#define LATCH_PIN 3
#define CLOCK_PIN 4
#define DATA_PIN 2

int predict(byte* bytemap);
void sevenSegWrite(int digit);
 
void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

  byte input[25] = {
1, 1, 0, 0, 0, 
1, 0, 0, 0, 0, 
1, 1, 1, 0, 0, 
1, 0, 1, 0, 0, 
1, 1, 1, 0, 0, 
  };

  int prediction = predict(input);

  sevenSegWrite(prediction);
}


int predict(byte* bytemap){
    byte brain[300];
    memset(brain, 0, 300);
    memcpy(brain + 1, bytemap, 25);
    
    brain[26] = brain[1] && brain[2] && brain[3];
    brain[27] = brain[2] && brain[3] && brain[4];
    brain[28] = brain[3] && brain[4] && brain[5];
    brain[29] = brain[6] && brain[7] && brain[8];
    brain[30] = brain[7] && brain[8] && brain[9];
    brain[31] = brain[8] && brain[9] && brain[10];
    brain[32] = brain[11] && brain[12] && brain[13];
    brain[33] = brain[12] && brain[13] && brain[14];
    brain[34] = brain[13] && brain[14] && brain[15];
    brain[35] = brain[16] && brain[17] && brain[18];
    brain[36] = brain[17] && brain[18] && brain[19];
    brain[37] = brain[18] && brain[19] && brain[20];
    brain[38] = brain[21] && brain[22] && brain[23];
    brain[39] = brain[22] && brain[23] && brain[24];
    brain[40] = brain[23] && brain[24] && brain[25];
    brain[41] = brain[1] && brain[6] && brain[11];
    brain[42] = brain[6] && brain[11] && brain[16];
    brain[43] = brain[11] && brain[16] && brain[21];
    brain[44] = brain[2] && brain[7] && brain[12];
    brain[45] = brain[7] && brain[12] && brain[17];
    brain[46] = brain[12] && brain[17] && brain[22];
    brain[47] = brain[3] && brain[8] && brain[13];
    brain[48] = brain[8] && brain[13] && brain[18];
    brain[49] = brain[13] && brain[18] && brain[23];
    brain[50] = brain[4] && brain[9] && brain[14];
    brain[51] = brain[9] && brain[14] && brain[19];
    brain[52] = brain[14] && brain[19] && brain[24];
    brain[53] = brain[5] && brain[10] && brain[15];
    brain[54] = brain[10] && brain[15] && brain[20];
    brain[55] = brain[15] && brain[20] && brain[25];
    brain[57] = brain[6] && brain[12] && brain[18];
    brain[60] = brain[7] && brain[13] && brain[19];
    brain[63] = brain[8] && brain[14] && brain[20];
    brain[65] = brain[15] && brain[19] && brain[23];
    brain[66] = brain[10] && brain[14] && brain[18];
    brain[67] = brain[14] && brain[18] && brain[22];
    brain[68] = brain[5] && brain[9] && brain[13];
    brain[69] = brain[9] && brain[13] && brain[17];
    brain[70] = brain[13] && brain[17] && brain[21];
    brain[71] = brain[4] && brain[8] && brain[12];
    brain[72] = brain[8] && brain[12] && brain[16];
    brain[73] = brain[3] && brain[7] && brain[11];
    brain[74] = brain[8] && brain[12] && brain[18];
    brain[75] = brain[9] && brain[13] && brain[19];
    brain[76] = brain[10] && brain[14] && brain[20];
    
    brain[77] = brain[26] && brain[41];
    brain[78] = brain[26] && brain[47];
    brain[79] = brain[32] && brain[41];
    brain[80] = brain[32] && brain[47];
    brain[81] = brain[32] && brain[43];
    brain[82] = brain[32] && brain[49];
    brain[83] = brain[38] && brain[43];
    brain[84] = brain[38] && brain[49];
    brain[85] = brain[27] && brain[44];
    brain[86] = brain[27] && brain[50];
    brain[87] = brain[33] && brain[44];
    brain[88] = brain[33] && brain[50];
    brain[89] = brain[33] && brain[46];
    brain[90] = brain[33] && brain[52];
    brain[91] = brain[39] && brain[46];
    brain[92] = brain[39] && brain[52];
    brain[93] = brain[47] && brain[28];
    brain[94] = brain[53] && brain[28];
    brain[95] = brain[34] && brain[47];
    brain[96] = brain[34] && brain[53];
    brain[97] = brain[34] && brain[49];
    brain[98] = brain[34] && brain[55];
    brain[99] = brain[40] && brain[49];
    brain[100] = brain[40] && brain[55];
    brain[111] = brain[41] && brain[42];
    brain[112] = brain[42] && brain[43];
    brain[113] = brain[44] && brain[45];
    brain[114] = brain[45] && brain[46];
    brain[115] = brain[47] && brain[48];
    brain[116] = brain[48] && brain[49];
    brain[117] = brain[50] && brain[51];
    brain[118] = brain[51] && brain[52];
    brain[119] = brain[53] && brain[54];
    brain[120] = brain[54] && brain[55];
    brain[129] = brain[26] && brain[57];
    brain[130] = brain[26] && brain[72];
    brain[131] = brain[38] && brain[57];
    brain[132] = brain[38] && brain[72];
    brain[133] = brain[27] && brain[60];
    brain[134] = brain[27] && brain[69];
    brain[135] = brain[39] && brain[60];
    brain[136] = brain[39] && brain[69];
    brain[137] = brain[28] && brain[63];
    brain[138] = brain[28] && brain[66];
    brain[139] = brain[40] && brain[63];
    brain[140] = brain[40] && brain[66];
    brain[144] = brain[29] && brain[70];
    brain[145] = brain[30] && brain[67];
    brain[146] = brain[31] && brain[65];
    brain[147] = brain[32] && brain[73];
    brain[148] = brain[33] && brain[71];
    brain[149] = brain[34] && brain[68];
    brain[153] = brain[47] && brain[74];
    brain[154] = brain[50] && brain[75];
    brain[155] = brain[53] && brain[76];
    
    brain[171] = brain[78] && brain[81] && brain[83];
    brain[172] = brain[86] && brain[89] && brain[91];
    brain[173] = brain[94] && brain[97] && brain[99];
    brain[174] = brain[130] && brain[132];
    brain[175] = brain[134] && brain[136];
    brain[176] = brain[138] && brain[140];
    brain[181] = brain[78] && brain[82] && brain[84];
    brain[182] = brain[86] && brain[90] && brain[92];
    brain[183] = brain[94] && brain[98] && brain[100];
    brain[184] = brain[78] && brain[84] && brain[153];
    brain[185] = brain[86] && brain[92] && brain[154];
    brain[186] = brain[94] && brain[100] && brain[155];
    brain[190] = brain[79] && brain[116];
    brain[191] = brain[87] && brain[118];
    brain[192] = brain[95] && brain[120];
    brain[196] = brain[77] && brain[82] && brain[84];
    brain[197] = brain[85] && brain[90] && brain[92];
    brain[198] = brain[93] && brain[98] && brain[100];
    brain[199] = brain[129] && brain[131];
    brain[200] = brain[133] && brain[135];
    brain[201] = brain[137] && brain[140];
    brain[203] = brain[79] && brain[83] && brain[84];
    brain[204] = brain[87] && brain[91] && brain[92];
    brain[205] = brain[95] && brain[99] && brain[100];
    brain[206] = brain[82] && brain[83] && brain[147];
    brain[207] = brain[90] && brain[91] && brain[148];
    brain[208] = brain[98] && brain[99] && brain[149];
    brain[216] = brain[78] && brain[115];
    brain[217] = brain[86] && brain[117];
    brain[218] = brain[94] && brain[119];
    brain[227] = brain[130] && brain[131];
    brain[228] = brain[134] && brain[135];
    brain[229] = brain[138] && brain[139];
    brain[233] = brain[78] && brain[79] && brain[116];
    brain[234] = brain[86] && brain[87] && brain[118];
    brain[235] = brain[94] && brain[95] && brain[120];
    brain[242] = brain[77] && brain[88] && brain[118];
    brain[243] = brain[85] && brain[96] && brain[120];
    brain[245] = brain[77] && brain[83] && brain[115];
    brain[246] = brain[85] && brain[91] && brain[117];
    brain[247] = brain[93] && brain[99] && brain[119];
    
    brain[291] = brain[111] || brain[113] || brain[115] || brain[117] || brain[119];
    brain[292] = brain[112] || brain[114] || brain[116] || brain[118] || brain[120];
    brain[293] = brain[130] || brain[134] || brain[138] || brain[144] || brain[145] || brain[146];
    
    brain[251] = brain[245] || brain[246] || brain[247] || brain[248] || brain[249];
    brain[252] = brain[156] || brain[157] || brain[158] || brain[159] || brain[160] || brain[291] || brain[292];
    brain[253] = brain[171] || brain[172] || brain[173] || brain[174] || brain[175] || brain[176] || brain[179] || brain[288] || brain[289] || brain[290];
    brain[254] = brain[181] || brain[182] || brain[183] || brain[184] || brain[185] || brain[186] || brain[189] || brain[271] || brain[272] || brain[273];
    brain[255] = brain[190] || brain[191] || brain[192] || brain[193] || brain[194] || brain[195] || brain[265] || brain[266] || brain[267] || brain[268] || brain[269] || brain[270] || brain[285] || brain[286] || brain[287];
    brain[256] = brain[196] || brain[197] || brain[198] || brain[199] || brain[200] || brain[201];
    brain[257] = brain[203] || brain[204] || brain[205] || brain[206] || brain[207] || brain[208];
    brain[258] = brain[216] || brain[217] || brain[218] || brain[274] || brain[275] || brain[276] || brain[293];
    brain[259] = brain[227] || brain[228] || brain[229] || brain[230] || brain[231] || brain[277] || brain[278] || brain[279] || brain[280] || brain[281];
    brain[260] = brain[233] || brain[234] || brain[235] || brain[242] || brain[243] || brain[261] || brain[262] || brain[263];
    
    if(brain[259]) return 8;
    if(brain[260]) return 9;
    if(brain[251]) return 0;
    if(brain[253]) return 2;
    if(brain[254]) return 3;
    if(brain[258]) return 7;
    if(brain[257]) return 6;
    if(brain[255]) return 4;
    if(brain[256]) return 5;
    if(brain[252]) return 1;
    return -1;
}

void sevenSegWrite(int digit) {
  byte seven_seg_digits[10] = { B11111100,  // = 0
                                B01100000,  // = 1
                                B11011100,  // = 2
                                B11110100,  // = 3
                                B01100110,  // = 4
                                B10110110,  // = 5
                                B10111110,  // = 6
                                B11100000,  // = 7
                                B11111110,  // = 8
                                B11100110   // = 9
                             };

  digitalWrite(LATCH_PIN, LOW);
     
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, digit > 0 ? seven_seg_digits[digit] : B00000000);  
 
  digitalWrite(LATCH_PIN, HIGH);
}
 
void loop() {       

}
