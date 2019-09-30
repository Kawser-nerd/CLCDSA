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
		static void OutB(bool b) => Out(b ? "YES" : "NO");

		static void Main(string[] args)
		{
			var inp = RIs;
			var N = inp[0];
			var K = inp[1];
			long ans = 0;
			if (K == 0) ans = (long)N * N;
			else
			{
				for (int i = K; i <= N; i++)
				{
					ans += Math.Max(((N + 1) % i) - K, 0);
					ans += (((N + 1) - ((N + 1) % i)) / i) * (i - K);

				}
			}
			Out(ans);
		}
	}
}