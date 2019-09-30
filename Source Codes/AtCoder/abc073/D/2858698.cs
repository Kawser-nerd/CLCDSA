using System;
using System.Linq;

namespace abc073_d
{
	class Program
	{
		static int[,] d;
		static int[] r;
		static bool[] flag;
		const int inf = 100000000;
		static int bfs(int x)
		{
			flag[x] = true;
			int min = inf;
			bool found = false;
			for (int i = 0; i < flag.Count(); i++)
			{
				if (!flag[i])
				{
					found = true;
					min = Math.Min(min, d[r[x], r[i]] + bfs(i));
				}
			}
			flag[x] = false;
			return found ? min : 0;
		}
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			r = Console.ReadLine().Split().Select(int.Parse).ToArray();
			for (int i = 0; i < x[2]; i++) r[i]--;
			flag = new bool[x[2]];
			d = new int[x[0], x[0]];
			for (int i = 0; i < x[0]; i++)
			{
				for (int j = 0; j < x[0]; j++)
				{
					d[i, j] = inf;
				}
			}
			for (int i = 0; i < x[1]; i++)
			{
				int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
				a[0]--; a[1]--;
				d[a[0], a[1]] = a[2]; d[a[1], a[0]] = a[2];
			}
			for (int k = 0; k < x[0]; k++)
			{
				for (int i = 0; i < x[0]; i++)
				{
					for (int j = 0; j < x[0]; j++)
					{
						d[i, j] = Math.Min(d[i, j], d[i, k] + d[k, j]);
					}
				}
			}
			long ret = long.MaxValue;
			for (int i = 0; i < x[2]; i++)
			{
				ret = Math.Min(ret, bfs(i));
			}
			Console.WriteLine(ret);
		}
	}
}