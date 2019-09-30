using System.Linq;
using System;
using static System.Console;
class E { static void Main() => new K(); }
class K
{
	const int MOD = 1000000007;
	public K()
	{
		var I = ReadLine().Split().Select(int.Parse).ToArray();
		int N = I[0], X = I[1], Y = I[2], Z = I[3];
		var M = 1 << (X + Y + Z);
		var m = M - 1;
		var n = (1 << (Z - 1)) | (1 << (Y + Z - 1)) | (1 << (X + Y + Z - 1));
		var d = new long[N + 1, M];
		d[0, 0] = 1;
		for (var i = 0; i < N; i++) for (var s = 0; s < M; s++) if (d[i, s] != 0) for (var a = 1; a <= 10; a++)
		{
			var t = ((s << a) | (1 << (a - 1))) & m;
			if ((t & n) != n) d[i + 1, t] = (d[i + 1, t] + d[i, s]) % MOD;
		}
		var p = 1L;
		for (var i = 0; i < N; i++) p = p * 10 % MOD;
		for (var s = 0; s < M; s++) p += MOD - d[N, s];
		WriteLine(p % MOD);
	}
}