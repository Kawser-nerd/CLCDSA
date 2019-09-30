using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F;
		var A = G;
		var cnt = new long[N + 1, 20];
		for (var i = 0; i < N; i++) for (var j = 0; j < 20; j++) { cnt[i + 1, j] = cnt[i, j] + ((A[i] & (1 << j)) != 0 ? 1 : 0); }
		var r = 0;
		var ans = 0L;
		for (var l = 0; l < N; l++)
		{
			while (r <= l) r++;
			while (r <= N)
			{
				var flag = true;
				for (var i = 0; flag && i < 20; i++) flag &= cnt[r, i] <= cnt[l, i] + 1;
				if (!flag) break;
				r++;
			}
			ans += r - l - 1;
		}
		WriteLine(ans);
	}
}