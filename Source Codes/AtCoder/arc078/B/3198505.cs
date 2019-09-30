using System;
using System.Collections.Generic;
using System.Linq;

namespace arc078_b
{
	class Program
	{
		public static List<int>[] list;
		public static int[] f, s;
		static void bfs(int x, int len, bool flag)
		{
			if (flag)//fennec
			{
				f[x] = len;
				foreach (var item in list[x])
				{
					if (f[item] < 0) bfs(item, len + 1, flag);
				}
			}
			else//snuke
			{
				s[x] = len;
				foreach (var item in list[x])
				{
					if (s[item] < 0) bfs(item, len + 1, flag);
				}
			}
		}
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			list = new List<int>[n];
			for (int i = 0; i < n; i++) list[i] = new List<int>();
			for (int i = 0; i < n - 1; i++)
			{
				int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
				x[0]--; x[1]--;
				list[x[0]].Add(x[1]); list[x[1]].Add(x[0]);
			}
			f = new int[n]; for (int i = 0; i < n; i++) f[i] = -1; bfs(0, 0, true);
			s = new int[n]; for (int i = 0; i < n; i++) s[i] = -1; bfs(n - 1, 0, false);
			int ret = 0;
			for (int i = 0; i < n; i++)
			{
				ret += f[i] <= s[i] ? 1 : -1;
			}
			Console.WriteLine(ret > 0 ? "Fennec" : "Snuke");
		}
	}
}