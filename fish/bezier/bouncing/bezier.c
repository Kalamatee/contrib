
/*
 *  BEZIER.C
 *
 *  Matthew Dillon.
 *  Public Domain (no Copyrights whatsoever)
 *
 *  -Assumes AZTEC compilation,  +L (32 bit ints), with all AMIGA symbols
 *  precompiled.  Additionally expects certain typedefs and routines
 *  found in MY.LIB, as well as some MY.LIB #include files.
 *
 *  An experienced programmer can remove the MY.LIB dependancies
 *  (openlibs() call), and figure out what typedefs have been assumed if
 *  he wishes to compile the program.  You can also simply extract the
 *  Bezier functions for your own use.
 *
 *  BEZIER EQUATIONS:
 *
 *	c(t) = T(t)BP
 *
 *	T(t) = (t^3 t^2 t 1)		P= ( P1 )
 *	B = (  -1   3  -3   1	)	   ( P2 )
 *	    (	3  -6	3   0	)	   ( P3 )
 *	    (  -3   3	0   0	)	   ( P4 )
 *	    (	1   0	0   0	)
 *
 *	t:  range 0 to 1
 *	C:  coordinate matrix  1xD matrix (D = dimensions)
 *	B:  Bezier matrix      4x4
 *	P:  Ctrl. Point matrix 4xD matrix (D = dimensions)
 *
 *	using D = 2
 */

/* !!!
 #include <typedefs.h>
*/ 
#include <aros/oldprograms.h>
#include <intuition/intuition.h>
#include <intuition/imageclass.h>
#include <graphics/gfx.h>
#include <graphics/gfxbase.h>

typedef struct Window WIN;
typedef struct NewWindow NW;
typedef struct IntuiMessage IMESS;
typedef struct RastPort RP;
typedef struct Gadget GADGET;
struct GfxBase * GfxBase;
struct IntuitionBase * IntuitionBase;
/* !!!
 #include <xmisc.h>
*/

 
#define     SHIFTS  9
#define     ONE     (1<<SHIFTS)

typedef struct PropInfo XPI;
typedef struct Image	IM;

#define MYGADGETS   (WINDOWSIZING|WINDOWDRAG|WINDOWDEPTH|WINDOWCLOSE)

NW Nw = {
    64, 64, 320, 100,
    0, 1,
    NEWSIZE|MOUSEBUTTONS|MOUSEMOVE|CLOSEWINDOW|GADGETDOWN|GADGETUP,
    MYGADGETS|REPORTMOUSE|ACTIVATE|NOCAREREFRESH,
    0, 0, (UBYTE *)"Bezier, By Matthew Dillon", NULL, NULL,
    32, 64, -1, -1, WBENCHSCREEN
};

#define INTUITION_LIB 1
#define GRAPHICS_LIB 2

int openlibs(int dummy)
{
  GfxBase = (struct GfxBase *)OpenLibrary("graphics.library",0);
  IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",0);
}

void closelibs(int dummy)
{
  if (GfxBase)
    CloseLibrary((struct Library *)GfxBase);
  if (IntuitionBase)
    CloseLibrary((struct Library *)IntuitionBase);
}

WIN *Win;
RP  *Rp;
short Ux, Uy, Lx, Ly;
short Step = 128;

