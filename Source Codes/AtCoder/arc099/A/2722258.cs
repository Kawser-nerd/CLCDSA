using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CompetitiveProgCsLib
{
	class MainProg
	{
		static string R => Console.ReadLine();
		static int RI => int.Parse(R);
		static double RD => double.Parse(R);
		static int[] RIs => R.Split(' ').Select(int.Parse).ToArray();
		static double[] RDs => R.Split(' ').Select(double.Parse).ToArray();
		static void Out(object obj) => Console.WriteLine(obj);
		static void OutLine<T>(IEnumerable<T> obj, string separateChar) => Out(String.Join(separateChar, obj));
		static void Outb(bool b) => Out(b ? "Yes" : "No");
		static void OutB(bool b) => Out(b ? "YES" : "NO");
		static bool IsIn(int y, int x, int h, int w) => 0 <= x && x < w && 0 <= y && y < h;

		static void Main(string[] args)
		{
			var nk = RIs;
			var a = RIs;
			var k = nk[1];
			var n = nk[0];

			var ans = (int)Math.Ceiling((double)(n - 1 ) / (k - 1));
			Out(ans);
		}
	}
}