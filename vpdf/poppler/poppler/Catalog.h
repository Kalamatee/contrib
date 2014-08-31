//========================================================================
//
// Catalog.h
//
// Copyright 1996-2007 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the Poppler project - http://poppler.freedesktop.org
//
// All changes made under the Poppler project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2005 Kristian Høgsberg <krh@redhat.com>
// Copyright (C) 2005, 2007, 2009-2011, 2013 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2005 Jonathan Blandford <jrb@redhat.com>
// Copyright (C) 2005, 2006, 2008 Brad Hards <bradh@frogmouth.net>
// Copyright (C) 2007 Julien Rebetez <julienr@svn.gnome.org>
// Copyright (C) 2008, 2011 Pino Toscano <pino@kde.org>
// Copyright (C) 2010 Hib Eris <hib@hiberis.nl>
// Copyright (C) 2012 Fabio D'Urso <fabiodurso@hotmail.it>
// Copyright (C) 2013 Thomas Freitag <Thomas.Freitag@alfa.de>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef CATALOG_H
#define CATALOG_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "poppler-config.h"
#include "Object.h"
#include "goo/GooMutex.h"

#include <vector>

class PDFDoc;
class XRef;
class PObject;
class Page;
class PageAttrs;
struct Ref;
class LinkDest;
class PageLabelInfo;
class Form;
class OCGs;
class ViewerPreferences;
class FileSpec;

//------------------------------------------------------------------------
// NameTree
//------------------------------------------------------------------------

class NameTree {
public:
  NameTree();
  ~NameTree();
  void init(XRef *xref, PObject *tree);
  GBool lookup(GooString *name, PObject *obj);
  int numEntries() { return length; };
  // iterator accessor, note it returns a shallow copy, do not free the object
  PObject getValue(int i);
  GooString *getName(int i);

private:
  struct Entry {
    Entry(Array *array, int index);
    ~Entry();
    GooString name;
    PObject value;
    void free();
    static int cmp(const void *key, const void *entry);
  };

  void parse(PObject *tree);
  void addEntry(Entry *entry);

  XRef *xref;
  PObject *root;
  Entry **entries;
  int size, length; // size is the number of entries in
                    // the array of Entry*
                    // length is the number of real Entry
};

//------------------------------------------------------------------------
// Catalog
//------------------------------------------------------------------------

class Catalog {
public:

  // Constructor.
  Catalog(PDFDoc *docA);

  // Destructor.
  ~Catalog();

  // Is catalog valid?
  GBool isOk() { return ok; }

  // Get number of pages.
  int getNumPages();

  // Get a page.
  Page *getPage(int i);

  // Get the reference for a page object.
  Ref *getPageRef(int i);

  // Return base URI, or NULL if none.
  GooString *getBaseURI() { return baseURI; }

  // Return the contents of the metadata stream, or NULL if there is
  // no metadata.
  GooString *readMetadata();

  // Return the structure tree root object.
  PObject *getStructTreeRoot();

  // Find a page, given its object ID.  Returns page number, or 0 if
  // not found.
  int findPage(int num, int gen);

  // Find a named destination.  Returns the link destination, or
  // NULL if <name> is not a destination.
  LinkDest *findDest(GooString *name);

  PObject *getDests();

  // Get the number of embedded files
  int numEmbeddedFiles() { return getEmbeddedFileNameTree()->numEntries(); }

  // Get the i'th file embedded (at the Document level) in the document
  FileSpec *embeddedFile(int i);

  // Get the number of javascript scripts
  int numJS() { return getJSNameTree()->numEntries(); }

  // Get the i'th JavaScript script (at the Document level) in the document
  GooString *getJS(int i);

  // Convert between page indices and page labels.
  GBool labelToIndex(GooString *label, int *index);
  GBool indexToLabel(int index, GooString *label);

  PObject *getOutline();

  PObject *getAcroForm() { return &acroForm; }

  OCGs *getOptContentConfig() { return optContent; }

  enum FormType
  {
    NoForm,
    AcroForm,
    XfaForm
  };

  FormType getFormType();
  Form* getForm();

  ViewerPreferences *getViewerPreferences();

  enum PageMode {
    pageModeNone,
    pageModeOutlines,
    pageModeThumbs,
    pageModeFullScreen,
    pageModeOC,
    pageModeAttach,
    pageModeNull
  };
  enum PageLayout {
    pageLayoutNone,
    pageLayoutSinglePage,
    pageLayoutOneColumn,
    pageLayoutTwoColumnLeft,
    pageLayoutTwoColumnRight,
    pageLayoutTwoPageLeft,
    pageLayoutTwoPageRight,
    pageLayoutNull
  };

  // Returns the page mode.
  PageMode getPageMode();
  PageLayout getPageLayout();

private:

  // Get page label info.
  PageLabelInfo *getPageLabelInfo();

  PDFDoc *doc;
  XRef *xref;			// the xref table for this PDF file
  Page **pages;			// array of pages
  Ref *pageRefs;		// object ID for each page
  int lastCachedPage;
  std::vector<Dict *> *pagesList;
  std::vector<Ref> *pagesRefList;
  std::vector<PageAttrs *> *attrsList;
  std::vector<int> *kidsIdxList;
  Form *form;
  ViewerPreferences *viewerPrefs;
  int numPages;			// number of pages
  int pagesSize;		// size of pages array
  PObject dests;			// named destination dictionary
  PObject names;			// named names dictionary
  NameTree *destNameTree;	// named destination name-tree
  NameTree *embeddedFileNameTree;  // embedded file name-tree
  NameTree *jsNameTree;		// Java Script name-tree
  GooString *baseURI;		// base URI for URI-type links
  PObject metadata;		// metadata stream
  PObject structTreeRoot;	// structure tree root dictionary
  PObject outline;		// outline dictionary
  PObject acroForm;		// AcroForm dictionary
  PObject viewerPreferences;     // ViewerPreference dictionary
  OCGs *optContent;		// Optional Content groups
  GBool ok;			// true if catalog is valid
  PageLabelInfo *pageLabelInfo; // info about page labels
  PageMode pageMode;		// page mode
  PageLayout pageLayout;	// page layout

  GBool cachePageTree(int page); // Cache first <page> pages.
  PObject *findDestInTree(PObject *tree, GooString *name, PObject *obj);

  PObject *getNames();
  NameTree *getDestNameTree();
  NameTree *getEmbeddedFileNameTree();
  NameTree *getJSNameTree();
#if MULTITHREADED
  GooMutex mutex;
#endif

};

#endif
