using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;


class Program {

	const long mod = 1000000007;
	//public static int[] max;

	static public  List<int> va=new List<int>();
	static void Main(string[] args) {

		char[] cs = new char[] { ' ', ',' };
		//int val = int.Parse(Console.ReadLine());
		//int[] vals = parseAry(Console.ReadLine().Split(cs));
		//string str = Console.ReadLine();
		//string[] strs = Console.ReadLine().Split(cs);

		//string res="";
		//int res = 0; ;
		//int t = int.Parse(Console.ReadLine());
		//string str = Console.ReadLine();
		///int[] vals = parseAry(Console.ReadLine().Split(cs));
		//int n = int.Parse(Console.ReadLine());

		//int num = vals[0];

		int res = 0;
		int n = int.Parse(Console.ReadLine());
		int[] vals = parseAry(Console.ReadLine().Split(cs));

		Array.Sort(vals);
		va = new List<int>(vals);

		while ( va.Count > 0 ) {
			if ( va.Count <= 1 ) { break; }

			int v = va[va.Count-1];
			va.RemoveAt(va.Count - 1);
			int x = v;
			int c = -1;
			if (v == 0) {return;};
    v |= (v >> 1);
    v |= (v >> 2);
    v |= (v >> 4);
    v |= (v >> 8);

    v |= (v >> 16);
			c=(int)numofbits5(v);

			int find = (1<<(int)c) - x;
			int k = Binary_SearchX(find);
			if ( k != -1 ) {
				va.RemoveAt(k);
				res++;
			}
		}
			Console.WriteLine(res);

		return;
	}
	static long numofbits5(long bits) {
		bits = ( bits & 0x55555555 ) + ( bits >> 1 & 0x55555555 );
		bits = ( bits & 0x33333333 ) + ( bits >> 2 & 0x33333333 );
		bits = ( bits & 0x0f0f0f0f ) + ( bits >> 4 & 0x0f0f0f0f );
		bits = ( bits & 0x00ff00ff ) + ( bits >> 8 & 0x00ff00ff );
		return ( bits & 0x0000ffff ) + ( bits >> 16 & 0x0000ffff );
	}


	//?String[]  ----->  int[]
	static int[] parseAry(string[] str) {
		int[] nums = new int[str.Length];
		for ( int i = 0; i < str.Length; i++ ) { nums[i] = int.Parse(str[i]); }
		return nums;
	}
	//?String[]  ----->  long[]
	static long[] parseAryL(string[] str) {
		long[] nums = new long[str.Length];
		for ( int i = 0; i < str.Length; i++ ) { nums[i] = long.Parse(str[i]); }
		return nums;
	}

	//????1????String[]????
	static string[] strAry(String str) {
		string[] re = new string[str.Length];
		for ( int i = 0; i < str.Length; i++ ) { re[i] = str[i].ToString(); }
		return re;
	}

	static public int Binary_SearchX(int x) {
		int Lower = 0;
		int Upper = va.Count - 1;
		while ( Lower <= Upper ) {
			int Center = ( Lower + Upper ) >> 1;
			if ( x > va[(int)Center] ) {
				Lower = Center + 1;
			} else if ( x < va[(int)Center] ) {
				Upper = Center - 1;
			} else {
				return (int)Center;
			}
		}
		return -1;
	}
}