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
			var input = RIs;
			int ans = 0;
			for(;!same(input);ans++)
			{
				var a = input.Min();
				var b = input.Max();
				var c = input.Count(x => x == a);
				for(int j = 0;j < input.Length;j++ )
				{
					if(a == input[j])
					{
						if (b - a == 1 && c == 2) input[j]++;
						else
						{
							input[j] += 2;
							goto NEXT;
						}
					}
				}
				NEXT:;
			}
			Out(ans);
		}

		static bool same(int[] arg)
		{
			return arg[0] == arg[1] && arg[1] == arg[2];
		}
	}
}