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
		Console.WriteLine(Solve() ? "Yes" : "No");
		Out.Flush();
	}
	bool Solve()
	{
		var N = F;
		var t = new int[N];
		var x = new int[N];
		var y = new int[N];
		for (var i = 0; i < N; i++)
		{
			var I = G;
			t[i] = I[0];
			x[i] = I[1];
			y[i] = I[2];
		}
		int t0 = 0, x0 = 0, y0 = 0;
		for (var i = 0; i < N; i++)
		{
			if (!IsFeasible(t[i] - t0, x[i] - x0, y[i] - y0)) return false;
			t0 = t[i];
			x0 = x[i];
			y0 = y[i];
		}
		return true;
	}
	bool IsFeasible(int dt, int dx, int dy)
	{
		if (dx < 0) dx *= -1;
		if (dy < 0) dy *= -1;
		return (dt % 2) == (dx + dy) % 2 && dt >= dx + dy;
	}
}