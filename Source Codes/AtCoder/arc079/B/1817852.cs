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
		var K = FL();
		var N = 50;
		var a = new long[N];
		for (var i = 0; i < N; i++) a[i] = i + (K / N) - (K % N);
		for (var i = N * (K / N); i < K; i++) a[i % N] += N + 1;
		Console.WriteLine(N);
		Console.WriteLine(string.Join(" ", a));
	}
}