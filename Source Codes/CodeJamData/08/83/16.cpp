#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// BEGIN CUT HERE
#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define sz size()

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
// END CUT HERE

const int MODULE = 1000000009;

int inverse[1000];

i64 select(int N, int K)
{
	i64 total = 1;
	REP(i, K) {
		total = (total * (N-i)) % MODULE;
		//total = (total * inverse[i+1]) % MODULE;
	}
	return total;
}

int N, K;
VVI next;

i64 go(int v, int prevV, int L1, int L2)
{
	int childCnt = next[v].sz;
	if (prevV != -1)
		childCnt--;

	int colAvail = K - L1 - L2;
	if (colAvail < childCnt)
		return 0;
	if (childCnt == 0)
		return 1;

	i64 res = 1;
	for (int i = 0; i < next[v].sz; i++) {
		int u = next[v][i];
		if (u == prevV)
			continue;

		res *= go(u, v, childCnt, (prevV == -1 ? 0 : 1));
		res %= MODULE;
	}

	res *= select(colAvail, childCnt);
	res %= MODULE;
	return res;
}

int solve()
{
	scanf("%d %d", &N, &K);
	next.clear();
	next.resize(N);

	REP(i, N-1) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		next[u].pb(v);
		next[v].pb(u);
	}

	return go(0, -1, 0, 0);
}

