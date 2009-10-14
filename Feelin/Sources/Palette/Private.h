/****************************************************************************
*** Includes ****************************************************************
****************************************************************************/

#include <proto/graphics.h>
#include <proto/feelin.h>

#include <libraries/feelin.h>

#define       GfxBase               FeelinBase -> Graphics

/****************************************************************************
*** Attributes, Methods, Values, Flags **************************************
****************************************************************************/

enum    {

        FA_Palette_Colors,
        FA_Palette_NumColors,
        FA_Palette_MaxColors,
        FA_Palette_Histogram,
        FA_Palette_Resolution

        };

enum    {

        FM_Palette_Best,
        FM_Palette_ObtainPens

        };

#define FF_PALETTE_EXTRACTED                    (1 << 0)

/****************************************************************************
*** Structures **************************************************************
****************************************************************************/

struct LocalObjectData
{
    uint32                          numcolors;
    uint32                         *colors;
    uint16                         *lut;
    uint32                          lutmask;
    uint16                          bitspergun;
    bits16                          flags;
};

/****************************************************************************
*** Preferences *************************************************************
****************************************************************************/

