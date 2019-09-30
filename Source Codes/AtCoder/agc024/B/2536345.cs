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
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F;
		var p = new int[N];
		for (var i = 0; i < N; i++) p[i] = F - 1;
		var q = new int[N];
		for (var i = 0; i < N; i++) q[p[i]] = i;
		var ans = N + 10;
		var l = 0;
		while (l < N)
		{
			var r = l + 1;
			while (r < N && q[r] >= q[r - 1]) r++;
			ans = Min(ans, N - r + l);
			// Console.WriteLine($"l = {l}, r = {r}, {N - r + l}");
			l = r;
		}
		Console.WriteLine(ans);
	}
}