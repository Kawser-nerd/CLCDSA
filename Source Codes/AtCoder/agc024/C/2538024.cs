using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Console.WriteLine(Solve());
		Out.Flush();
	}
	int[] A, B;
	long Solve()
	{
		var N = F;
		A = new int[N];
		B = new int[N];
		for (var i = 0; i < N; i++) A[i] = F;
		var l = 0;
		var ans = 0L;
		while (l < N)
		{
			var tmp = new List<int>();
			if (A[l] != 0) return -1;
			var r = l + 1;
			while (r < N && A[r] > 0) r++;
			var c = Solve(l, r);
			if (c < 0) return -1;
			ans += c;
			l = r;
		}
		return ans;
	}
	long Solve(int l, int r)
	{
		if (r - l == 1) return 0;
		for (var t = l + 1; t < r; t++) if (A[t] - A[t - 1] > 1) return -1;
		var ans = 0L;
		var i = r - 1;
		while (i > l)
		{
			ans += A[i];
			var j = i - 1;
			while (j > l && A[i] - A[j] == i - j) j--;
			i = j;
		}
		return ans;
	}
}