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
			var n = RI;
			var s = R;
			int[] w = { 0, 0 };
			int[] e = { 0, 0 };
			for(int i = 0;i < n;i++)
			{
				if (s[i] == 'W') w[0]++;
				else e[0]++;
			}
			int min = int.MaxValue;
			for (int i = 0; i < n; i++)
			{
				if (s[i] == 'E')
				{
					min = Math.Min(min, w[1] + e[0] - 1);
					e[0]--;
					e[1]++;
				}
				else
				{
					min = Math.Min(min, w[1] + e[0]);
					w[0]--;
					w[1]++;
				}
			}
			Out(min);
		}		
	}
}