#pragma once




const int DOWN_BUTTON_W = 20;
const int DOWN_BUTTON_H = 20;




const uint16_t downButtonPixMap [DOWN_BUTTON_H * DOWN_BUTTON_W] PROGMEM = {
0x8410, 0x8410, 0x8410, 0x8410, 0x8410, 0x7bf0, 0x840f, 0x942f, 0x8bee, 0x738e, 0x738d, 0x83ce, 0x942f, 0x8c0f, 0x7bf0, 0x8410, 0x8410, 0x8410, 0x8410, 0x8410, 
0x8410, 0x8410, 0x8410, 0x7bf0, 0x8410, 0x8c0f, 0x6b8e, 0x536f, 0x53d2, 0x5c34, 0x5c54, 0x53f3, 0x5390, 0x636e, 0x83ef, 0x840f, 0x7bf0, 0x8410, 0x8410, 0x8410, 
0x8410, 0x8410, 0x7bf0, 0x840f, 0x7bcf, 0x4350, 0x6cd6, 0xae7c, 0xbefe, 0xbf1f, 0xaede, 0xa69d, 0x9e3c, 0x7538, 0x4bb1, 0x73ae, 0x8c0f, 0x7bf0, 0x8410, 0x8410, 
0x8410, 0x7bf0, 0x840f, 0x73ae, 0x4392, 0xae7c, 0xdf9f, 0xbf1f, 0x9e9d, 0x8e3d, 0x7dfc, 0x6dbc, 0x6dbc, 0x7dfc, 0x963c, 0x5c54, 0x638e, 0x8c0f, 0x7bf0, 0x8410, 
0x8410, 0x840f, 0x7bce, 0x4392, 0xc71e, 0xc75f, 0x9e9d, 0x967d, 0x863d, 0x7dfc, 0x6dbb, 0x5d7b, 0x553a, 0x3cd9, 0x2c99, 0x861c, 0x5c75, 0x6b8e, 0x840f, 0x7bf0, 
0x7bf0, 0x8c0f, 0x4350, 0xa67c, 0xbf3f, 0x967d, 0x8e5d, 0x861c, 0x75dc, 0x659b, 0x5d5b, 0x4d1a, 0x3499, 0x1c38, 0x0bf7, 0x03b6, 0x7ddb, 0x53d2, 0x83ef, 0x7bf0, 
0x840f, 0x6b8e, 0x6cb6, 0xc75f, 0x8e5d, 0x861d, 0x75dc, 0x6dbc, 0x657b, 0x553a, 0x2c99, 0x1418, 0x0bf7, 0x03b6, 0x0396, 0x0395, 0x2437, 0x7d59, 0x5b6f, 0x8c2f, 
0x942f, 0x536f, 0x9e5c, 0x9e9e, 0x7dfc, 0x75fc, 0x7dfc, 0x4d3a, 0x44fa, 0x1438, 0x03f7, 0x0bf7, 0x0396, 0x2457, 0x1c17, 0x0375, 0x0354, 0x6559, 0x63f2, 0x940e, 
0x8bee, 0x5bf2, 0xa6be, 0x6ddc, 0x65bc, 0xc71e, 0xe79f, 0x5d5b, 0x03d7, 0x0bf7, 0x0c17, 0x0396, 0x1c17, 0xd75e, 0xe77e, 0x1bf6, 0x0313, 0x3c97, 0x6c95, 0x6b6d, 
0x738d, 0x6454, 0x967e, 0x557b, 0x4d3b, 0x965d, 0xefbf, 0xd75e, 0x3cd9, 0x0396, 0x0396, 0x13f7, 0xcf3d, 0xffff, 0xbebc, 0x13b5, 0x0333, 0x2c36, 0x6cd6, 0x530d, 
0x736d, 0x6454, 0x863d, 0x451b, 0x3cfa, 0x1c59, 0x7ddb, 0xf7df, 0xe77e, 0x3498, 0x0bd6, 0xcf3d, 0xffff, 0xb6bc, 0x0354, 0x0354, 0x0333, 0x2415, 0x6cd6, 0x530d, 
0x83ce, 0x6433, 0x7dfc, 0x2cba, 0x2c99, 0x1438, 0x03b7, 0x7ddb, 0xffff, 0xd75e, 0xcf1d, 0xffff, 0xb6bc, 0x0354, 0x0353, 0x0374, 0x02f2, 0x3456, 0x6cb6, 0x632d, 
0x942f, 0x5bb1, 0x7ddb, 0x1c79, 0x1438, 0x0c18, 0x0bf7, 0x0376, 0x85db, 0xffff, 0xffff, 0xbedc, 0x0354, 0x0333, 0x0374, 0x0353, 0x02d1, 0x54f7, 0x6433, 0x83ce, 
0x8c0f, 0x636f, 0x7538, 0x2cda, 0x03d7, 0x0bf7, 0x0bf7, 0x0bd6, 0x0355, 0x963b, 0xcf1d, 0x0354, 0x0333, 0x0374, 0x0353, 0x0332, 0x0353, 0x7d79, 0x5b90, 0x942f, 
0x7bf0, 0x83ef, 0x53d2, 0x7ddb, 0x03b7, 0x0bf7, 0x0bd6, 0x0bd6, 0x0395, 0x0375, 0x0374, 0x0354, 0x0374, 0x0353, 0x0353, 0x02b1, 0x5d18, 0x6475, 0x73ae, 0x840f, 
0x7c10, 0x840f, 0x6b8e, 0x6496, 0x6d9b, 0x0375, 0x03b6, 0x0bb5, 0x0395, 0x0374, 0x0374, 0x0374, 0x0353, 0x0333, 0x02b1, 0x4496, 0x7538, 0x5b6f, 0x8c0f, 0x7bf0, 
0x8410, 0x7bf0, 0x8c0f, 0x5b6f, 0x6cd6, 0x75bb, 0x13f6, 0x0334, 0x0354, 0x0374, 0x0353, 0x0313, 0x02d1, 0x0312, 0x5cf8, 0x7558, 0x5370, 0x8c0f, 0x7bf0, 0x8410, 
0x8410, 0x8410, 0x7bf0, 0x8c0f, 0x636e, 0x5c34, 0x7d9a, 0x5d19, 0x2c36, 0x1bd5, 0x13b4, 0x23f5, 0x4c97, 0x7d79, 0x6496, 0x5b6f, 0x840f, 0x7c10, 0x8410, 0x8410, 
0x8410, 0x8410, 0x8410, 0x7bf0, 0x8c0f, 0x7bce, 0x5b90, 0x6454, 0x6cd6, 0x7517, 0x7517, 0x6cd7, 0x6475, 0x5bb1, 0x73ae, 0x8c0f, 0x7bf0, 0x7c10, 0x8410, 0x8410, 
0x8410, 0x8410, 0x8410, 0x8410, 0x7bf0, 0x8410, 0x942f, 0x83ce, 0x5b2d, 0x534e, 0x534e, 0x532d, 0x738e, 0x942f, 0x840f, 0x7bf0, 0x8410, 0x8410, 0x8410, 0x8410
};


