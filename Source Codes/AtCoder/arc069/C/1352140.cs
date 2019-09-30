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
	void Solve()
	{
		var N = F();
		var a = G();
		var t = new List<P>();
		var n = new long[N];
		for (var i = 0; i < N; i++) t.Add(new P(a[i], i));
		t.Sort();
		var m = N + 1;
		for (var i = 0; i < N; i++)
		{
			var d = i < N - 1 ? t[i].H - t[i + 1].H : t[i].H;
			m = Min(m, t[i].I);
			n[m] += (i + 1L) * d;
		}
		for (var i = 0; i < N; i++) WriteLine(n[i]);
	}
}
struct P : IComparable<P>
{
	public int H, I;
	public P(int h, int i)
	{
		H = h;
		I = i;
	}
	public int CompareTo(P x)
	{
		var c = x.H.CompareTo(H);
		return c == 0 ? x.I.CompareTo(I) : c;
	}
}