using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var S = ReadLine();
		var T = ReadLine();
		var Q = F();
		var N = S.Length;
		var M = T.Length;
		var a = new int[N + 1];
		var b = new int[M + 1];
		for (var i = 0; i < N; i++) a[i + 1] = a[i] + (S[i] == 'A' ? 1 : -1);
		for (var i = 0; i < M; i++) b[i + 1] = b[i] + (T[i] == 'A' ? 1 : -1);
		for (var i = 0; i < Q; i++)
		{
			var q = G();
			WriteLine((a[q[1]] - a[q[0] - 1] - b[q[3]] + b[q[2] - 1]) % 3 == 0 ? "YES" : "NO");
		}
	}
}