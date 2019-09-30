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
		var I = G();
		int N = I[0], M = I[1];
		WriteLine(Calc(N) * Calc(M) % MOD);
	}
	long Calc(int N)
	{
		var x = G();
		var s = new long[N + 1];
		for (var i = 0; i < N; i++) s[i + 1] = s[i] + x[i];
		var ans = 0L;
		for (var i = 0; i < N; i++) ans = (ans + (long)i * x[i] - s[i]) % MOD;
		if (ans < 0) ans += MOD;
		return ans;
	}
}