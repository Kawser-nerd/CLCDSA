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
		int X = I[0], Y = I[1], N = I[2];
		var ls = new int[X];
		for (var x = 0; x < X; x++) ls[x] = Y;
		for (var i = 0; i < N; i++)
		{
			I = G;
			int x = I[0] - 1, y = I[1] - 1;
			ls[x] = Min(ls[x], y);
		}
		var R = 0;
		for (var x = 0; x < X - 1; x++)
		{
			// (x,0)~(x,R) ???????
			if (ls[x + 1] <= R) { WriteLine(x + 1); return; }
			if (ls[x + 1] > R + 1) R++;
		}
		WriteLine(X);
	}
}