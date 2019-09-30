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
		var q = G();
		int N = q[0], D = q[1];
		var d = G();
		int Q = F();
		q = G();
		var x = new int[N + 1];
		x[0] = D;
		for (var i = 0; i < N; i++) x[i + 1] = Min(x[i], Abs(x[i] - d[i]));
		var y = new int[N + 1];
		y[N] = 1;
		for (var i = N; i > 0; i--) y[i - 1] = y[i] + (y[i] <= d[i - 1] / 2 ? 0 : d[i - 1]);
		foreach (var z in q.Select(w => w-1)) WriteLine(y[z + 1] <= x[z] ? "YES" : "NO");
	}
}