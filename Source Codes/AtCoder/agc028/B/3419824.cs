using System.Linq;
using static System.Console;
class K
{
	static int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	const int MOD = 1000000007;
	static void Main()
	{
		var N = G[0];
		var A = G;
		var inv = new long[N + 1];
		for (var i = 1; i <= N; i++) inv[i] = Inverse(i, MOD);
		var sum = new long[N + 2];
		for (var i = 0; i <= N; i++) sum[i + 1] = (sum[i] + inv[i]) % MOD;
		var ans = 0l;
		for (var i = 0; i < N; i++)
		{
			var x = (sum[i + 2] - sum[2]) + (sum[N - i + 1] - sum[1]);
			x %= MOD;
			if (x < 0) x += MOD;
			ans += x * A[i] % MOD;
		}
		ans %= MOD;
		for (var i = 1; i <= N; i++) ans = ans * i % MOD;
		WriteLine(ans % MOD);
	}
	static long Inverse(long n, long mod)
	{
		long a = 1, b = 0, c = 0, d = 1;
		while (mod > 0)
		{
			var r = n % mod;
			var q = n / mod;
			n = mod;
			mod = r;
			var tmp = a;
			a = -a * q + b;
			b = tmp;
			tmp = c;
			c = -c * q + d;
			d = tmp;
		}
		return d;
	}
}