main(ac, av)
char *av[];
{
    register IMESS *mess;
    short notdone = 1;
    short pt = -1;
    short ptarray[4][2];
    short auarray[4][2];    /* auto move */
    short au = 0;
    long  delay = 0;

    short gy, gg = 0;
    XPI *po;

    if (ac >= 2) {
	if (ac >= 3)
	    delay = atoi(av[2]);
	au = 1;
	loadauto(auarray, atoi(av[1]));
    }

    exiterr(!openlibs(INTUITION_LIB|GRAPHICS_LIB), "unable to open libs");
    init_gadgets(&Nw, &po);
    exiterr(!(Win = (struct Window *)OpenWindow(&Nw)), "unable to open window");
    Rp = Win->RPort;
    SetAPen(Rp, 1);
    setpoint(ptarray, 0, 32, 32);
    setpoint(ptarray, 1, 40, 40);
    setpoint(ptarray, 2, 50, 50);
    setpoint(ptarray, 3, 60, 60);
    setbounds(ptarray);
    while (notdone) {
	short mx, my, mm = 0;
	if (au == 0) {
	    WaitPort(Win->UserPort);
	} else {
	    if (delay)
		Delay(delay);
	    moveauto(auarray, ptarray);
	}
	while (mess = GetMsg(Win->UserPort)) {
	    switch(mess->Class) {
	    case CLOSEWINDOW:
		notdone = 0;
		break;
	    case NEWSIZE:
		setbounds(ptarray);
		break;
	    case GADGETUP:
	    case GADGETDOWN:
		{
		    gg = mess->Class;
		    gy = po->VertPot / 256;
		}
		break;
	    case MOUSEBUTTONS:
		switch(mess->Code) {
		case SELECTDOWN:
		    pt = getpoint(ptarray, mess->MouseX, mess->MouseY);
		    movepoint(ptarray, pt, mess->MouseX, mess->MouseY);
		    drawcurve(ptarray);
		    break;
		case SELECTUP:
		    pt = -1;
		    break;
		}
		break;
	    case MOUSEMOVE:
		if (gg == GADGETDOWN) {
		    gy = po->VertPot / 256;
		    break;
		}
		mm = 1;
		mx = mess->MouseX;
		my = mess->MouseY;
		break;
	    default:
		break;
	    }
	    ReplyMsg(mess);
	}
	if (mm && pt >= 0) {
	    movepoint(ptarray, pt, mx, my);
	    drawcurve(ptarray);
	}
	if (gg) {
	    char buf[32];
	    if (gg == GADGETUP)
		gg = 0;
	    if (gy + 1 >= 0 && gy + 1 != Step) {
		Step = gy + 1;
		sprintf(buf, "gran: %4ld/%ld", Step, ONE);
		drawcurve(ptarray);
		SetDrMd(Rp, JAM1);
		Move(Rp, Ux + 1, Uy + 16);
		Text(Rp, buf, strlen(buf));
	    }
	}
    }
    exiterr(1, NULL);
}

exiterr(n, str)
char *str;
{
    if (n) {
	if (str)
	    puts(str);
	if (Win)
	    CloseWindow(Win);
	closelibs(-1);
	exit(1);
    }
}

setbounds(a)
register long *a;
{
    Ux = Win->BorderLeft;
    Uy = Win->BorderTop;
    Lx = Win->Width - Win->BorderRight;
    Ly = Win->Height- Win->BorderBottom;
    drawcurve(a);
}

setpoint(a, pt, x, y)
register short a[4][2];
{
    a[pt][0] = x;
    a[pt][1] = y;
    drawpoints(a, pt, pt + 1);
}

getpoint(a, x, y)
register short a[4][2];
{
    register short i, bi;
    register long r, br;

    for (i = bi = 0, br = 0x7FFFFFFF; i < 4; ++i) {
	r = (x-a[i][0])*(x-a[i][0]) + (y-a[i][1])*(y-a[i][1]);
	if (r < br) {
	    bi = i;
	    br = r;
	}
    }
    return(bi);
}

movepoint(a, pt, x, y)
register short a[4][2];
{
    SetAPen(Rp, 0);
    drawpoints(a, pt, pt + 1);
    SetAPen(Rp, 1);
    setpoint(a, pt, x, y);
}

#define S10(x)	 ((x) >> SHIFTS)
#define S20(x)	 ((x) >> (2*SHIFTS))
#define MUL3(x)  ((x)+((x)<<1))

/*
 *  So I can use integer arithmatic, I am defining 512 as 1 (as far
 *  as the mathematics go), which means that I must divide any power
 *  multiplication by 512^(n-1).  E.G. .5^2 = .25 ... to make 256^2
 *  equal 128, I must divide by 512^1
 */

drawcurve(a)
register short a[4][2];
{
    long  mr[4];		/* Holds T(t)B partial result	*/
    char  lastpt;
    short array[ONE][2];	/* hold points to plot		*/
    register long  ttt3, t3, tt3;
    register short t, i, n;
    register long tt, ttt;

    lastpt = 0;
    for (t = n = 0; t <= ONE; t += Step) {     /*  t = 0 to 1	   */
oncemore:
	tt = t * t;
	ttt= tt * t;
	ttt3 = S20(MUL3(ttt));
	tt3  = S10(MUL3(tt));
	t3   = MUL3(t);
	ttt  = S20(ttt);

	mr[0] = -ttt + tt3 - t3 + ONE;
	mr[1] = ttt3 - (tt3<<1) + t3;
	mr[2] = -ttt3 + tt3;
	/* MR[3] is ttt     */

	for (i = 0; i < 2; ++i) {
	    array[n][i] = (mr[0] * a[0][i] + mr[1] * a[1][i] +
		      mr[2] * a[2][i] + ttt * a[3][i]) >> SHIFTS;
	}
	++n;
    }
    if (lastpt == 0 && t - Step < ONE) {
	lastpt = 1;
	t = ONE;
	goto oncemore;
    }

    SetAPen(Rp, 0);
    RectFill(Rp, Ux, Uy, Lx - 1, Ly - 1);
    SetAPen(Rp, 1);
    Move(Rp, a[0][0], a[0][1]);
    PolyDraw(Rp, n, array);
    drawpoints(a, 0, 4);
}


