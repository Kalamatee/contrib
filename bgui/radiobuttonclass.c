/*
 * @(#) $Header$
 *
 * BGUI library
 * radiobuttonclass.c
 *
 * (C) Copyright 1998 Manuel Lemos.
 * (C) Copyright 1996-1997 Ian J. Einman.
 * (C) Copyright 1993-1996 Jaba Development.
 * (C) Copyright 1993-1996 Jan van den Baard.
 * All Rights Reserved.
 *
 * $Log$
 * Revision 1.1  1998/02/25 17:09:33  mlemos
 * Ian sources
 *
 *
 */

#include "include/classdefs.h"

/// OM_NEW
/*
 * Create a shiny new object.
 */
METHOD(RBClassNew, struct opSet *ops)
{
   ULONG           rc;
   Object         *rb;
   struct TagItem  ttags[2], *tags;

   /*
    * Get us a radiobutton image.
    */
   if (rb = BGUI_NewObject(BGUI_VECTOR_IMAGE, VIT_BuiltIn, BUILTIN_RADIOBUTTON, VIT_DriPen, FILLPEN, TAG_DONE))
   {
      ttags[0].ti_Tag  = BUTTON_SelectedVector;
      ttags[0].ti_Data = (ULONG)rb;
      ttags[1].ti_Tag  = TAG_MORE;
      ttags[1].ti_Data = (ULONG)ops->ops_AttrList;

      tags = DefTagList(BGUI_RADIOBUTTON_GADGET, ttags);

      /*
       * Let the superclass setup an object for us.
       */
      if (rc = NewSuperObject(cl, obj, tags))
      {
         /*
          * No recessed rendering.
          */
         DoSetMethodNG((Object *)rc, FRM_EdgesOnly, FALSE, GA_ToggleSelect, TRUE, TAG_DONE);
      }
      else
      {
         AsmDoMethod(rb, OM_DISPOSE);
      };
      FreeTagItems(tags);
   }
   return rc;
}
///
/// Class Initialization.
/*
 * Class function table.
 */
STATIC DPFUNC ClassFunc[] = {
   OM_NEW,           (FUNCPTR)RBClassNew,
   DF_END
};

/*
 * Initialize the radiobutton class.
 */
makeproto Class *InitRadioButtonClass(void)
{
   return BGUI_MakeClass(CLASS_SuperClassBGUI, BGUI_BUTTON_GADGET,
                         CLASS_DFTable,        ClassFunc,
                         TAG_DONE);
}
///
