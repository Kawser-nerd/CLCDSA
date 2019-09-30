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
			li.Sort();
			li.Reverse();
			int n = 0;
			int k = 0;
			//for(int i = 0;i < N;i++)
			{
				var m = li[0];
				var mid = m / 2.0;
				var mm = double.MaxValue;
				int n1 = 0;
				int k1 = 0;
				for(int j = 0 + 1;j < N;j++)
				{
					if(Math.Abs(mid - li[j]) < mm)
					{
						mm = Math.Abs(mid - li[j]);
						n1 = m;
						k1 = li[j];
					}
				}
				n = n1;
				k = k1;
			}
			Out(n + " " + k);
		}
		
	}
}