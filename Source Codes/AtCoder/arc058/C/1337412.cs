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
	int N, X, Y, Z;
	void Solve()
	{
		var I = G();
		N = I[0];
		X = I[1];
		Y = I[2];
		Z = I[3];
		var M = 1 << (X + Y + Z);
		var m = M - 1;
		var ng = (1 << (Z - 1)) | (1 << (Y + Z - 1)) | (1 << (X + Y + Z - 1));
		var dp = new long[N + 1, M];
		dp[0, 0] = 1;
		for (var i = 0; i < N; i++) for (var s = 0; s < M; s++) if (dp[i, s] != 0) for (var a = 1; a <= 10; a++)
					{
						var t = ((s << a) | (1 << (a - 1))) & m;
						if ((t & ng) != ng) dp[i + 1, t] = (dp[i + 1, t] + dp[i, s]) % MOD;
					}
		var ans = 1L;
		for (var i = 0; i < N; i++) ans = ans * 10 % MOD;
		for (var s = 0; s < M; s++) ans -= dp[N, s];
		if ((ans %= MOD) < 0) ans += MOD;
		Console.WriteLine(ans);
	}
}