const uint16_t downButtonAlphaMask [] PROGMEM = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,7,82,149,183,186,158,98,20,0,0,0,0,0,0,
0,0,0,0,0,108,233,255,255,255,255,255,255,248,139,2,0,0,0,0,
0,0,0,0,174,255,255,255,255,255,255,255,255,255,255,209,19,0,0,0,
0,0,0,176,255,255,255,255,255,255,255,255,255,255,255,255,219,6,0,0,
0,0,98,255,255,255,255,255,255,255,255,255,255,255,255,255,255,157,0,0,
0,5,239,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,34,0,
0,77,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,135,0,
0,149,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,201,0,
0,184,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,227,0,
0,189,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,230,0,
0,164,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,213,0,
0,105,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,162,0,
0,23,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,66,0,
0,0,155,255,255,255,255,255,255,255,255,255,255,255,255,255,255,210,0,0,
0,0,10,232,255,255,255,255,255,255,255,255,255,255,255,255,255,42,0,0,
0,0,0,38,237,255,255,255,255,255,255,255,255,255,255,255,78,0,0,0,
0,0,0,0,27,190,255,255,255,255,255,255,255,255,216,57,0,0,0,0,
0,0,0,0,0,0,71,170,224,241,242,230,185,93,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,33,37,3,0,0,0,0,0,0,0,0
};
