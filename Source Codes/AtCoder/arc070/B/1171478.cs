#pragma warning disable
using System.Collections.Generic;
using System.Linq;
using System;
using System.Collections;
using static System.Math;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(Console.ReadLine());
	int[] G() => Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		var a = G();
		int N = a[0], K = a[1];
		a = G();
		Array.Sort(a);
		Console.WriteLine(FirstBinary(0, N, c =>
		{
			var dp = new bool[K];
			dp[0] = true;
			for (var i = 0; i < N; i++)
			{
				if (i == c) continue;
				for (var s = K - 1; s >= a[i]; s--) dp[s] |= dp[s - a[i]];
			}
			for (var i = K - 1; i >= 0; i--) if (dp[i]) return i + a[c] >= K;
			return false;
		}));
	}
	static int FirstBinary(int min, int max, Predicate<int> pred)
	{
		while (min < max)
		{
			var mid = (min + max) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
	}
}