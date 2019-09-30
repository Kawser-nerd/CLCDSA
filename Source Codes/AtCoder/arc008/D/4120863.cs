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
		var I = GL;
		var M = (int)I[1];
		var p = new long[M];
		var a = new double[M];
		var b = new double[M];
		for (var i = 0; i < M; i++)
		{
			var S = Strs;
			p[i] = long.Parse(S[0]);
			a[i] = double.Parse(S[1]);
			b[i] = double.Parse(S[2]);
		}
		var ks = new SortedSet<long>(p).ToList();
		var n = ks.Count;
		var id = new Dictionary<long, int>();
		for (var i = 0; i < n; i++) id[ks[i]] = i;
		var seg = new SegmentTree(n);
		double min = 1.0, max = 1.0;
		for (var i = 0; i < M; i++)
		{
			seg[id[p[i]]] = new Node(a[i], b[i]);
			var val = seg.Range(0, n).ApplyTo(1);
			min = Min(min, val);
			max = Max(max, val);
		}
		WriteLine(min);
		WriteLine(max);
	}
}
struct Node
{
	public static readonly Node Unit = new Node(1, 0);
	public static Node Compose(Node p, Node q)
	{
		// q(p(x)) = q(p.A*x+p.B) = q.A*(p.A*x+p.B)+q.B
		return new Node(p.A * q.A, q.A * p.B + q.B);
	}
	public readonly double A, B;
	public Node(double a, double b) { A = a; B = b; }
	public double ApplyTo(double x) => A * x + B;
	public override string ToString() => $"{A}*x+{B}";
}
class SegmentTree
{
	readonly int N;
	readonly Node[] seg;
	public SegmentTree(int n)
	{
		N = 1;
		while (N < n) N <<= 1;
		seg = new Node[2 * N - 1];
		for (var i = 0; i < 2 * N - 1; i++) seg[i] = Node.Unit;
	}
	public void Update(int index, Node value)
	{
		index += N - 1;
		seg[index] = value;
		while (index > 0)
		{
			index = (index - 1) / 2;
			seg[index] = Node.Compose(seg[index * 2 + 1], seg[index * 2 + 2]);
		}
	}
	public Node this[int n] { get { return Range(n, n + 1); } set { Update(n, value); } }
	public Node Range(int from, int to) => Range(from, to, 0, 0, N);
	Node Range(int from, int to, int node, int l, int r)
	{
		if (to <= l || r <= from) return Node.Unit;
		if (from <= l && r <= to) return seg[node];
		return Node.Compose(Range(from, to, 2 * node + 1, l, (l + r) >> 1), Range(from, to, 2 * node + 2, (l + r) >> 1, r));
	}
}