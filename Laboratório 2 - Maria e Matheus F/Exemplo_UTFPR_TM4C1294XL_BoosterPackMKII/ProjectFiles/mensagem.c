/*
M1
50 01 c0 fc 94 01 00 ff 1c 01 88 fc 90 01 d0 fc 84 01 60 fc a0 01
d8 fc c8 01 00 ff 80 00 00 ff 80 00 00 ff 80 00 00 ff 80 00 00 ff
80 00 00 ff 80 00 00 ff c4 00 38 fe dc 00 70 fe f9 ed 08 00 4d ca
08 00*/

/*
M2
a6 00 5c fb d0 00 14 fb dc 00 50 fb d8 00 44 fb e4 00 2c fe e6 00
80 fe 98 00 14 fb e6 00 90 fa c2 00 80 fe 40 00 80 fe 40 00 80 fe
40 00 80 fe 40 00 80 fe 62 00 54 fd 72 00 9c fd a5 e9 b5 0a e3 0c
b3 0a
*/
/*
M3
c4 00 a8 fd 80 00 f4 fc b8 01 2c fb c8 01 54 fa 80 00 64 fc 94 01
d8 fa 80 00 80 fe 80 00 80 fe 80 00 80 fe 80 00 80 fe 80 00 80 fe
80 00 80 fe 80 00 80 fe c4 00 54 fd d4 00 6c fd 35 63 52 8b e5 95
46 8b
*/

#include "cmsis_os.h"
//chave 761
//anterior 757
//proxima 769
//indice par div 4
//indice impar div 8
uint8_t men1[] = 
{	0x50, 0x01, 0xc0, 0xfc, 0x94, 0x01, 0x00, 0xff, 0x1c, 0x01, 
	0x88, 0xfc, 0x90, 0x01, 0xd0, 0xfc, 0x84, 0x01, 0x60, 0xfc, 
	0xa0, 0x01, 0xd8, 0xfc, 0xc8, 0x01, 0x00, 0xff, 0x80, 0x00, 
	0x00, 0xff, 0x80, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0xff, 
	0x80, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0xff, 0x80, 0x00, 
	0x00, 0xff, 0xc4, 0x00, 0x38, 0xfe, 0xdc, 0x00, 0x70, 0xfe, 
	0xf9, 0xed, 0x08, 0x00, 0x4d, 0xca, 0x08, 0x00
};
//chave 13399
//anterior 13397
//proxima 13411
uint8_t men2[] = 
{	0xa6, 0x00, 0x5c, 0xfb, 0xd0, 0x00, 0x14, 0xfb, 0xdc, 0x00, 
	0x50, 0xfb, 0xd8, 0x00, 0x44, 0xfb, 0xe4, 0x00, 0x2c, 0xfe, 
	0xe6, 0x00, 0x80, 0xfe, 0x98, 0x00, 0x14, 0xfb, 0xe6, 0x00, 
	0x90, 0xfa, 0xc2, 0x00, 0x80, 0xfe, 0x40, 0x00, 0x80, 0xfe, 
	0x40, 0x00, 0x80, 0xfe, 0x40, 0x00, 0x80, 0xfe, 0x40, 0x00, 
	0x80, 0xfe, 0x62, 0x00, 0x54, 0xfd, 0x72, 0x00, 0x9c, 0xfd, 
	0xa5, 0xe9, 0xb5, 0x0a, 0xe3, 0x0c, 0xb3, 0x0a
};
//chave 48341
//anterior 48337
//proxima 48353
uint8_t men3[] = 
{	0xc4, 0x00, 0xa8, 0xfd, 0x80, 0x00, 0xf4, 0xfc, 0xb8, 0x01, 
	0x2c, 0xfb, 0xc8, 0x01, 0x54, 0xfa, 0x80, 0x00, 0x64, 0xfc, 
	0x94, 0x01, 0xd8, 0xfa, 0x80, 0x00, 0x80, 0xfe, 0x80, 0x00, 
	0x80, 0xfe, 0x80, 0x00, 0x80, 0xfe, 0x80, 0x00, 0x80, 0xfe, 
	0x80, 0x00, 0x80, 0xfe, 0x80, 0x00, 0x80, 0xfe, 0x80, 0x00, 
	0x80, 0xfe, 0xc4, 0x00, 0x54, 0xfd, 0xd4, 0x00, 0x6c, 0xfd, 
	0x35, 0x63, 0x52, 0x8b, 0xe5, 0x95, 0x46, 0x8b
};

/*

50, 01, c0, fc, 94, 01, 00, ff, 1c, 01, 88, fc, 90, 01, d0, fc, 84, 01, 60, fc, a0, 01, d8, fc, c8, 01, 00, ff, 80, 00, 00, ff, 80, 00, 00, ff, 80, 00, 00, ff, 80, 00, 00, ff, 80, 00, 00, ff, 80, 00, 00, ff, c4, 00, 38, fe, dc, 00, 70, fe, f9, ed, 08, 00, 4d, ca, 08, 00*/