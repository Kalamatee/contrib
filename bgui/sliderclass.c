/*
 * @(#) $Header$
 *
 * BGUI library
 * sliderclass.c
 *
 * (C) Copyright 1998 Manuel Lemos.
 * (C) Copyright 1996-1997 Ian J. Einman.
 * (C) Copyright 1993-1996 Jaba Development.
 * (C) Copyright 1993-1996 Jan van den Baard.
 * All Rights Reserved.
 *
 * $Log$
 * Revision 1.1  1998/02/25 17:09:46  mlemos
 * Ian sources
 *
 *
 */

#include "include/classdefs.h"

/// OM_NEW
/*
 * Create a shiny new object.
 */
METHOD(SliderClassNew, struct opSet *ops)
{
   struct TagItem   *tags;
   ULONG             rc;

   tags = DefTagList(BGUI_SLIDER_GADGET, ops->ops_AttrList);

   /*
    * First we let the superclass get us an object.
    */
   if (rc = NewSuperObject(cl, obj, tags))
   {
      AsmDoSuperMethod(cl, (Object *)rc, OM_SET, tags, NULL);
   };
   FreeTagItems(tags);

   return rc;
}
///
///Class initialization.
/*
 * Class function table.
 */
STATIC DPFUNC ClassFunc[] =
{
   OM_NEW,           (FUNCPTR)SliderClassNew,
   DF_END,           NULL
};

/*
 * Class initialization.
 */
makeproto Class *InitSliderClass(void)
{
   return BGUI_MakeClass(CLASS_SuperClassBGUI, BGUI_PROP_GADGET,
                         CLASS_DFTable,        ClassFunc,
                         TAG_DONE);
}
///
