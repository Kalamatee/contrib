/*
 *
 * decss.c
 *
 */

#if defined(__AROS__)
#include "aros-inc.h"
#endif

#include "decss.h"

unsigned char csstab1[256] = {
  0x33,0x73,0x3b,0x26,0x63,0x23,0x6b,0x76,0x3e,0x7e,0x36,0x2b,0x6e,0x2e,0x66,0x7b,
  0xd3,0x93,0xdb,0x06,0x43,0x03,0x4b,0x96,0xde,0x9e,0xd6,0x0b,0x4e,0x0e,0x46,0x9b,
  0x57,0x17,0x5f,0x82,0xc7,0x87,0xcf,0x12,0x5a,0x1a,0x52,0x8f,0xca,0x8a,0xc2,0x1f,
  0xd9,0x99,0xd1,0x00,0x49,0x09,0x41,0x90,0xd8,0x98,0xd0,0x01,0x48,0x08,0x40,0x91,
  0x3d,0x7d,0x35,0x24,0x6d,0x2d,0x65,0x74,0x3c,0x7c,0x34,0x25,0x6c,0x2c,0x64,0x75,
  0xdd,0x9d,0xd5,0x04,0x4d,0x0d,0x45,0x94,0xdc,0x9c,0xd4,0x05,0x4c,0x0c,0x44,0x95,
  0x59,0x19,0x51,0x80,0xc9,0x89,0xc1,0x10,0x58,0x18,0x50,0x81,0xc8,0x88,0xc0,0x11,
  0xd7,0x97,0xdf,0x02,0x47,0x07,0x4f,0x92,0xda,0x9a,0xd2,0x0f,0x4a,0x0a,0x42,0x9f,
  0x53,0x13,0x5b,0x86,0xc3,0x83,0xcb,0x16,0x5e,0x1e,0x56,0x8b,0xce,0x8e,0xc6,0x1b,
  0xb3,0xf3,0xbb,0xa6,0xe3,0xa3,0xeb,0xf6,0xbe,0xfe,0xb6,0xab,0xee,0xae,0xe6,0xfb,
  0x37,0x77,0x3f,0x22,0x67,0x27,0x6f,0x72,0x3a,0x7a,0x32,0x2f,0x6a,0x2a,0x62,0x7f,
  0xb9,0xf9,0xb1,0xa0,0xe9,0xa9,0xe1,0xf0,0xb8,0xf8,0xb0,0xa1,0xe8,0xa8,0xe0,0xf1,
  0x5d,0x1d,0x55,0x84,0xcd,0x8d,0xc5,0x14,0x5c,0x1c,0x54,0x85,0xcc,0x8c,0xc4,0x15,
  0xbd,0xfd,0xb5,0xa4,0xed,0xad,0xe5,0xf4,0xbc,0xfc,0xb4,0xa5,0xec,0xac,0xe4,0xf5,
  0x39,0x79,0x31,0x20,0x69,0x29,0x61,0x70,0x38,0x78,0x30,0x21,0x68,0x28,0x60,0x71,
  0xb7,0xf7,0xbf,0xa2,0xe7,0xa7,0xef,0xf2,0xba,0xfa,0xb2,0xaf,0xea,0xaa,0xe2,0xff
};

