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
		var a = new int[N, N];
		for (var i = 0; i < N; i++)
		{
			var I = G();
			for (var j = 0; j < N; j++) a[i, j] = I[j];
		}
		WriteLine(Check(a));
	}
	long Check(int[,] a)
	{
		for (var k = 0; k < N; k++) for (var v = 0; v < N; v++) for (var w = 0; w < N; w++) if (a[v, w] > a[v, k] + a[k, w]) return -1;
		var s = 0L;
		for (var i = 0; i < N; i++)
			for (var j = 0; j < i; j++)
			{
				var need = false;
				for (var k = 0; k < N; k++) if (k != i && k != j) need |= a[i, j] == a[i, k] + a[k, j];
				if (!need) s += a[i, j];
			}
		return s;
	}
}