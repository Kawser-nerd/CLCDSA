using System;
using System.Collections.Generic;
using System.Linq;

namespace AIZU
{
	class Program
	{
		#region Reserve
		static int cin() { return cin(-1); }
		static int cin(int D)
		{
			string s = Console.ReadLine();
			if (string.IsNullOrEmpty(s))
				return D;
			return int.Parse(s);
		}
		static long[] cins(char spliter)
		{
			string s = Console.ReadLine();
			if (string.IsNullOrEmpty(s))
				return new long[] { };
			string[] ss = s.Split(spliter);
			long[] Res = new long[ss.Length];
			long g;
			for (int i = 0; i < ss.Length; i++) {
				if (long.TryParse(ss[i], out g))
					Res[i] = g;
			}
			return Res;
		}
		static long[] cins() { return cins(' '); }
		static void print(object j) { Console.WriteLine(j.ToString()); }
		static void print(string j) { Console.WriteLine(j); }
		#endregion
		static long[] decs = new long[20];  //for 0 to 10^(i+1)-1
		static void Main(string[] args)
		{
			decs[0] = 0;
			decs[1] = 2;
			for (int i = 0; i < 19; i++) decs[i + 1] = 
					decs[i]*8+2*(long)Math.Pow(10,i);

			long[] I = cins();

			print(Neglect(I[1])-Neglect(I[0]-1));
			Console.ReadLine();
		}

		static long Neglect(long x) {
			int keta = x.ToString().Length;
			long Res = 0;
			for (int i = keta; i >=0; i--) {
				long D = (long)Math.Pow(10, i);
				long x1 = x / D;
				switch (x1) {
					case 4:
						Res += 4*decs[i]+ 1L+ x %D;
						goto HJ;
					case 9:
						Res +=8*decs[i]+D+ 1L + x % D;
						goto HJ;
					default:
						Res += (x1 + (x1>4?-1:0)) * decs[i] + (x1>4?D:0);
						break;
				}
				x %=D;
			}
			HJ:
			return Res;
		}

	}
}