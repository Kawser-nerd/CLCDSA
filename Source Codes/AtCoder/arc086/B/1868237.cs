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
	long FL() => long.Parse(ReadLine());
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
		var A = G();
		int m = A.Min(), M = A.Max(), mi = 0, Mi = 0;
		while (A[mi] != m) mi++;
		while (A[Mi] != M) Mi++;
		if (m >= 0)
		{
			Console.WriteLine(N - 1);
			Pos();
		}
		else if (M <= 0)
		{
			Console.WriteLine(N - 1);
			Neg();
		}
		else if (M >= -m)
		{
			Console.WriteLine(2 * N - 1);
			Unif(Mi);
			Pos();
		}
		else
		{
			Console.WriteLine(2 * N - 1);
			Unif(mi);
			Neg();
		}
	}
	void Unif(int k) { for (var i = 0; i < N; i++) F(k, i); }
	void Pos() { for (var i = 1; i < N; i++) F(i - 1, i); }
	void Neg() { for (var i = N - 1; i > 0; i--) F(i, i - 1); }
	void F(int x, int y) => Console.WriteLine("{0} {1}", x + 1, y + 1);
}