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
	int N;
	List<int> c, d;
	void Solve()
	{
		N = F;
		var a = G;
		var b = G;
		var s = 0;
		for (var i = 29; i >= 0; i--)
		{
			int n = 1 << i, m = n << 1, t = 0, l1 = 0, l2 = 0, r1 = 0, r2 = 0, k = m - 1;
			if (i == 29)
			{
				c = new List<int>(a);
				d = new List<int>(b);
				c.Sort();
				d.Sort();
			}
			else
			{
				c = Sort(c, k);
				d = Sort(d, k);
				//for (var j = 0; j < N; j++) c[j] &= k;
				//for (var j = 0; j < N; j++) d[j] &= k;
			}
			for (var j = N - 1; j >= 0; j--)
			{
				var x = d[j];
				l1 = Incr(l1, n - x);
				r1 = Incr(r1, m - x);
				l2 = Incr(l2, n + m - x);
				r2 = Incr(r2, 2 * m - x);
				t += r1 - l1;
				t += r2 - l2;
				t %= 2;
			}
			if (t > 0) s ^= 1 << i;
		}
		WriteLine(s);
	}
	int Incr(int i, int v)
	{
		while (i < N && c[i] < v) i++;
		return i;
	}
	List<int> Sort(List<int> x, int mask)
	{
		var m = 0;
		while (m < N && x[m] <= mask) m++;
		for (var i = 0; i < N; i++) x[i] &= mask;
		if (m == 0 || m == N) return x;
		return Merge(x, m);
	}
	// x[0, m) , x[m, N) => sort
	List<int> Merge(List<int> x, int m)
	{
		var y = new List<int>();
		int l1 = 0, r1 = m;
		while (true)
		{
			if (x[l1] <= x[r1]) y.Add(x[l1++]);
			else y.Add(x[r1++]);
			if (l1 == m || r1 == N) break;
		}
		while (l1 < m) y.Add(x[l1++]);
		while (r1 < N) y.Add(x[r1++]);
		return y;
	}
}