int main()
{
	inverse[1] = 1;
	inverse[2] = 500000005;
	inverse[3] = 666666673;
	inverse[4] = 750000007;
	inverse[5] = 200000002;
	inverse[6] = 833333341;
	inverse[7] = 857142865;
	inverse[8] = 875000008;
	inverse[9] = 888888897;
	inverse[10] = 100000001;
	inverse[11] = 363636367;
	inverse[12] = 916666675;
	inverse[13] = 615384621;
	inverse[14] = 928571437;
	inverse[15] = 733333340;
	inverse[16] = 437500004;
	inverse[17] = 58823530;
	inverse[18] = 944444453;
	inverse[19] = 368421056;
	inverse[20] = 550000005;
	inverse[21] = 952380961;
	inverse[22] = 681818188;
	inverse[23] = 826086964;
	inverse[24] = 958333342;
	inverse[25] = 440000004;
	inverse[26] = 807692315;
	inverse[27] = 296296299;
	inverse[28] = 964285723;
	inverse[29] = 517241384;
	inverse[30] = 366666670;
	inverse[31] = 838709685;
	inverse[32] = 218750002;
	inverse[33] = 787878795;
	inverse[34] = 29411765;
	inverse[35] = 171428573;
	inverse[36] = 972222231;
	inverse[37] = 297297300;
	inverse[38] = 184210528;
	inverse[39] = 205128207;
	inverse[40] = 775000007;
	inverse[41] = 195121953;
	inverse[42] = 976190485;
	inverse[43] = 139534885;
	inverse[44] = 340909094;
	inverse[45] = 577777783;
	inverse[46] = 413043482;
	inverse[47] = 340425535;
	inverse[48] = 479166671;
	inverse[49] = 408163269;
	inverse[50] = 220000002;
	inverse[51] = 686274516;
	inverse[52] = 903846162;
	inverse[53] = 188679247;
	inverse[54] = 648148154;
	inverse[55] = 472727277;
	inverse[56] = 982142866;
	inverse[57] = 456140355;
	inverse[58] = 258620692;
	inverse[59] = 389830512;
	inverse[60] = 183333335;
	inverse[61] = 786885253;
	inverse[62] = 919354847;
	inverse[63] = 984126993;
	inverse[64] = 109375001;
	inverse[65] = 323076926;
	inverse[66] = 893939402;
	inverse[67] = 388059705;
	inverse[68] = 514705887;
	inverse[69] = 942028994;
	inverse[70] = 585714291;
	inverse[71] = 915492966;
	inverse[72] = 986111120;
	inverse[73] = 315068496;
	inverse[74] = 148648650;
	inverse[75] = 146666668;
	inverse[76] = 92105264;
	inverse[77] = 623376629;
	inverse[78] = 602564108;
	inverse[79] = 670886082;
	inverse[80] = 887500008;
	inverse[81] = 98765433;
	inverse[82] = 597560981;
	inverse[83] = 301204822;
	inverse[84] = 988095247;
	inverse[85] = 11764706;
	inverse[86] = 569767447;
	inverse[87] = 505747131;
	inverse[88] = 170454547;
	inverse[89] = 213483148;
	inverse[90] = 788888896;
	inverse[91] = 373626377;
	inverse[92] = 206521741;
	inverse[93] = 279569895;
	inverse[94] = 670212772;
	inverse[95] = 273684213;
	inverse[96] = 739583340;
	inverse[97] = 92783506;
	inverse[98] = 704081639;
	inverse[99] = 262626265;
	inverse[100] = 110000001;
	inverse[101] = 841584166;
	inverse[102] = 343137258;
	inverse[103] = 601941753;
	inverse[104] = 451923081;
	inverse[105] = 390476194;
	inverse[106] = 594339628;
	inverse[107] = 803738325;
	inverse[108] = 324074077;
	inverse[109] = 990825697;
	inverse[110] = 736363643;
	inverse[111] = 99099100;
	inverse[112] = 491071433;
	inverse[113] = 955752221;
	inverse[114] = 728070182;
	inverse[115] = 965217400;
	inverse[116] = 129310346;
	inverse[117] = 68376069;
	inverse[118] = 194915256;
	inverse[119] = 579831938;
	inverse[120] = 591666672;
	inverse[121] = 214876035;
	inverse[122] = 893442631;
	inverse[123] = 65040651;
	inverse[124] = 959677428;
	inverse[125] = 888000008;
	inverse[126] = 992063501;
	inverse[127] = 913385835;
	inverse[128] = 554687505;
	inverse[129] = 713178301;
	inverse[130] = 161538463;
	inverse[131] = 526717562;
	inverse[132] = 446969701;
	inverse[133] = 624060156;
	inverse[134] = 694029857;
	inverse[135] = 859259267;
	inverse[136] = 757352948;
	inverse[137] = 262773725;
	inverse[138] = 471014497;
	inverse[139] = 978417275;
	inverse[140] = 792857150;
	inverse[141] = 780141851;
	inverse[142] = 457746483;
	inverse[143] = 874125882;
	inverse[144] = 493055560;
	inverse[145] = 903448284;
	inverse[146] = 157534248;
	inverse[147] = 136054423;
	inverse[148] = 74324325;
	inverse[149] = 308724835;
	inverse[150] = 73333334;
	inverse[151] = 913907293;
	inverse[152] = 46052632;
	inverse[153] = 228758172;
	inverse[154] = 811688319;
	inverse[155] = 167741937;
	inverse[156] = 301282054;
	inverse[157] = 566878986;
	inverse[158] = 335443041;
	inverse[159] = 729559755;
	inverse[160] = 443750004;
	inverse[161] = 689441000;
	inverse[162] = 549382721;
	inverse[163] = 564417183;
	inverse[164] = 798780495;
	inverse[165] = 157575759;
	inverse[166] = 150602411;
	inverse[167] = 994011985;
	inverse[168] = 994047628;
	inverse[169] = 355029589;
	inverse[170] = 5882353;
	inverse[171] = 152046785;
	inverse[172] = 784883728;
	inverse[173] = 682080931;
	inverse[174] = 752873570;
	inverse[175] = 634285720;
	inverse[176] = 585227278;
	inverse[177] = 129943504;
	inverse[178] = 106741574;
	inverse[179] = 268156427;
	inverse[180] = 394444448;
	inverse[181] = 77348067;
	inverse[182] = 686813193;
	inverse[183] = 928961757;
	inverse[184] = 603260875;
	inverse[185] = 59459460;
	inverse[186] = 639784952;
	inverse[187] = 550802144;
	inverse[188] = 335106386;
	inverse[189] = 328042331;
	inverse[190] = 636842111;
	inverse[191] = 518324612;
	inverse[192] = 369791670;
	inverse[193] = 341968915;
	inverse[194] = 46391753;
	inverse[195] = 441025645;
	inverse[196] = 852040824;
	inverse[197] = 228426398;
	inverse[198] = 631313137;
	inverse[199] = 246231158;
	inverse[200] = 555000005;
	inverse[201] = 129353235;
	inverse[202] = 420792083;
	inverse[203] = 788177347;
	inverse[204] = 171568629;
	inverse[205] = 639024396;
	inverse[206] = 800970881;
	inverse[207] = 647343001;
	inverse[208] = 725961545;
	inverse[209] = 124401915;
	inverse[210] = 195238097;
	inverse[211] = 132701423;
	inverse[212] = 297169814;
	inverse[213] = 305164322;
	inverse[214] = 901869167;
	inverse[215] = 27906977;
	inverse[216] = 662037043;
	inverse[217] = 834101390;
	inverse[218] = 995412853;
	inverse[219] = 105022832;
	inverse[220] = 868181826;
	inverse[221] = 389140275;
	inverse[222] = 49549550;
	inverse[223] = 834080725;
	inverse[224] = 745535721;
	inverse[225] = 715555562;
	inverse[226] = 977876115;
	inverse[227] = 264317183;
	inverse[228] = 364035091;
	inverse[229] = 65502184;
	inverse[230] = 482608700;
	inverse[231] = 541125546;
	inverse[232] = 64655173;
	inverse[233] = 266094423;
	inverse[234] = 534188039;
	inverse[235] = 68085107;
	inverse[236] = 97457628;
	inverse[237] = 223628694;
	inverse[238] = 289915969;
	inverse[239] = 238493726;
	inverse[240] = 295833336;
	inverse[241] = 269709546;
	inverse[242] = 607438022;
	inverse[243] = 32921811;
	inverse[244] = 946721320;
	inverse[245] = 881632661;
	inverse[246] = 532520330;
	inverse[247] = 874493935;
	inverse[248] = 479838714;
	inverse[249] = 767068280;
	inverse[250] = 444000004;
	inverse[251] = 709163353;
	inverse[252] = 996031755;
	inverse[253] = 711462457;
	inverse[254] = 956692922;
	inverse[255] = 337254905;
	inverse[256] = 777343757;
	inverse[257] = 540856036;
	inverse[258] = 856589155;
	inverse[259] = 185328187;
	inverse[260] = 580769236;
	inverse[261] = 168582377;
	inverse[262] = 263358781;
	inverse[263] = 745247155;
	inverse[264] = 723484855;
	inverse[265] = 437735853;
	inverse[266] = 312030078;
	inverse[267] = 737827722;
	inverse[268] = 847014933;
	inverse[269] = 609665433;
	inverse[270] = 929629638;
	inverse[271] = 944649455;
	inverse[272] = 378676474;
	inverse[273] = 457875462;
	inverse[274] = 631386867;
	inverse[275] = 494545459;
	inverse[276] = 735507253;
	inverse[277] = 494584842;
	inverse[278] = 989208642;
	inverse[279] = 93189965;
	inverse[280] = 396428575;
	inverse[281] = 633451963;
	inverse[282] = 890070930;
	inverse[283] = 611307426;
	inverse[284] = 728873246;
	inverse[285] = 91228071;
	inverse[286] = 437062941;
	inverse[287] = 313588853;
	inverse[288] = 246527780;
	inverse[289] = 650519037;
	inverse[290] = 451724142;
	inverse[291] = 697594508;
	inverse[292] = 78767124;
	inverse[293] = 706484648;
	inverse[294] = 568027216;
	inverse[295] = 477966106;
	inverse[296] = 537162167;
	inverse[297] = 754208761;
	inverse[298] = 654362422;
	inverse[299] = 678929772;
	inverse[300] = 36666667;
	inverse[301] = 19933555;
	inverse[302] = 956953651;
	inverse[303] = 947194728;
	inverse[304] = 23026316;
	inverse[305] = 757377056;
	inverse[306] = 114379086;
	inverse[307] = 166123780;
	inverse[308] = 905844164;
	inverse[309] = 200647251;
	inverse[310] = 583870973;
	inverse[311] = 742765280;
	inverse[312] = 150641027;
	inverse[313] = 415335467;
	inverse[314] = 283439493;
	inverse[315] = 796825404;
	inverse[316] = 667721525;
	inverse[317] = 274447952;
	inverse[318] = 864779882;
	inverse[319] = 47021944;
	inverse[320] = 221875002;
	inverse[321] = 267912775;
	inverse[322] = 344720500;
	inverse[323] = 845201246;
	inverse[324] = 774691365;
	inverse[325] = 264615387;
	inverse[326] = 782208596;
	inverse[327] = 996941905;
	inverse[328] = 899390252;
	inverse[329] = 762917940;
	inverse[330] = 578787884;
	inverse[331] = 190332328;
	inverse[332] = 575301210;
	inverse[333] = 699699706;
	inverse[334] = 997005997;
	inverse[335] = 77611941;
	inverse[336] = 497023814;
	inverse[337] = 961424341;
	inverse[338] = 677514799;
	inverse[339] = 651917410;
	inverse[340] = 502941181;
	inverse[341] = 76246335;
	inverse[342] = 576023397;
	inverse[343] = 629737615;
	inverse[344] = 392441864;
	inverse[345] = 988405806;
	inverse[346] = 841040470;
	inverse[347] = 907780988;
	inverse[348] = 376436785;
	inverse[349] = 962750725;
	inverse[350] = 317142860;
	inverse[351] = 22792023;
	inverse[352] = 292613639;
	inverse[353] = 592067994;
	inverse[354] = 64971752;
	inverse[355] = 383098595;
	inverse[356] = 53370787;
	inverse[357] = 526610649;
	inverse[358] = 634078218;
	inverse[359] = 153203344;
	inverse[360] = 197222224;
	inverse[361] = 282548479;
	inverse[362] = 538674038;
	inverse[363] = 71625345;
	inverse[364] = 843406601;
	inverse[365] = 263013701;
	inverse[366] = 964480883;
	inverse[367] = 504087198;
	inverse[368] = 801630442;
	inverse[369] = 21680217;
	inverse[370] = 29729730;
	inverse[371] = 884097043;
	inverse[372] = 319892476;
	inverse[373] = 453083114;
	inverse[374] = 275401072;
	inverse[375] = 629333339;
	inverse[376] = 167553193;
	inverse[377] = 193633954;
	inverse[378] = 664021170;
	inverse[379] = 216358841;
	inverse[380] = 818421060;
	inverse[381] = 304461945;
	inverse[382] = 259162306;
	inverse[383] = 548302877;
	inverse[384] = 184895835;
	inverse[385] = 924675333;
	inverse[386] = 670984462;
	inverse[387] = 904392773;
	inverse[388] = 523195881;
	inverse[389] = 511568128;
	inverse[390] = 720512827;
	inverse[391] = 872122770;
	inverse[392] = 426020412;
	inverse[393] = 508905857;
	inverse[394] = 114213199;
	inverse[395] = 534177220;
	inverse[396] = 815656573;
	inverse[397] = 365239298;
	inverse[398] = 123115579;
	inverse[399] = 208020052;
	inverse[400] = 777500007;
	inverse[401] = 528678309;
	inverse[402] = 564676622;
	inverse[403] = 987593061;
	inverse[404] = 710396046;
	inverse[405] = 619753092;
	inverse[406] = 894088678;
	inverse[407] = 117936119;
	inverse[408] = 585784319;
	inverse[409] = 168704158;
	inverse[410] = 319512198;
	inverse[411] = 420924578;
	inverse[412] = 900485445;
	inverse[413] = 912832938;
	inverse[414] = 823671505;
	inverse[415] = 460240968;
	inverse[416] = 862980777;
	inverse[417] = 659472428;
	inverse[418] = 562200962;
	inverse[419] = 517899766;
	inverse[420] = 597619053;
	inverse[421] = 964370555;
	inverse[422] = 566350716;
	inverse[423] = 593380620;
	inverse[424] = 148584907;
	inverse[425] = 202352943;
	inverse[426] = 152582161;
	inverse[427] = 112412179;
	inverse[428] = 950934588;
	inverse[429] = 291375294;
	inverse[430] = 513953493;
	inverse[431] = 675174020;
	inverse[432] = 831018526;
	inverse[433] = 279445730;
	inverse[434] = 417050695;
	inverse[435] = 301149428;
	inverse[436] = 997706431;
	inverse[437] = 885583532;
	inverse[438] = 52511416;
	inverse[439] = 849658322;
	inverse[440] = 434090913;
	inverse[441] = 712018147;
	inverse[442] = 694570142;
	inverse[443] = 24830700;
	inverse[444] = 24774775;
	inverse[445] = 642696635;
	inverse[446] = 917040367;
	inverse[447] = 769574951;
	inverse[448] = 872767865;
	inverse[449] = 908685977;
	inverse[450] = 357777781;
	inverse[451] = 472283818;
	inverse[452] = 988938062;
	inverse[453] = 971302437;
	inverse[454] = 632158596;
	inverse[455] = 474725279;
	inverse[456] = 682017550;
	inverse[457] = 177242890;
	inverse[458] = 32751092;
	inverse[459] = 76252724;
	inverse[460] = 241304350;
	inverse[461] = 26030369;
	inverse[462] = 270562773;
	inverse[463] = 64794817;
	inverse[464] = 532327591;
	inverse[465] = 55913979;
	inverse[466] = 633047216;
	inverse[467] = 676659535;
	inverse[468] = 767094024;
	inverse[469] = 341151389;
	inverse[470] = 534042558;
	inverse[471] = 188959662;
	inverse[472] = 48728814;
	inverse[473] = 194503173;
	inverse[474] = 111814347;
	inverse[475] = 654736848;
	inverse[476] = 644957989;
	inverse[477] = 243186585;
	inverse[478] = 119246863;
	inverse[479] = 628392490;
	inverse[480] = 147916668;
	inverse[481] = 638253644;
	inverse[482] = 134854773;
	inverse[483] = 563147003;
	inverse[484] = 303719011;
	inverse[485] = 218556703;
	inverse[486] = 516460910;
	inverse[487] = 301848052;
	inverse[488] = 473360660;
	inverse[489] = 188139061;
	inverse[490] = 940816335;
	inverse[491] = 843177197;
	inverse[492] = 266260165;
	inverse[493] = 795131853;
	inverse[494] = 937246972;
	inverse[495] = 52525253;
	inverse[496] = 239919357;
	inverse[497] = 702213286;
	inverse[498] = 383534140;
	inverse[499] = 176352707;
	inverse[500] = 222000002;
	inverse[501] = 998004001;
	inverse[502] = 854581681;
	inverse[503] = 483101396;
	inverse[504] = 998015882;
	inverse[505] = 368316835;
	inverse[506] = 855731233;
	inverse[507] = 785009869;
	inverse[508] = 478346461;
	inverse[509] = 49115914;
	inverse[510] = 668627457;
	inverse[511] = 902152650;
	inverse[512] = 888671883;
	inverse[513] = 384015598;
	inverse[514] = 270428018;
	inverse[515] = 720388356;
	inverse[516] = 928294582;
	inverse[517] = 667311418;
	inverse[518] = 592664098;
	inverse[519] = 894026983;
	inverse[520] = 290384618;
	inverse[521] = 360844533;
	inverse[522] = 584291193;
	inverse[523] = 938814540;
	inverse[524] = 631679395;
	inverse[525] = 878095246;
	inverse[526] = 872623582;
	inverse[527] = 872865283;
	inverse[528] = 861742432;
	inverse[529] = 948960311;
	inverse[530] = 718867931;
	inverse[531] = 709981174;
	inverse[532] = 156015039;
	inverse[533] = 15009381;
	inverse[534] = 368913861;
	inverse[535] = 160747665;
	inverse[536] = 923507471;
	inverse[537] = 422718812;
	inverse[538] = 804832721;
	inverse[539] = 946196669;
	inverse[540] = 464814819;
	inverse[541] = 737523112;
	inverse[542] = 972324732;
	inverse[543] = 25782689;
	inverse[544] = 189338237;
	inverse[545] = 598165143;
	inverse[546] = 228937731;
	inverse[547] = 78610604;
	inverse[548] = 815693438;
	inverse[549] = 309653919;
	inverse[550] = 747272734;
	inverse[551] = 185117969;
	inverse[552] = 867753631;
	inverse[553] = 238698013;
	inverse[554] = 247292421;
	inverse[555] = 19819820;
	inverse[556] = 494604321;
	inverse[557] = 447037706;
	inverse[558] = 546594987;
	inverse[559] = 549194996;
	inverse[560] = 698214292;
	inverse[561] = 516934051;
	inverse[562] = 816725986;
	inverse[563] = 321492010;
	inverse[564] = 445035465;
	inverse[565] = 391150446;
	inverse[566] = 305653713;
	inverse[567] = 442680780;
	inverse[568] = 364436623;
	inverse[569] = 304042182;
	inverse[570] = 545614040;
	inverse[571] = 996497382;
	inverse[572] = 718531475;
	inverse[573] = 506108207;
	inverse[574] = 656794431;
	inverse[575] = 193043480;
	inverse[576] = 123263890;
	inverse[577] = 116117852;
	inverse[578] = 825259523;
	inverse[579] = 780656311;
	inverse[580] = 225862071;
	inverse[581] = 757314981;
	inverse[582] = 348797254;
	inverse[583] = 289879934;
	inverse[584] = 39383562;
	inverse[585] = 813675221;
	inverse[586] = 353242324;
	inverse[587] = 848381609;
	inverse[588] = 284013608;
	inverse[589] = 44142615;
	inverse[590] = 238983053;
	inverse[591] = 409475469;
	inverse[592] = 768581088;
	inverse[593] = 210792582;
	inverse[594] = 877104385;
	inverse[595] = 715966393;
	inverse[596] = 327181211;
	inverse[597] = 415410389;
	inverse[598] = 339464886;
	inverse[599] = 948247087;
	inverse[600] = 518333338;

	freopen("C-large.in", "rt", stdin);
	freopen("C-large.out", "wt", stdout);
	int nTest;
	scanf("%d", &nTest);
	for (int iTest = 1; iTest <= nTest; iTest++)
		printf("Case #%d: %d\n", iTest, solve());
	return 0;
}
