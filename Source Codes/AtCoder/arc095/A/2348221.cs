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
		static void Outb(bool b) => Out(b ? "Yes" : "No");
		static void OutB(bool b) => Out(b ? "YES": "NO");

		static void Main(string[] args)
		{
			var N = RI;
			var x = RIs;
			var li = new List<int>(x);
			Array.Sort(x);
			for(int i = 0;i < N;i++)
			{
				if (li[i] < x[N / 2]) Out(x[N / 2]);
				else Out(x[N / 2 - 1]);
			}
		}
	}
}