drawpoints(a, is, ie)
register short a[4][2];
{
    register short i;
    for (i = is; i < ie; ++i) {
	Move(Rp, a[i][0] - 2, a[i][1]);
	Draw(Rp, a[i][0] + 2, a[i][1]);
	Move(Rp, a[i][0], a[i][1] - 2);
	Draw(Rp, a[i][0], a[i][1] + 2);
    }
}

/*
 *  AUTO ROUTINES   ------------------------------------------------------
 */

loadauto(a, seed)
register short a[4][2];
{
    register short i, j;
    register long n;
    n = random(seed);
    for (i = 0; i < 4; ++i) {
	for (j = 0; j < 2; ++j) {
	    n = random(n);
	    if ((a[i][j] = (((n>>1) & 15) - 7)) == 0)
		a[i][j] = 1;
	}
    }
}

moveauto(au, ar)
register short au[4][2];
register short ar[4][2];
{
    register short i, j;
    short lb[2], mb[2];

    lb[0] = Ux; lb[1] = Uy;
    mb[0] = Lx; mb[1] = Ly;

    for (i = 0; i < 4; ++i) {
	for (j = 0; j < 2; ++j) {
	    if (au[i][j] < 0 && ar[i][j] <= lb[j]+8)
		au[i][j] = -au[i][j];
	    if (au[i][j] > 0 && ar[i][j] >= mb[j]-8)
		au[i][j] = -au[i][j];
	    ar[i][j] += au[i][j];
	}
    }
    drawcurve(ar);
}

random(n)
{
    return((n ^ (n >> 8)) * 13 + 1);
}


/*
 *  GADGET ROUTINES!	------------------------------------------------
 */


#define NG(nn)	&Gadgets[nn+1]
#define G_YGLOB 1
#define G_XGLOB 2

XPI Props[] = {
    { AUTOKNOB|FREEVERT|PROPNEWLOOK|PROPBORDERLESS , 0, 0, 0x1FFF, 0x1FFF }
};

IM Images[] = {
    { 0,0,2,1,1, NULL, 1, 0, NULL },
};

GADGET Gadgets[] = {
    {
	NULL, -15, 11, 15, -19, GADGIMAGE|GADGHCOMP|GRELRIGHT|GRELHEIGHT,
	GADGIMMEDIATE|RIGHTBORDER|RELVERIFY,PROPGADGET,
	(APTR)&Images[0],NULL,NULL,0,(APTR)&Props[0], G_YGLOB, 0
    },
};

GADGET *Gc;
long GUx, GUy;

init_gadgets(nw, ppo)
NW *nw;
XPI **ppo;
{
    struct Screen *scr;
    struct DrawInfo *dri;    
    Object *sizeim;
    WORD sizewidth  = 14;
    WORD sizeheight = 14;
    
    scr = LockPubScreen(NULL);
    if (scr)
    {
    	dri = GetScreenDrawInfo(scr);
	if (dri)
	{
	    sizeim = NewObject(NULL, SYSICLASS, SYSIA_DrawInfo, (IPTR)dri,
	    	    	    	    	        SYSIA_Which, SIZEIMAGE,
						TAG_DONE);
	
	    if (sizeim)
	    {
	    	sizewidth = ((struct Image *)sizeim)->Width;
	    	sizeheight = ((struct Image *)sizeim)->Height;
	    	DisposeObject(sizeim);
	    }
	    
	    Gadgets[0].LeftEdge = -sizewidth + 1 + 3;			
            Gadgets[0].TopEdge = scr->WBorTop + scr->Font->ta_YSize + 1 + 2;
	    Gadgets[0].Width  = sizewidth - 6;
	    Gadgets[0].Height = -Gadgets[0].TopEdge - sizeheight - 2;
	    	    
	    FreeScreenDrawInfo(scr, dri);
    	}
	UnlockPubScreen(NULL, scr);
    }
    
    nw->FirstGadget = &Gadgets[0];
    *ppo = &Props[0];
}


