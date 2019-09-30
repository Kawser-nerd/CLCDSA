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
	void Solve()
	{
		var N = F();
		var A = G();
		int m = A.Min(), M = A.Max(), mi = 0, Mi = 0;
		while (A[mi] != m) mi++;
		while (A[Mi] != M) Mi++;
		if (m >= 0)
		{
			Console.WriteLine(N - 1);
			for (var i = 1; i < N; i++) Console.WriteLine("{0} {1}", i, i + 1);
		}
		else if (M <= 0)
		{
			Console.WriteLine(N - 1);
			for (var i = N - 1; i > 0; i--) Console.WriteLine("{0} {1}", i + 1, i);
		}
		// m < 0 && M > 0
		else if (M >= -m)
		{
			Console.WriteLine(2 * N - 1);
			for (var i = 0; i < N; i++) Console.WriteLine("{0} {1}", Mi + 1, i + 1);
			for (var i = 1; i < N; i++) Console.WriteLine("{0} {1}", i, i + 1);
		}
		else
		{
			Console.WriteLine(2 * N - 1);
			for (var i = 0; i < N; i++) Console.WriteLine("{0} {1}", mi + 1, i + 1);
			for (var i = N - 1; i > 0; i--) Console.WriteLine("{0} {1}", i + 1, i);
		}
	}
}