const ULONG Back_colors[48] =
{
	0x90909090,0x90909090,0x90909090,
	0x00000000,0x00000000,0x00000000,
	0xffffffff,0xffffffff,0xffffffff,
	0xf0f0f0f0,0xf0f0f0f0,0x00000000,
	0x70707070,0x70707070,0x70707070,
	0xa0a0a0a0,0xa0a0a0a0,0xa0a0a0a0,
	0xf0f0f0f0,0x00000000,0xf0f0f0f0,
	0xf0f0f0f0,0x00000000,0x00000000,
	0x40404040,0x40404040,0xf0f0f0f0,
	0xc0c0c0c0,0xc0c0c0c0,0xf0f0f0f0,
	0x00000000,0xa0a0a0a0,0x00000000,
	0x70707070,0x70707070,0xf0f0f0f0,
	0xe0e0e0e0,0x40404040,0x40404040,
	0x60606060,0xe0e0e0e0,0x60606060,
	0x00000000,0x40404040,0xd0d0d0d0,
	0xc0c0c0c0,0xf0f0f0f0,0xc0c0c0c0,
};
#define BACK_WIDTH        24
#define BACK_HEIGHT       22
#define BACK_DEPTH         4
#define BACK_COMPRESSION   0
#define BACK_MASKING       2

const struct BitMapHeader Back_header =
{ 24,22,0,0,4,2,0,0,0,10,11,640,400 };
const UBYTE Back_body[352] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x02,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x3f,0xfd,0xe7,0x00,0x0e,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x7f,0xf5,0xe7,0x00,0x1e,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xf8,0xc2,0x00,0xff,0xf5,0xa7,0x00,0x3f,
0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xf8,0xc2,0x00,0xff,0xf5,0xa7,0x00,
0x3f,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xf8,0xc2,0x00,0x7c,0x05,0xa7,
0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xf8,0xc2,0x00,0x3d,0xfd,
0xe7,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1d,
0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,
0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,
0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,
0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00, };