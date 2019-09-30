//#pragma warning disable
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System;
using System.Numerics;
using System.Threading.Tasks;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		int H = I[0], W = I[1], h = I[2], w = I[3];
		var t = YesNo(H, W, h, w);
		Console.WriteLine(t ? "Yes" : "No");
		if (t) for (var y = 0; y < H; y++)
			{
				for (var x = 0; x < W; x++) Console.Write("{0}{1}", map[y, x], x == W - 1 ? "" : " ");
				Console.WriteLine();
			}
	}
	int[,] map;
	void Swap2()
	{
		var Y = map.GetLength(0);
		var X = map.GetLength(1);
		var m2 = new int[X, Y];
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) m2[x, y] = map[y, x];
		map = m2;
	}
	bool YesNo(int H, int W, int h, int w)
	{
		if (h == H && w == W) return false;
		if (H % h == 0 && W % w == 0) return false;
		if (H % h == 0)
		{
			var t = YesNo(W, H, w, h);
			Swap2();
			return t;
		}
		var rem = H % h;
		var dup = h - rem;
		var N = H / h;
		var a = dup * (2 * N + 1);
		var b = 2 * rem * (N + 1);
		var c = dup * (N + 1);
		map = new int[H, W];
		for (var q = 0; q < W; q++)
		{
			for (var i = 0; i < N; i++)
			{
				for (var j = 0; j < rem; j++) map[i * h + j, q] = a;
				for (var j = rem; j < h; j++) map[i * h + j, q] = -b;
			}
			for (var i = N * h; i < H; i++) map[i, q] = c;
		}
		return true;
	}
}