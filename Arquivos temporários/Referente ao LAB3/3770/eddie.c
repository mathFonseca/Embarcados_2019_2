/* http://srecord.sourceforge.net/ */
const unsigned char eddie[] =
{
0x50, 0x36, 0x0A, 0x38, 0x20, 0x31, 0x34, 0x0A, 0x32, 0x35, 0x35, 0x0A,
0x00, 0x00, 0x0C, 0x00, 0x00, 0x1B, 0xB9, 0xC2, 0xF9, 0xB7, 0xC2, 0xFF,
0xBD, 0xC4, 0xFF, 0xBD, 0xC2, 0xF9, 0x00, 0x00, 0x1E, 0x00, 0x01, 0x15,
0x00, 0x04, 0x00, 0xBC, 0xCC, 0xCC, 0xB4, 0xD0, 0xDB, 0xAE, 0xCE, 0xDB,
0xB0, 0xCC, 0xD8, 0xB7, 0xCD, 0xD8, 0xBC, 0xCB, 0xD0, 0x00, 0x04, 0x06,
0x00, 0x10, 0x00, 0x00, 0x13, 0x00, 0xC2, 0xFF, 0xB3, 0xBB, 0xFF, 0xA9,
0xBC, 0xFF, 0xA4, 0xC5, 0xFE, 0xAF, 0x00, 0x10, 0x00, 0x00, 0x0B, 0x00,
0x00, 0x1D, 0x00, 0x69, 0xAB, 0x53, 0x62, 0xAA, 0x46, 0x60, 0xB1, 0x39,
0x5C, 0xB9, 0x2A, 0x5E, 0xB9, 0x30, 0x6B, 0xAF, 0x4A, 0x00, 0x1A, 0x00,
0x4D, 0xBA, 0x39, 0x5D, 0xB5, 0x4D, 0x62, 0x93, 0x5C, 0x66, 0x9A, 0x5A,
0x58, 0xBC, 0x36, 0x4A, 0xC3, 0x1E, 0x50, 0xC1, 0x27, 0x51, 0xBF, 0x2A,
0x49, 0xBF, 0x37, 0x5C, 0xB6, 0x52, 0x6C, 0x8A, 0x70, 0x69, 0x8B, 0x66,
0x55, 0xBA, 0x38, 0x41, 0xCA, 0x18, 0x3D, 0xC8, 0x13, 0x3C, 0xCA, 0x14,
0x5A, 0xB5, 0x4C, 0x68, 0xAB, 0x5E, 0x73, 0x84, 0x71, 0x72, 0x8E, 0x66,
0x56, 0xBB, 0x37, 0x3D, 0xCB, 0x17, 0x3B, 0xCF, 0x1B, 0x3A, 0xD2, 0x1D,
0x54, 0xA0, 0x48, 0x5D, 0x99, 0x53, 0x6F, 0x89, 0x66, 0x6C, 0x95, 0x5B,
0x53, 0xBB, 0x32, 0x40, 0xCE, 0x1A, 0x39, 0xCE, 0x1A, 0x36, 0xCF, 0x1C,
0x59, 0x9F, 0x49, 0x5A, 0x9B, 0x4B, 0x60, 0x97, 0x54, 0x5A, 0xA0, 0x47,
0x4B, 0xBB, 0x29, 0x43, 0xCC, 0x1E, 0x3E, 0xCD, 0x1B, 0x3C, 0xD0, 0x1C,
0x70, 0xA3, 0x61, 0x72, 0xA4, 0x5D, 0x74, 0xA3, 0x52, 0x72, 0xAB, 0x44,
0x66, 0xB6, 0x2F, 0x5C, 0xBC, 0x27, 0x55, 0xBC, 0x2F, 0x4E, 0xBA, 0x31,
0x00, 0x08, 0x00, 0x00, 0x0B, 0x00, 0xD9, 0xDA, 0x8E, 0xDD, 0xDF, 0x7A,
0xD6, 0xE0, 0x70, 0xCE, 0xE3, 0x7E, 0x00, 0x11, 0x00, 0x00, 0x13, 0x00,
0x0D, 0x01, 0x00, 0x13, 0x02, 0x00, 0xE9, 0xD0, 0x74, 0xF4, 0xD5, 0x69,
0xF4, 0xD8, 0x6B, 0xE9, 0xD4, 0x81, 0x09, 0x03, 0x00, 0x00, 0x01, 0x00,
0xF3, 0xD5, 0x67, 0xF4, 0xD5, 0x61, 0xF8, 0xD6, 0x5A, 0xF9, 0xD6, 0x56,
0xF9, 0xD3, 0x54, 0xEF, 0xD2, 0x74, 0x0D, 0x00, 0x00, 0x05, 0x04, 0x02,
0xFF, 0xDB, 0x4B, 0xFF, 0xDB, 0x4C, 0xFA, 0xD3, 0x47, 0xFD, 0xD6, 0x4B,
0xFF, 0xD8, 0x50, 0xF2, 0xD0, 0x6C, 0x0F, 0x00, 0x00, 0x03, 0x00, 0x02,
};
const unsigned long eddie_termination = 0x00000000;
const unsigned long eddie_start       = 0x00000000;
const unsigned long eddie_finish      = 0x0000015C;
const unsigned long eddie_length      = 0x0000015C;

#define EDDIE_TERMINATION 0x00000000
#define EDDIE_START       0x00000000
#define EDDIE_FINISH      0x0000015C
#define EDDIE_LENGTH      0x0000015C
