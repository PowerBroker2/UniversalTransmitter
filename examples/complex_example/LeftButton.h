#pragma once




const int LEFT_BUTTON_W = 20;
const int LEFT_BUTTON_H = 20;




const uint16_t leftButtonPixMap [LEFT_BUTTON_H * LEFT_BUTTON_W] PROGMEM = {
0x8410, 0x8410, 0x8410, 0x8410, 0x8410, 0x7bf0, 0x840f, 0x942f, 0x8bee, 0x7bae, 0x7bae, 0x8bee, 0x942f, 0x840f, 0x7bf0, 0x8410, 0x8410, 0x8410, 0x8410, 0x8410, 
0x8410, 0x8410, 0x8410, 0x7bf0, 0x8410, 0x8c0f, 0x6b8e, 0x536f, 0x53b2, 0x5c13, 0x5c13, 0x53d2, 0x5390, 0x6b8e, 0x8c0f, 0x8410, 0x7bf0, 0x8410, 0x8410, 0x8410, 
0x8410, 0x8410, 0x7bf0, 0x840f, 0x7bcf, 0x4350, 0x64b6, 0xa65c, 0xbefe, 0xb6fe, 0xaede, 0xa69d, 0x961b, 0x6cf7, 0x4b90, 0x73ae, 0x840f, 0x7bf0, 0x8410, 0x8410, 
0x8410, 0x7bf0, 0x840f, 0x73ae, 0x4392, 0xae7c, 0xdf9f, 0xbf3f, 0x9e9e, 0x8e3d, 0x7dfc, 0x6ddc, 0x6ddc, 0x861c, 0x961c, 0x5413, 0x6b8e, 0x840f, 0x7bf0, 0x8410, 
0x8410, 0x840f, 0x7bce, 0x4392, 0xc71e, 0xc75f, 0x9e9d, 0x967d, 0x8e3d, 0x75dc, 0x659b, 0x555a, 0x553a, 0x3cb9, 0x34b9, 0x8e1c, 0x5414, 0x73ae, 0x840f, 0x7c10, 
0x7bf0, 0x8c0f, 0x4350, 0xae9d, 0xbf3f, 0x967d, 0x8e5d, 0x861c, 0x6dbc, 0x555b, 0xbedd, 0xae9d, 0x2c99, 0x1c38, 0x0bf7, 0x0bd6, 0x7ddb, 0x53b1, 0x83ef, 0x7bf0, 
0x840f, 0x636e, 0x6cd7, 0xc75f, 0x8e5d, 0x863d, 0x7dfc, 0x659b, 0x4d3a, 0xaebd, 0xffff, 0xe79e, 0x1c38, 0x03b6, 0x0bd6, 0x0375, 0x2c78, 0x7538, 0x638f, 0x8c0f, 
0x942f, 0x5370, 0xa67c, 0x9e9e, 0x861d, 0x75dc, 0x659b, 0x451a, 0xa69d, 0xffdf, 0xdf7e, 0x2c78, 0x03b6, 0x0bd6, 0x0bd6, 0x0bb5, 0x0374, 0x6d79, 0x63d1, 0x942f, 
0x83ce, 0x5bf3, 0xa6be, 0x6ddc, 0x6dbc, 0x5d7b, 0x3cfa, 0x9e7d, 0xf7df, 0xdf7e, 0x2c78, 0x0396, 0x0bd6, 0x0bd6, 0x0bb5, 0x0395, 0x0313, 0x44d8, 0x6c74, 0x738e, 
0x6b6d, 0x6474, 0x967e, 0x557b, 0x555b, 0x451a, 0xa67d, 0xefbf, 0xcf1e, 0x2c78, 0x0396, 0x0bd6, 0x0bd6, 0x0bb5, 0x0395, 0x0394, 0x0333, 0x3456, 0x6cb6, 0x5b2d, 
0x634d, 0x6c95, 0x863d, 0x451b, 0x3cda, 0x3cfa, 0xdf5e, 0xf7df, 0x9e5c, 0x0356, 0x03b6, 0x0bd6, 0x0bb5, 0x0395, 0x0394, 0x0374, 0x0333, 0x2c36, 0x6cb6, 0x5b0d, 
0x738e, 0x6454, 0x75fd, 0x249a, 0x2c99, 0x0bf8, 0x2c78, 0xdf5e, 0xffff, 0x9e5c, 0x0355, 0x0395, 0x0395, 0x0394, 0x0374, 0x0374, 0x02f2, 0x3c76, 0x6c95, 0x6b4d, 
0x940f, 0x5bd1, 0x7ddc, 0x1459, 0x1438, 0x0c18, 0x0396, 0x2c78, 0xe79e, 0xffff, 0x9e5b, 0x0334, 0x0374, 0x0374, 0x0374, 0x0353, 0x02d1, 0x5cf8, 0x6433, 0x8bee, 
0x8c2f, 0x5b6f, 0x7d79, 0x2499, 0x0bf7, 0x0bf7, 0x0bf7, 0x0375, 0x2c57, 0xefbf, 0xffff, 0xae9c, 0x0b74, 0x0353, 0x0353, 0x0332, 0x0b73, 0x7d79, 0x5b90, 0x942f, 
0x7bf0, 0x7bcf, 0x5c13, 0x75bb, 0x0397, 0x0bf7, 0x0bd6, 0x0bd6, 0x0334, 0x2c36, 0xffff, 0xefbe, 0x1394, 0x0333, 0x0353, 0x02b1, 0x5d18, 0x6455, 0x7bae, 0x83ef, 
0x7bf0, 0x840f, 0x636e, 0x6cf7, 0x5d7b, 0x0375, 0x0bb6, 0x0bb5, 0x03b5, 0x0313, 0x3456, 0x1bd5, 0x0312, 0x0353, 0x02b1, 0x4496, 0x7538, 0x5b6f, 0x8c0f, 0x7bf0, 
0x8410, 0x7bf0, 0x8c0f, 0x5b6f, 0x7518, 0x657a, 0x0bb6, 0x0334, 0x0354, 0x0374, 0x0313, 0x02f2, 0x02d1, 0x0312, 0x5cf7, 0x7538, 0x536f, 0x8c0f, 0x7bf0, 0x8410, 
0x8410, 0x8410, 0x7bf0, 0x8c0f, 0x5b6f, 0x6475, 0x7d9a, 0x54f8, 0x2416, 0x13b5, 0x13b4, 0x23d4, 0x4c96, 0x7d79, 0x64b6, 0x5b6f, 0x8c0f, 0x7c10, 0x8410, 0x8410, 
0x8410, 0x8410, 0x8410, 0x7bf0, 0x8c0f, 0x73ae, 0x5b90, 0x6474, 0x6cf7, 0x7518, 0x7518, 0x74f7, 0x6475, 0x5bb1, 0x73ae, 0x8c0f, 0x7bf0, 0x7c10, 0x8410, 0x8410, 
0x8410, 0x8410, 0x8410, 0x8410, 0x7bf0, 0x840f, 0x942f, 0x738e, 0x532e, 0x534f, 0x534f, 0x532e, 0x738d, 0x942f, 0x840f, 0x7bf0, 0x8410, 0x8410, 0x8410, 0x8410
};


