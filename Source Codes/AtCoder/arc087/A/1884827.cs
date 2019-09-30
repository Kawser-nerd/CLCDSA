//#pragma warning disable
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
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => long.Parse(ReadLine());
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
		var N = F();
		var a = G();
		var ans = 0;
		var cnt = new Dictionary<int, int>();
		foreach (var x in a)
		{
			if (!cnt.ContainsKey(x)) cnt[x] = 1;
			else cnt[x]++;
		}
		foreach (var x in cnt.Keys)
		{
			if (cnt[x] >= x) ans += cnt[x] - x;
			else ans += cnt[x];
		}
		Console.WriteLine(ans);
	}
}