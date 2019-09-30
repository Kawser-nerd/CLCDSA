using System;
using System.Linq;

static class Solution
{
	private static long min(long a, long b)
	{
		return a < b ? a : b;
	}
	
	static void Main()
	{
		var T = Convert.ToInt32(Console.ReadLine());
		for (var iT = 1; iT <= T; ++iT)
		{
			var array = (from word in Console.ReadLine().Split()
			             select Convert.ToInt64(word)).ToArray();
			int N = (int) array[0];
			var P = array[1];
			
			long may = 0;
			for (var i = 1; i <= N; ++i)
				if ((1L << i) - 1 < P)
					may = (1L << N) - (1L << N - i);
			
			long must = 0;
			for (var i = 1; i <= N; ++i)
				if (((1L << i) - 1 << N - i) < P)
					must = min((1L << i + 1) - 1, 1L << N) - 1;
			
			Console.WriteLine("Case #{0}: {1} {2}", iT, must, may);
		}
	}
}