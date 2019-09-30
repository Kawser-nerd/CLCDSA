using System;
using System.IO;
using System.Linq;
class Z { static void Main() { new K(); } }
class K
{
	public K()
	{
		Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Console.Out.Flush();
	}
	void Solve()
	{
		var I = Console.ReadLine().Split().Select(int.Parse).ToArray();
		int H = I[0], W = I[1];
		var t = YesNo(H, W, I[2], I[3]);
		if (t == null) Console.WriteLine("No");
		else
		{
			Console.WriteLine("Yes");
			for (var h = 0; h < H; h++)
			{
				for (var w = 0; w < W; w++) Console.Write("{0}{1}", t[h, w], w == W - 1 ? "" : " ");
				Console.WriteLine();
			}
		}
	}
	int[,] Swap2(int[,] t)
	{
		var Y = t.GetLength(0);
		var X = t.GetLength(1);
		var t2 = new int[X, Y];
		for (var x = 0; x < X; x++) for (var y = 0; y < Y; y++) t2[x, y] = t[y, x];
		return t2;
	}
	int[,] YesNo(int H, int W, int h, int w)
	{
		if (H % h == 0 && W % w == 0) return null;
		if (H % h == 0) return Swap2(YesNo(W, H, w, h));
		var r = H % h;
		var s = h - r;
		var N = H / h;
		var a = s * (2 * N + 1);
		var b = 2 * r * (N + 1);
		var x = s * (N + 1);
		var t = new int[H, W];
		for (var y = 0; y < W; y++)
		{
			for (var i = 0; i < N; i++)
			{
				for (var j = 0; j < r; j++) t[i * h + j, y] = a;
				for (var j = r; j < h; j++) t[i * h + j, y] = -b;
			}
			for (var i = N * h; i < H; i++) t[i, y] = x;
		}
		return t;
	}
}