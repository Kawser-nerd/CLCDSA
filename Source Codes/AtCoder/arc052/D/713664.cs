using System;
using System.Collections.Generic;
using System.Linq;
class E { static void Main() { new K(); } }
class K
{
	long[] G() { return Console.ReadLine().Split().Select(_ => long.Parse(_)).ToArray(); }
	public static long GCD(long n, long m)
	{
		long a = Math.Abs(n), b = Math.Abs(m);
		while (b > 0) { var c = a % b; a = b; b = c; }
		return a;
	}
	public K()
	{
		var I = G();
		long K = I[0], M = I[1], ans = 0L, pow10 = 10000L;
		if (M < 10000) for (var i = 1; i <= M; i++) ans += Check(i, K);
		else
		{
			for (var i = 1; i < pow10; i++) ans += Check(i, K);
			for (var i = (M / pow10) * pow10; i <= M; i++) ans += Check(i, K);
			K /= GCD(K, 9);
			var count = new Dictionary<long, int>();
			for (var b = 0; b < 10; b++) for (var c = 0; c < 10; c++) for (var d = 0; d < 10; d++)
					{
						var x = Rem(-b - 11 * c - 111 * d, K);
						if (!count.ContainsKey(x)) count.Add(x, 0);
						count[x]++;
					}
			var log10 = -4; pow10 = 1;
			while (pow10 <= M) { log10++; pow10 *= 10; }
			pow10 = 10000;
			var arr = new int[log10]; arr[0] = 1;
			var lim = M.ToString().Substring(0, log10).Select(c => c - '0').Reverse().ToArray();
			var seq1 = new long[10];
			var sum = seq1[0] = 1111 % K;
			for (var i = 1; i < 10; i++) seq1[i] = (10 * seq1[i - 1] + 1) % K;
			while (true)
			{
				var flag = true;
				for (var i = 0; flag && i < log10; i++) flag = arr[i] == lim[i];
				if (flag) break;
				if (count.ContainsKey(sum)) ans += count[sum] * 10L;
				for (var j = 0; j < log10; j++)
				{
					arr[j]++;
					sum += seq1[j];
					if (arr[j] == 10) { arr[j] = 0; sum -= seq1[j] * 10; }
					else break;
				}
				sum = Rem(sum, K);
			}
		}
		Console.WriteLine(ans);
	}
	long Rem(long a, long b) { var x = a % b; if (x < 0) x += b; return x; }
	int Check(long n, long K) { return (n - n.ToString().Sum(c => c - '0')) % K == 0 ? 1 : 0; }
}