unsigned char reverse[256] = {
  0x00,0x80,0x40,0xc0,0x20,0xa0,0x60,0xe0,0x10,0x90,0x50,0xd0,0x30,0xb0,0x70,0xf0,
  0x08,0x88,0x48,0xc8,0x28,0xa8,0x68,0xe8,0x18,0x98,0x58,0xd8,0x38,0xb8,0x78,0xf8,
  0x04,0x84,0x44,0xc4,0x24,0xa4,0x64,0xe4,0x14,0x94,0x54,0xd4,0x34,0xb4,0x74,0xf4,
  0x0c,0x8c,0x4c,0xcc,0x2c,0xac,0x6c,0xec,0x1c,0x9c,0x5c,0xdc,0x3c,0xbc,0x7c,0xfc,
  0x02,0x82,0x42,0xc2,0x22,0xa2,0x62,0xe2,0x12,0x92,0x52,0xd2,0x32,0xb2,0x72,0xf2,
  0x0a,0x8a,0x4a,0xca,0x2a,0xaa,0x6a,0xea,0x1a,0x9a,0x5a,0xda,0x3a,0xba,0x7a,0xfa,
  0x06,0x86,0x46,0xc6,0x26,0xa6,0x66,0xe6,0x16,0x96,0x56,0xd6,0x36,0xb6,0x76,0xf6,
  0x0e,0x8e,0x4e,0xce,0x2e,0xae,0x6e,0xee,0x1e,0x9e,0x5e,0xde,0x3e,0xbe,0x7e,0xfe,
  0x01,0x81,0x41,0xc1,0x21,0xa1,0x61,0xe1,0x11,0x91,0x51,0xd1,0x31,0xb1,0x71,0xf1,
  0x09,0x89,0x49,0xc9,0x29,0xa9,0x69,0xe9,0x19,0x99,0x59,0xd9,0x39,0xb9,0x79,0xf9,
  0x05,0x85,0x45,0xc5,0x25,0xa5,0x65,0xe5,0x15,0x95,0x55,0xd5,0x35,0xb5,0x75,0xf5,
  0x0d,0x8d,0x4d,0xcd,0x2d,0xad,0x6d,0xed,0x1d,0x9d,0x5d,0xdd,0x3d,0xbd,0x7d,0xfd,
  0x03,0x83,0x43,0xc3,0x23,0xa3,0x63,0xe3,0x13,0x93,0x53,0xd3,0x33,0xb3,0x73,0xf3,
  0x0b,0x8b,0x4b,0xcb,0x2b,0xab,0x6b,0xeb,0x1b,0x9b,0x5b,0xdb,0x3b,0xbb,0x7b,0xfb,
  0x07,0x87,0x47,0xc7,0x27,0xa7,0x67,0xe7,0x17,0x97,0x57,0xd7,0x37,0xb7,0x77,0xf7,
  0x0f,0x8f,0x4f,0xcf,0x2f,0xaf,0x6f,0xef,0x1f,0x9f,0x5f,0xdf,0x3f,0xbf,0x7f,0xff
};

static inline void css_key_generate (unsigned char *key, unsigned char *in, unsigned char invert)
{
  unsigned char k[5];
  unsigned int lfsr0, lfsr1;
  unsigned char o_lfsr0, o_lfsr1;
  int i, val;

  lfsr0 = ((in[4] << 17) | (in[3] << 9) | (in[2] << 1)) + 8 - (in[2] & 7);
  lfsr0 = (reverse[lfsr0&0xff]<<17) | (reverse[(lfsr0>>8)&0xff] << 9) | (reverse[(lfsr0>>16)&0xff]<<1) |(lfsr0>>24);
  lfsr1 = (reverse[ in[0] ] << 9) | 0x100 | reverse[ in[1]];

  val = 0;
  for (i = 0; i < 5; ++i) {
    o_lfsr0 = (lfsr0 >> 12) ^ (lfsr0 >> 4) ^ (lfsr0 >> 3) ^ lfsr0;

    o_lfsr1 = ((lfsr1 >> 14) & 7) ^ lfsr1;
    o_lfsr1 ^= (o_lfsr1 << 3) ^ (o_lfsr1 << 6);

    lfsr1 = (lfsr1 >> 8) ^ (o_lfsr1 << 9);
    lfsr0 = (lfsr0 >> 8) ^ (o_lfsr0 << 17);

    val += (o_lfsr0 ^ invert) + o_lfsr1;

    k[i] = val & 0xff;
    val >>= 8;
  }

  key[4]=k[4]^csstab1[key[4]]^key[3];
  key[3]=k[3]^csstab1[key[3]]^key[2];
  key[2]=k[2]^csstab1[key[2]]^key[1];
  key[1]=k[1]^csstab1[key[1]]^key[0];
  key[0]=k[0]^csstab1[key[0]]^key[4];

  key[4]=k[4]^csstab1[key[4]]^key[3];
  key[3]=k[3]^csstab1[key[3]]^key[2];
  key[2]=k[2]^csstab1[key[2]]^key[1];
  key[1]=k[1]^csstab1[key[1]]^key[0];
  key[0]=k[0]^csstab1[key[0]];
}

