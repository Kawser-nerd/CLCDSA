using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
class K
{
	static void Main() => WriteLine(Solve());
	static long Solve()
	{
		var S = ReadLine();
		var s = S.Select(c => c - 'a').ToArray();
		int N = S.Length, odd = 0, mid = -1;
		var cnt = new int[26];
		foreach (var c in s) cnt[c]++;
		for (var c = 0; c < 26; c++)
		{
			if (cnt[c] % 2 == 1) { mid = c; odd++; }
			cnt[c] /= 2;
		}
		if (odd > 1) return -1;
		var left = new List<int>();
		foreach (var c in s) if (cnt[c] > 0) { cnt[c]--; left.Add(c); }
		int[] t = new int[N], ind = new int[26], p = new int[N];
		for (var i = 0; i < left.Count; i++) t[N - 1 - i] = t[i] = left[i];
		if (mid >= 0) t[N / 2] = mid;
		for (var i = 0; i < N; i++)
		{
			var c = s[i];
			while (t[ind[c]] != c) ind[c]++;
			p[i] = ind[c]++;
		}
		return BIT.Inversion(p);
	}
}
class BIT
{
	public readonly int Size;
	readonly int[] bit;
	public BIT(int size) { Size = size; bit = new int[size + 1]; }
	public void Add(int index, int value) { for (var i = index + 1; i <= Size; i += i & (-i)) bit[i] += value; }
	public int Sum(int to) { var sum = 0; for (var i = to; i > 0; i -= i & (-i)) sum += bit[i]; return sum; }
	public static long Inversion(int[] s)
	{
		var ans = 0L;
		var bit = new BIT(s.Length);
		for (var j = 0; j < s.Length; j++)
		{
			ans += j - bit.Sum(s[j]);
			bit.Add(s[j], 1);
		}
		return ans;
	}
}