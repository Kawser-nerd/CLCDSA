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
			var a = RIs;
			long count = 0;
			long cc = 0;
			int max = (int)Math.Pow(2, Math.Ceiling(Math.Log(a.Max(), 2) + 0.01));
			for(int i = n-1;i >= 0;i--)
			{
				long x = a[i];
				long s = a[i];
				if(a[i] == 0)
				{
					cc++;
					count += cc;
					continue;
				}
				cc = 1;
				for(int j = i + 1;j < n;j++)
				{
					x ^= a[j];
					s += a[j];
					if (x == s)
					{
						cc++;
					}
					if (s > max) break;
				}
				count += cc;
			}
			Out(count);
		}		
	}
}