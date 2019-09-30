#pragma warning disable
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Collections;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	const int Mod = 1000000007;
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	int Y, X, sx, sy, gx, gy;
	int[,] map;
	double[] pow;
	void Solve()
	{
		var I = G();
		Y = I[0];
		X = I[1];
		map = new int[X, Y];
		for (var y = 0; y < Y; y++)
		{
			var s = ReadLine();
			for (var x = 0; x < X; x++)
			{
				if (s[x] == 's')
				{
					sx = x;
					sy = y;
				}
				else if (s[x] == 'g')
				{
					gx = x;
					gy = y;
				}
				else if (s[x] != '#') map[x, y] = s[x] - '0';
				else map[x, y] = -1;
			}
		}
		pow = new double[Min(X * Y, 3000)];
		pow[0] = 1;
		for (var t = 1; t < pow.Length; t++) pow[t] = pow[t - 1] * 0.99;
		if (NG())
		{
			WriteLine(-1);
			return;
		}
		double l = 0.0, r = 9.0 * 0.99;
		while (r - l > 2.0e-9)
		{
			var m = (l + r) / 2;
			if (OK(m)) l = m;
			else r = m;
		}
		WriteLine((l + r) / 2);
	}
	int[] dx = new[] { 1, 0, -1, 0, 1 };
	bool NG()
	{
		var used = new bool[X, Y];
		var q = new Queue<Tuple<int, int>>();
		used[sx, sy] = true;
		q.Enqueue(new Tuple<int, int>(sx, sy));
		while (q.Count > 0)
		{
			var p = q.Dequeue();
			int x = p.Item1, y = p.Item2;
			for (var i = 0; i < 4; i++)
			{
				int u = x + dx[i], v = y + dx[i + 1];
				if (u == gx && v == gy) return false;
				if (0 <= u && u < X && 0 <= v && v < Y && !used[u, v] && map[u, v] >= 0)
				{
					used[u, v] = true;
					q.Enqueue(new Tuple<int, int>(u, v));
				}
			}
		}
		return true;
	}
	bool OK(double m)
	{
		var used = new bool[X, Y];
		var q = new Queue<Tuple<int, int, int>>();
		used[sx, sy] = true;
		q.Enqueue(new Tuple<int, int, int>(sx, sy, 0));
		while (q.Count > 0)
		{
			var p = q.Dequeue();
			int x = p.Item1, y = p.Item2, t = p.Item3;
			for (var i = 0; i < 4; i++)
			{
				int u = x + dx[i], v = y + dx[i + 1];
				if (u == gx && v == gy) return true;
				if (0 <= u && u < X && 0 <= v && v < Y && !used[u, v] && map[u, v] * pow[t + 1] >= m)
				{
					used[u, v] = true;
					q.Enqueue(new Tuple<int, int, int>(u, v, t + 1));
				}
			}
		}
		return false;
	}
	long GCD(long a, long b)
	{
		var n = (ulong)Abs(a); var m = (ulong)Abs(b);
		if (n == 0) return (long)m; if (m == 0) return (long)n;
		int zm = 0, zn = 0;
		while ((n & 1) == 0) { n >>= 1; zn++; }
		while ((m & 1) == 0) { m >>= 1; zm++; }
		while (m != n)
		{
			if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
			else { n -= m; while ((n & 1) == 0) n >>= 1; }
		}
		return (long)n << Min(zm, zn);
	}
}