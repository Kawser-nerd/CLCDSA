using System;
using System.Linq;

namespace abc023_c
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			int[] candya = new int[x[0]]; int[] candyb = new int[x[1]];
			int n = int.Parse(Console.ReadLine());
			Tuple<int, int>[] where = new Tuple<int, int>[n];
			for (int i = 0; i < n; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				a[0]--; a[1]--;
				candya[a[0]]++; candyb[a[1]]++;
				where[i] = new Tuple<int, int>(a[0], a[1]);
			}
			long[] c = new long[200000];
			for (int i = 0; i < x[0]; i++) c[candya[i]]++;
			long[] d = new long[200000];
			for (int i = 0; i < x[1]; i++) d[candyb[i]]++;
			long ret = 0;
			for (int i = 0; i <= x[2]; i++)
			{
				ret += c[i] * d[x[2] - i];
			}
			for (int i = 0; i < n; i++)
			{
				if (candya[where[i].Item1] + candyb[where[i].Item2] == x[2])
					ret--;
				if (candya[where[i].Item1] + candyb[where[i].Item2] == x[2] + 1)
					ret++;
			}
			Console.WriteLine(ret);
		}
	}
}