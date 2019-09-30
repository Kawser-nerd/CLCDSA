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
		var I = G();
		int N = I[0], L = I[1];
		var xs = new int[N];
		var ys = new int[N];
		var ds = new int[N];
		for (var i = 0; i < N; i++)
		{
			var S = Console.ReadLine().Split();
			xs[i] = int.Parse(S[0]) - 1;
			ds[i] = S[1][0] == 'R' ? 1 : -1;
		}
		var l = 0;
		while (l < N && ds[l] < 0)
		{
			ys[l] = l;
			l++;
		}
		while (l < N)
		{
			var l2 = l + 1;
			while (l2 < N && ds[l2] > 0) l2++;
			if (l2 == N)
			{
				for (var i = N - 1; i >= l; i--) ys[i] = L - N + i;
				break;
			}
			else
			{
				var r = l2 + 1;
				while (r < N && ds[r] < 0) r++;
				var lc = l2 - l;
				var rc = r - l2;
				var med = lc <= rc ? xs[l2 - 1] + 1 : xs[l2];
				for (var i = l; i < r; i++) ys[i] = med + i - l2;
				l = r;
			}
		}
		var ans = 0L;
		for (var i = 0; i < N; i++) ans += Abs(xs[i] - ys[i]);
		Console.WriteLine(ans);
	}
}