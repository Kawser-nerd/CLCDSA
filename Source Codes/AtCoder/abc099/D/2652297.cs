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
		var I = G;
		int N = I[0], C = I[1];
		var cost = new int[C, C];
		for (var i = 0; i < C; i++)
		{
			I = G;
			for (var j = 0; j < C; j++) cost[i, j] = I[j];
		}
		var map = new int[N, N];
		for (var i = 0; i < N; i++)
		{
			I = G;
			for (var j = 0; j < N; j++) map[i, j] = I[j] - 1;
		}
		var ans = N * N * 1001;
		var c2 = new int[3, C];
		for (var i = 0; i < N; i++) for (var j = 0; j < N; j++) for (var c = 0; c < C; c++) c2[(i + j) % 3, c] += cost[map[i, j], c];
		for (var p = 0; p < C; p++)
			for (var q = 0; q < C; q++)
				for (var r = 0; r < C; r++)
					if (p != q && q != r && r != p) ans = Min(ans, c2[0, p] + c2[1, q] + c2[2, r]);
		WriteLine(ans);
	}
}