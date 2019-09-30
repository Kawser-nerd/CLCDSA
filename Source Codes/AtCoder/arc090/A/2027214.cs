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
		var map = new int[N, 2];
		for (var i = 0; i < 2; i++)
		{
			var I = G;
			for (var x = 0; x < N; x++) map[x, i] = I[x];
		}
		var max = new int[N, 2];
		for (var x = N-1; x >= 0; x--)
			for (var y = 1; y >= 0; y--)
			{
				if (x < N - 1) max[x, y] = Max(max[x, y], max[x + 1, y]);
				if (y < 1) max[x, y] = Max(max[x, y], max[x, y + 1]);
				max[x, y] += map[x, y];
			}
		Console.WriteLine(max[0, 0]);
	}
}