const uint16_t leftButtonAlphaMask [] PROGMEM = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,3,74,138,172,173,142,81,9,0,0,0,0,0,0,
0,0,0,0,0,104,229,255,255,255,255,255,255,236,118,0,0,0,0,0,
0,0,0,0,173,255,255,255,255,255,255,255,255,255,255,190,6,0,0,0,
0,0,0,179,255,255,255,255,255,255,255,255,255,255,255,255,199,0,0,0,
0,0,106,255,255,255,255,255,255,255,255,255,255,255,255,255,255,132,0,0,
0,8,244,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,20,0,
0,88,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,113,0,
0,162,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,185,0,
0,197,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,215,0,
0,201,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,220,0,
0,182,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,202,0,
0,125,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,150,0,
0,37,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,57,0,
0,0,180,255,255,255,255,255,255,255,255,255,255,255,255,255,255,203,0,0,
0,0,23,247,255,255,255,255,255,255,255,255,255,255,255,255,255,38,0,0,
0,0,0,57,250,255,255,255,255,255,255,255,255,255,255,255,76,0,0,0,
0,0,0,0,44,209,255,255,255,255,255,255,255,255,219,58,0,0,0,0,
0,0,0,0,0,0,90,187,233,245,246,235,193,100,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,11,51,53,15,0,0,0,0,0,0,0,0
};
