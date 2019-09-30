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
		var A = G();
		int N = A[0], K = A[1];
		A = G();
		var cnt = new Dictionary<int, int>();
		foreach (var a in A)
		{
			if (!cnt.ContainsKey(a)) cnt[a] = 1;
			else cnt[a]++;
		}
		var k = cnt.Values.ToList();
		k.Sort();
		var c = 0;
		for (var i = 0; i < k.Count - K; i++) c += k[i];
		Console.WriteLine(c);
	}
}