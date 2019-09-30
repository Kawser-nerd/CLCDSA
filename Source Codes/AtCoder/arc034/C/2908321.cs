using System;
using System.Collections.Generic;
using System.Linq;

namespace arc034_3
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
			Dictionary<int, int> primecount = new Dictionary<int, int>();
			for (int i = x[1] + 1; i <= x[0]; i++)
			{
				int a = i;
				for (int j = 2; j < Math.Sqrt(a) + 10; j++)
				{
					while (a % j == 0)
					{
						if (!primecount.ContainsKey(j)) primecount[j] = 0;
						primecount[j]++;
						a /= j;
					}
				}
				if (a > 1)
				{
					if (!primecount.ContainsKey(a)) primecount[a] = 0;
					primecount[a]++;
				}
			}
			long ret = 1;
			foreach(var item in primecount)
			{
				ret *= item.Value + 1;
				ret %= 1000000007;
			}
			Console.WriteLine(ret);
		}
	}
}