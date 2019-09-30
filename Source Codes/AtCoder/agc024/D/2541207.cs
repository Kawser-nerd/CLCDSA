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
		WriteLine(Solve());
		Out.Flush();
	}
	struct Answer : IComparable<Answer>
	{
		public long Depth, Leaf;
		public Answer(long d, long l) { Depth = d; Leaf = l; }
		public int CompareTo(Answer answer) { var x = Depth.CompareTo(answer.Depth); return x == 0 ? Leaf.CompareTo(answer.Leaf) : x; }
		public override string ToString() => $"{Depth} {Leaf}";
	}
	List<int>[] g;
	Answer Solve()
	{
		var N = F;
		g = new List<int>[N];
		for (var i = 0; i < N; i++) g[i] = new List<int>();
		for (var i = 0; i < N - 1; i++)
		{
			var I = G;
			g[I[0] - 1].Add(I[1] - 1);
			g[I[1] - 1].Add(I[0] - 1);
		}
		var x = Visit(-1, 0);
		var y = Visit(-1, x.Item2);
		var p = new int[N];
		AsRoot(x.Item2, -1, p);
		var c = y.Item2;
		for (var i = 0; i < y.Item1 / 2; i++) c = p[c];
		Answer ans;
		if (y.Item1 % 2 == 0)
		{
			ans = Check(c);
			foreach (var d in g[c])
			{
				var t = Check(c, d);
				if (ans.CompareTo(t) > 0) ans = t;
			}
		}
		else ans = Check(c, p[c]);
		return ans;
	}
	long[] Unite(IEnumerable<long[]> z)
	{
		var ans = new long[z.Max(x => x.Length) + 1];
		ans[0] = z.Count();
		for (var i = 0; i < ans.Length - 1; i++)
		{
			ans[i + 1] = 0;
			foreach (var t in z) if (i < t.Length) ans[i + 1] = Max(ans[i + 1], t[i]);
		}
		return ans;
	}
	long[] Unite(int v, int p)
	{
		var sub = new List<long[]>();
		foreach (var e in g[v]) if (e != p) sub.Add(Unite(e, v));
		if (sub.Count == 0) return new []{ 1L };
		return Unite(sub);
	}
	Answer Check(int v)
	{
		var ans = new Answer(0, 0);
		var tmp = Unite(v, -1);
		var p = 1L;
		foreach (var x in tmp) p *= x;
		return new Answer(tmp.Length, p);
	}
	Answer Check(int u, int v)
	{
		var a = Unite(u, v);
		var b = Unite(v, u);
		var c = Unite(new[] { a, b });
		var p = 1L;
		foreach (var x in c) p *= x;
		return new Answer(c.Length - 1, p);
	}
	void AsRoot(int v, int p, int[] par)
	{
		par[v] = p;
		foreach (var e in g[v]) if (e != p) AsRoot(e, v, par);
	}
	Tuple<int, int> Visit(int p, int v)
	{
		var r = new Tuple<int, int>(0, v);
		foreach (var e in g[v])
			if (e != p)
			{
				var t = Visit(v, e);
				if (r.Item1 < t.Item1 + 1) r = new Tuple<int, int>(t.Item1 + 1, t.Item2);
			}
		return r;
	}
}