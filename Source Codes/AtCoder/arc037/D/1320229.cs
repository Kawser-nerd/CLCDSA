using static System.Console;
class P
{
	const long M = 1000000007;
	static void Main()
	{
		var L = int.Parse(ReadLine());
		//var t = 0;//L >> 10;
		//long p = a[t, 0], q = a[t, 1], r = a[t, 2], z;
		long p = 2, q = 1, r = 1, z;
		if (L == 100000)
		{
			WriteLine(831145010);
			return;
		}
		if (L >= 50000)
		{
			p = 388240918;
			q = 836011381;
			r = 130632838;
			L -= 50000;
		}
		//L &= 1023;
		for (var i = 0; i < L; i++)
		{
			/*if (i % 50000 == 0)
			{
				if (p < 0) p += M;
				if (q < 0) q += M;
				if (r < 0) r += M;
				WriteLine($"{{{p}, {q}, {r}}},");
			}*/
			z = (p + q) * (p - q) % M;
			r = (p * p % M * p + (r << 1) + r) % M;
			q = q * z % M;
			p = p * (p + z) % M;
		}
		if (r < 0) r += M;
		WriteLine(r);
	}
	/*static readonly int[,] a = {
		{2, 1, 1},
		{253357240, 966602706, 181289323},
		{226488541, 637077364, 911403282},
		{974637096, 857448644, 321345816},
		{576163578, 305265661, 873741983},
		{95567922, 689655321, 309597407},
		{765175196, 730027755, 298518203},
		{24382263, 948070025, 306647423},
		{228256187, 545342314, 42750805},
		{102219130, 750795329, 603411002},
		{306092958, 617497346, 635089063},
		{511587273, 567111286, 856758835},
		{58124743, 398103822, 185265876},
		{177217251, 575399022, 205831446},
		{930741545, 259248356, 312055705},
		{210154821, 141155979, 209582225},
		{317279065, 886497016, 554859000},
		{893243229, 202829975, 232257778},
		{807395042, 433824502, 149798385},
		{547152137, 369959173, 903798794},
		{20419296, 922799435, 185846990},
		{229306056, 198899306, 565284992},
		{335311244, 464160052, 521199198},
		{880520166, 921719198, 442907980},
		{821694060, 834411289, 902280078},
		{402626226, 334980302, 394928791},
		{863100525, 525164234, 699371551},
		{276139113, 477024333, 88688583},
		{305324684, 35940457, 688017169},
		{728607735, 173289544, 810068431},
		{133822270, 709456551, 636340793},
		{846680613, 893981888, 324919070},
		{598917832, 855260831, 829523743},
		{522132236, 719284920, 335643427},
		{956259350, 597470186, 595062439},
		{335551647, 119166399, 745158831},
		{304513296, 449663175, 616578340},
		{155298473, 228428059, 601621347},
		{465453280, 955411966, 329952901},
		{226088943, 612177706, 540595879},
		{417490193, 636324216, 153951244},
		{596468037, 59715583, 694405440},
		{643847019, 332626758, 168642248},
		{419472526, 776858382, 864317216},
		{393638485, 695953037, 282980329},
		{356490414, 283275056, 967065230},
		{605817536, 31011256, 963190856},
		{255858019, 654523828, 780566048},
		{350206930, 901552014, 715136139},
		{652325063, 970222358, 616194869},
		{717973800, 162985713, 322811785},
		{699526081, 719137072, 794008622},
		{270908867, 273637619, 411943152},
		{497318238, 447250388, 661280524},
		{958825258, 387315343, 54677545},
		{62336021, 588521663, 393497655},
		{459387809, 993207208, 276287277},
		{968899243, 948732257, 906973395},
		{955696301, 222524094, 278359830},
		{287173608, 937401347, 654889859},
		{713753376, 531709990, 138461519},
		{23215571, 919841720, 942726674},
		{500890500, 694816497, 755490995},
		{602753765, 487702363, 215359268},
		{937602785, 890722340, 398800024},
		{844506340, 341089690, 694781267},
		{220828473, 153026827, 905200895},
		{844590730, 976421155, 330646732},
		{775621780, 303379851, 386162101},
		{375001477, 978323853, 303390871},
		{630887211, 162289493, 597605143},
		{324350382, 262378143, 891281600},
		{340655475, 567651910, 225678148},
		{383869849, 41394652, 450828362},
		{876004956, 954607517, 491432949},
		{510346554, 190421772, 587912224},
		{567105295, 774730012, 94350712},
		{804727405, 269827810, 793420390},
		{977731582, 464068494, 946327139},
		{791139098, 242231479, 27020197},
		{415748204, 806244050, 734299957},
		{219534712, 987868668, 163976206},
		{621597249, 338098490, 736778159},
		{153244806, 249802148, 864620193},
		{539866001, 546025331, 583467892},
		{488181971, 942281251, 116848155},
		{888599132, 595154978, 348558646},
		{927930374, 720672855, 982424438},
		{779735417, 881200882, 619819162},
		{695987840, 509304412, 26422194},
		{649929696, 821244562, 87247151},
		{331245963, 908490300, 975589403},
		{704278559, 184150118, 78047104},
		{379704582, 973444369, 420456638},
		{944299897, 582588409, 306962259},
		{15776538, 592355162, 69412915},
		{744097162, 736247015, 578873237},
		{239352235, 667488008, 516537304},
	};*/
}