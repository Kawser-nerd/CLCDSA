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
class E { static void Main() => new K(); }
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
	int N;
	void Solve()
	{
		N = F();
		var c = new int[N];
		var a = new int[N];
		for (var i = 1; i < N; i++)
		{
			var I = G();
			c[i] = I[0];
			a[i] = I[1];
		}
		var s = new RMQ(N);
		s[0] = 0;
		for (var i = 1; i < N; i++) s[i] = -1;
		var grundy = new int[N];
		var sum = 0;
		for (var i = 1; i < N; i++)
		{
			grundy[i] = FirstBinary(0, N, j => s.Min(0, j) < i - c[i]) - 1;
			s[grundy[i]] = i;
			if (a[i] % 2 == 1) sum ^= grundy[i];
		}
		Console.WriteLine(sum != 0 ? "First" : "Second");
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
class RMQ
{
	int N2;
	readonly int[] seg;
	public RMQ(int n)
	{
		N2 = 1;
		while (N2 < n) N2 <<= 1;
		seg = new int[2 * N2 - 1];
		for (var i = 0; i < 2 * N2 - 1; i++) seg[i] = K.MOD;
	}
	public void Update(int index, int value)
	{
		index += N2 - 1;
		seg[index] = value;
		while (index > 0)
		{
			index = (index - 1) / 2;
			seg[index] = Math.Min(seg[index * 2 + 1], seg[index * 2 + 2]);
		}
	}
	public int this[int n] { get { return Min(n, n + 1); } set { Update(n, value); } }
	public int Min(int from, int to) => Min(from, to, 0, 0, N2);
	int Min(int from, int to, int node, int l, int r)
	{
		if (to <= l || r <= from) return K.MOD;
		if (from <= l && r <= to) return seg[node];
		return Math.Min(Min(from, to, 2 * node + 1, l, (l + r) >> 1), Min(from, to, 2 * node + 2, (l + r) >> 1, r));
	}
}