using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		WriteLine(YesNo() ? "YES" : "NO");
	}
	const int L = 19;
	bool YesNo()
	{
		var map = new int[L, L];
		int sb = 0, sw = 0;
		for (var y = 0; y < L; y++)
		{
			var l = ReadLine();
			for (var x = 0; x < L; x++)
			{
				if (l[x] == 'o')
				{
					map[x, y] = 1;
					sb++;
				}
				else if (l[x] == 'x')
				{
					map[x, y] = -1;
					sw++;
				}
			}
		}
		if (sb + sw == 0) return true;
		int last;
		if (sb == sw) last = -1;
		else if (sb == sw + 1) last = 1;
		else return false;
		if (Danger(map, -last) != null) return false;
		var danger = Danger(map, last);
		if (danger == null) return true;
		int p = danger.Item1, q = danger.Item2, d = danger.Item3;
		for (var i = 0; i < danger.Item4; i++)
		{
			map[p, q] = 0;
			if (Danger(map, last) == null) return true;
			map[p, q] = last;
			p += dx[d];
			q += dx[d + 1];
		}
		return false;
	}
	int[] dx = new[]{ 1, 0, 1, 1, -1 };
	Tuple<int, int, int, int> Danger(int[,] map, int c)
	{
		for (var x = 0; x < L; x++)
			for (var y = 0; y < L; y++)
				if (map[x, y] == c)
					for (var i = 0; i < 4; i++)
					{
						int p = x, q = y, s = 0;
						while (p < L && 0 <= q && q < L && map[p, q] == c)
						{
							s++;
							p += dx[i];
							q += dx[i + 1];
						}
						if (s >= 5) return new Tuple<int, int, int, int>(x, y, i, s);
					}
		return null;
	}
}