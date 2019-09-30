using System;
using System.Linq;

namespace arc098_b
{
	class Program
	{
		static void Main(string[] args)
		{
			int n = int.Parse(Console.ReadLine());
			long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
			long ret = 0; long now = 0; int j = 0;
			for (int i = 0; i < n; i++)
			{
				while (j < n && (now & x[j]) == 0)
				{
					now ^= x[j];
					j++;
				}
				ret += j - i;
				now ^= x[i];
			}
			Console.WriteLine(ret);
		}
	}
}