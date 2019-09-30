using System.Linq;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	public K()
	{
		var N = int.Parse(ReadLine());
		var t = G();
		var v = G();
		var V = v.Max();
		// dp[n, v] = t[0]+...+t[n-1] ???????????? v/2 ??????????????????? * 16
		// ????????????? dp[n, v] = -1 ???
		// ??? dp[N, 0] / 16
		var dp = new int[N + 1, 2 * V + 1];
		dp[0, 0] = 0;
		// dp[n, v] >= 0 ??? v ????? M[n] ???
		var M = new int[N + 1];
		for (var i = 1; i <= 2 * V; i++) dp[0, i] = -1;
		for (var n = 0; n < N; n++)
		{
			M[n + 1] = Min(M[n] + 2 * t[n], 2 * v[n]);
			for (var w = M[n + 1] + 1; w <= 2 * V; w++) dp[n + 1, w] = -1;
			for (var w = 0; w <= M[n + 1]; w++)
			{
				for (var u = 0; u <= M[n]; u++)
				{
					// dp[n, u] => dp[n+1, w]
					if (u > 2 * v[n] || u - 2 * t[n] > w || u + 2 * t[n] < w) continue;
					int au = 2 * v[n] - u,  bw = 2 * v[n] - w, run;
					// ???????????????????????
					if (au + bw <= 2 * t[n]) run = 2 * (8 * t[n] * v[n] - au * au - bw * bw);
					// ???????????? x/4 (< v[n]) ??????????
					else
					{
						var x = 2 * t[n] + u + w;
						run = x * x - 2 * (u * u + w * w);
					}
					dp[n + 1, w] = Max(dp[n + 1, w], dp[n, u] + run);
				}
			}
		}
		WriteLine(dp[N, 0] / 16m);
	}
}