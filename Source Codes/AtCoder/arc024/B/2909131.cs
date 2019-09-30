using System;

namespace arc024_2
{
	class Program
	{
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			int[] tree = new int[n * 2];
			for (int i = 0; i < n; i++)
			{
				int a = int.Parse(Console.ReadLine());
				tree[i] = a; tree[i + n] = a;
			}
			int back = -1; int count = 1; int ret = 0;
			for (int i = 0; i < tree.Length; i++)
			{
				if (back == tree[i]) count++;
				else
				{
					ret = Math.Max(ret, (count - 1) / 2);
					count = 1;
				}
				back = tree[i];
			}
			ret = Math.Max(ret, (count - 1) / 2);
			Console.WriteLine(ret >= n - 1 ? -1 : ret + 1);
		}
	}
}