using System.IO;
using System.Linq;
using static System.Console;
using System.Text;
using System.Collections.Generic;
using System;

class K
{
	static int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	static void Main()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		var I = G;
		int N = I[0], M = I[1];
		var uf = new UnionFindTree(N);
		for (var i = 0; i < M; i++)
		{
			I = G;
			int a = I[0] - 1, b = I[1] - 1;
			uf.Unite(a, b);
		}
		var Q = int.Parse(ReadLine());
		var sb = new StringBuilder();
		while (Q-- > 0)
		{
			I = G;
			int x = I[0] - 1, y = I[1] - 1, z = I[2], l = 0, r = M + 1;
			while (l < r)
			{
				var t = (l + r) / 2;
				int p = uf.Find(t, x), q = uf.Find(t, y), s = p == q ? uf.GetSize(t, p) : uf.GetSize(t, p) + uf.GetSize(t, q);
				if (s >= z) r = t;
				else l = t + 1;
			}
			sb.AppendLine(l.ToString());
		}
		Write(sb);
		Out.Flush();
	}
}
struct Pair
{
	public readonly int X, Y;
	public Pair(int x, int y) { X = x; Y = y; }
}
class UnionFindTree
{
	int now;
	readonly int[] par, rank, time, size;
	readonly List<Pair>[] sizeHist;
	public UnionFindTree(int N)
	{
		par = new int[N];
		rank = new int[N];
		time = new int[N];
		size = new int[N];
		sizeHist = new List<Pair>[N];
		for (var i = 0; i < N; i++) { par[i] = i; time[i] = int.MaxValue; sizeHist[i] = new List<Pair> { new Pair(0, 1) }; size[i] = 1; }
	}
	public int Find(int x) => x == par[x] ? x : Find(par[x]);
	public int Find(int t, int x) => time[x] > t ? x : Find(t, par[x]);
	public void Unite(int x, int y)
	{
		now++; x = Find(now, x); y = Find(now, y);
		if (x == y) return;
		if (rank[x] < rank[y]) { var z = x; x = y; y = z; }
		par[y] = x; time[y] = now; size[x] += size[y]; sizeHist[x].Add(new Pair(now, size[x]));
		if (rank[x] == rank[y]) rank[x]++;
	}
	public int GetSize(int t, int x)
	{
		var i = FirstBinary(0, sizeHist[x].Count, j => sizeHist[x][j].X > t) - 1;
		return sizeHist[x][i].Y;
	}
	public static int FirstBinary(int min, int max, Predicate<int> pred)
	{
		while (min < max)
		{
			var mid = (min + max) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
	}
}