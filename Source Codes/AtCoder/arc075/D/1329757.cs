#pragma warning disable
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Collections;
using static System.Math;
using static System.Console;
class E { static void Main() => new J(); }
class J
{
	const int Mod = 1000000007;
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	long D, ans;
	long[] pow = new long[20];
	void Solve()
	{
		D = F();
		pow[0] = 1;
		for (var i = 1; i < 20; i++) pow[i] = pow[i - 1] * 10;
		WriteLine(Calc(D));
	}
	long Calc(long D)
	{
		if (D % 9 != 0) return 0;
		D /= 9;
		ans = 0;
		for (var n = 1; n <= 18; n++) DFS(new int[n / 2], n, D, 0);
		return ans;
	}
	void DFS(int[] a, int n, long d, int i)
	{
		if (i == n / 2)
		{
			if (d != 0) return;
			var p = a[0] >= 0 ? 9L - a[0] : 10 + a[0];
			for (var j = 1; j < n / 2; j++) p *= 10 - Abs(a[j]);
			//Console.WriteLine($"n = {n}, a = ({string.Join(", ", a)})");
			ans += (n % 2 == 0 ? 1 : 10) * p;
		}
		else
		{
			var c = (pow[n - i - 1] - pow[i]) / 9;
			var t = d / c;
			if (d < 0 && d % c != 0) t--;
			//foreach (var z in new HashSet<long> { t, t + 1, t - 1, 9, -9, t + 2, t - 2 })
			foreach (var z in new HashSet<long> { t, t + 1 })
				if (-9 <= z && z <= 9)
				{
					a[i] = (int)z;
					DFS(a, n, d - z * c, i + 1);
				}
		}
	}
}