/* Table from libcss 0.1.0 */
typedef struct {
  int offset;
  unsigned char key[5];
} playerkey_t;

static playerkey_t playerkeys[] = {
  {0x000, {0x00,0x00,0x00,0x00,0x00}},
  {0x005, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x00a, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x014, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x019, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x01e, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x023, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x028, {0x53,0xd4,0xf7,0xd9,0x8f}},
  {0x028, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x02d, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x032, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x037, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x03c, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x041, {0x12,0x11,0xca,0x04,0x3b}},
  {0x046, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x04b, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x050, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x055, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x05a, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x05f, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x064, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x069, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x06e, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x073, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x078, {0x14,0x71,0x35,0xba,0xe2}},
  {0x07d, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x082, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x087, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x08c, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x091, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x096, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x09b, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x0a0, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x0a5, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x0aa, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x0af, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x0b9, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x0be, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x0c3, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x0c8, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x0cd, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x0d2, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x0d7, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x0e1, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x0e6, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x0eb, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x0f0, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x0f5, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x0fa, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x0ff, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x104, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x109, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x10e, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x113, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x118, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x11d, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x122, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x12c, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x131, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x136, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x13b, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x140, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x145, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x14a, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x14f, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x154, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x159, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x15e, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x163, {0x14,0x71,0x35,0xba,0xe2}},
  {0x168, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x16d, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x172, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x177, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x17c, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x181, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x186, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x18b, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x190, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x195, {0x14,0x71,0x35,0xba,0xe2}},
  {0x19a, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x19f, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x1a4, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x1a9, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x1ae, {0x12,0x11,0xca,0x04,0x3b}},
  {0x1b3, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x1b8, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x1bd, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x1c2, {0x14,0x71,0x35,0xba,0xe2}},
  {0x1c7, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x1cc, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x1d1, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x1d6, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x1db, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x1e0, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x1e5, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x1ea, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x1ef, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x1f4, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x1f9, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x1fe, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x203, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x208, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x20d, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x212, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x217, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x21c, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x221, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x226, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x22b, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x235, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x235, {0x90,0xc1,0xd7,0x84,0x48}},
  {0x23a, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x23f, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x244, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x249, {0xb7,0x3f,0xd4,0xaa,0x14}},
  {0x24e, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x253, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x258, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x25d, {0x12,0x11,0xca,0x04,0x3b}},
  {0x262, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x267, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x26c, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x271, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x276, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x27b, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x280, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x285, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x28a, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x28f, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x294, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x299, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x29e, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x2a3, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x2a8, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x2ad, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x2b2, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x2b7, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x2bc, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x2c1, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x2c6, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x2cb, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x2d0, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x2d5, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x2da, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x2df, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x2e4, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x2e9, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x2ee, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x2f3, {0x90,0xc1,0xd7,0x84,0x48}},
  {0x2f3, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x2f8, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x2fd, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x302, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x307, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x30c, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x311, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x316, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x31b, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x320, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x325, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x32a, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x32f, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x334, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x339, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x33e, {0x14,0x71,0x35,0xba,0xe2}},
  {0x343, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x348, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x34d, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x352, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x357, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x35c, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x361, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x366, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x36b, {0x90,0xc1,0xd7,0x84,0x48}},
  {0x36b, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x370, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x375, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x37a, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x37f, {0x14,0x71,0x35,0xba,0xe2}},
  {0x384, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x389, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x38e, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x393, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x398, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x39d, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x3a2, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x3a7, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x3ac, {0x14,0x71,0x35,0xba,0xe2}},
  {0x3b1, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x3b6, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x3bb, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x3c0, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x3c5, {0x12,0x11,0xca,0x04,0x3b}},
  {0x3ca, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x3cf, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x3d4, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x3d9, {0x12,0x11,0xca,0x04,0x3b}},
  {0x3de, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x3e3, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x3e8, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x3ed, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x3f2, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x3f7, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x3fc, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x401, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x406, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x40b, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x410, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x415, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x41a, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x41f, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x424, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x429, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x42e, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x433, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x438, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x43d, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x442, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x447, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x44c, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x451, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x456, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x45b, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x465, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x46a, {0x12,0x11,0xca,0x04,0x3b}},
  {0x46f, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x474, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x479, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x47e, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x483, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x488, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x48d, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x492, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x497, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x49c, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x4a1, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x4a6, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x4ab, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x4b0, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x4b5, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x4ba, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x4bf, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x4c4, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x4c9, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x4ce, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x4d3, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x4d8, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x4dd, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x4e2, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x4e7, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x4ec, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x4f1, {0x14,0x71,0x35,0xba,0xe2}},
  {0x4f6, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x4fb, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x500, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x505, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x50a, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x50f, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x514, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x519, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x51e, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x523, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x528, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x52d, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x532, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x537, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x53c, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x541, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x546, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x54b, {0x33,0x2f,0x49,0x6c,0xe0}},
  {0x550, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x555, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x55a, {0x14,0x71,0x35,0xba,0xe2}},
  {0x55f, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x564, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x569, {0x12,0x11,0xca,0x04,0x3b}},
  {0x56e, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x573, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x578, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x57d, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x582, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x587, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x58c, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x591, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x596, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x59b, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x5a0, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x5a5, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x5aa, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x5af, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x5b4, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x5b9, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x5be, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x5c3, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x5c8, {0x14,0x71,0x35,0xba,0xe2}},
  {0x5cd, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x5d2, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x5d7, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x5dc, {0x14,0x71,0x35,0xba,0xe2}},
  {0x5e1, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x5e6, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x5f0, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x5f5, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x5fa, {0x1a,0xa4,0x33,0x21,0xa6}},
  {0x5ff, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x604, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x609, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x60e, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x613, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x618, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x61d, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x622, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x627, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x62c, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x631, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x636, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x63b, {0x01,0xaf,0xe3,0x12,0x80}},
  {0x645, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x64a, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x64f, {0x39,0x3d,0xf1,0xf1,0xbd}},
  {0x654, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x659, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x65e, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x663, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x668, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x66d, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x672, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x67c, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x681, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x686, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x68b, {0x45,0xed,0x28,0xeb,0xd3}},
  {0x690, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x695, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x69a, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x6a4, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x6a9, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x6ae, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x6b3, {0x14,0x71,0x35,0xba,0xe2}},
  {0x6b8, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x6bd, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x6c2, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x6c7, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x6d1, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x6d6, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x6db, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x6e0, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x6e5, {0x12,0x11,0xca,0x04,0x3b}},
  {0x6ea, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x6ef, {0x48,0xb7,0x6c,0xce,0x69}},
  {0x6f4, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x6f9, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x6fe, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x703, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x708, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x70d, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x712, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x717, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x71c, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x721, {0x12,0x11,0xca,0x04,0x3b}},
  {0x726, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x72b, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x730, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x735, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x73a, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x73f, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x744, {0x12,0x11,0xca,0x04,0x3b}},
  {0x749, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x74e, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x753, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x758, {0x63,0xdb,0x4c,0x5b,0x4a}},
  {0x75d, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x762, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x767, {0x12,0x11,0xca,0x04,0x3b}},
  {0x76c, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x771, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x776, {0x12,0x11,0xca,0x04,0x3b}},
  {0x77b, {0x2c,0xb2,0xc1,0x09,0xee}},
  {0x780, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {0x785, {0x57,0x2c,0x8b,0x31,0xae}},
  {0x78a, {0x4b,0x65,0x0d,0xc1,0xee}},
  {0x78f, {0xbf,0x92,0xc3,0xb0,0xe2}},
  {0x794, {0x12,0x11,0xca,0x04,0x3b}},
  {0x799, {0xb1,0xb8,0xf9,0x38,0x03}},
  {0x79e, {0x14,0x0c,0x9e,0xd0,0x09}},
  {0x7a3, {0xb8,0x5d,0xd8,0x53,0xbd}},
  {0x7a8, {0xfc,0x95,0xa9,0x87,0x35}},
  {0x7ad, {0xec,0xa0,0xcf,0xb3,0xff}},
  {0x7b2, {0x3b,0x31,0x34,0x0d,0x91}},
  {0x7b7, {0xab,0x36,0xe3,0xeb,0x76}},
  {0x7c1, {0xcf,0x1a,0xb2,0xf8,0x0a}},
  {0x7c6, {0x85,0xf3,0x85,0xa0,0xe0}},
  {0x7cb, {0x14,0x71,0x35,0xba,0xe2}},
  {0x7d0, {0xab,0x1e,0xe7,0x7b,0x72}},
  {0x7d5, {0x4c,0xbb,0xf5,0x5b,0x23}},
  {0x7da, {0x26,0xec,0xc4,0xa7,0x4e}},
  {0x7df, {0x53,0x94,0xe1,0x75,0xbf}},
  {0x7e4, {0x36,0x67,0xb2,0xe3,0x85}},
  {0x7e9, {0x35,0x5b,0xc1,0x31,0x0f}},
  {0x7ee, {0x2f,0x25,0x9e,0x96,0xdd}},
  {0x7f3, {0x51,0x67,0x67,0xc5,0xe0}},
  {0x7f8, {0x7b,0x1e,0x5e,0x2b,0x57}},
  {   -1, {0x00,0x00,0x00,0x00,0x00}}
};

int css_decrypt_title_key(unsigned char *title_key, unsigned char *disk_key)
{
  static unsigned char tmp1[5], tmp3[5];
  int i;

  for (i=0; playerkeys[i].offset != -1; ++i) {
    memcpy(tmp1, disk_key + playerkeys[i].offset, 5);
    css_key_generate(tmp1, playerkeys[i].key, 0);

    memcpy(tmp3, disk_key, 5);
    css_key_generate(tmp3, tmp1, 0);

    if (memcmp(tmp3, tmp1, 5) == 0) {
      memcpy(tmp3, title_key, 5);
      css_key_generate(tmp3, tmp1, 0xff);
      memcpy(title_key, tmp3, 5);
      return 0;
    }
  }

  return -1;
}

void css_descramble_sector(unsigned char *sector, unsigned char *key)
{
  unsigned char *buf_end = sector + 0x800;
  unsigned int lfsr0, lfsr1;
  unsigned char o_lfsr0, o_lfsr1;
  unsigned char off;
  int val;

  off = (sector[13] & 0x07) + 20;

  /* Return if sector isn't scrambled */
  if ((sector[off] & 0x30) != 0x10) {
    return;
  }

  /* Remove scramble bits */
  sector[off] &= 0xcf;

  #define SALTED(i) (key[i] ^ sector[0x54 + (i)])

  lfsr0 = ((SALTED(4) << 17) | (SALTED(3) << 9) | (SALTED(2) << 1)) + 8 - (SALTED(2)&7);
  lfsr0 = (reverse[lfsr0&0xff]<<17) | (reverse[(lfsr0>>8)&0xff] << 9) | (reverse[(lfsr0>>16)&0xff]<<1) |(lfsr0>>24);
  lfsr1 = (reverse[SALTED(0)] << 9) | 0x100 | (reverse[SALTED(1)]);

  sector+=0x80;
  val = 0;
  while (sector != buf_end) {
    o_lfsr0 = (lfsr0 >> 12) ^ (lfsr0 >> 4) ^  (lfsr0 >> 3) ^ lfsr0;

    o_lfsr1 = ((lfsr1 >> 14) & 7) ^ lfsr1;
    o_lfsr1 ^= (o_lfsr1 << 3) ^ (o_lfsr1 << 6);

    lfsr1 = (lfsr1 >> 8) ^ (o_lfsr1 << 9);
    lfsr0 = (lfsr0 >> 8) ^ (o_lfsr0 << 17);

    val += o_lfsr0 + (unsigned char)~o_lfsr1;
    *sector++ = csstab1[*sector] ^ (val & 0xff);
    val >>= 8;
  }
}
