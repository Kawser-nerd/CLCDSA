using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		long CASES = long.Parse(Console.ReadLine());
		for (long CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] parts = Console.ReadLine().Split();
			long C = long.Parse(parts[0]);
			long D = long.Parse(parts[1]);
			long V = long.Parse(parts[2]);
			bool[] have = new bool[V + 1];
			parts = Console.ReadLine().Split();
			long[] nums = new long[D];
			for (long i = 0; i < D; i++)
				nums[i] = long.Parse(parts[i]);

			long ans = 0;
			long max = C;
			long k = 0;
			if (nums[0] == 1) k++;
			else ans++;

			while (max < V)
			{
				if (k == D || nums[k] > max + 1)
				{
					ans++;
					max = (max + 1) * C + max;
				}
				else
				{
					max = nums[k] * C + max;
					k++;
				}
			}

			Console.WriteLine("Case #" + CASE + ": " + ans);
		}
	}

	/*
			for (long i = 1; i <= V; i++)
				if (!canMake(i, C, nums))
					nums.Add(i);

	public static bool canMake(long x, long C, HashSet<long> nums)
	{
		bool[] can = new bool[x + 1];
		can[0] = true;
		foreach (long i in nums)
		{
			for (long j = x; j >= 0; j--)
			{
				if (!can[j]) continue;
				for (long k = 1; k <= C; k++)
					if (j + i * k <= x)
						can[j + i * k] = true;
			}
		}
		return can[x];
	}
	 * */
}
