using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using System.Numerics;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		WriteLine(YesNo() ? "YES" : "NO");
	}
	bool YesNo()
	{
		var I = G();
		int N = I[0], K = I[1];
		var S = Console.ReadLine();
		var count = new int[26];
		for (var i = 0; i < K; i++) count[S[i] - 'a']++;
		var x = new List<Tuple<int,int[]>>{ new Tuple<int, int[]>(0, (int[])count.Clone()) };
		for (var i = 1; i <= N - K; i++)
		{
			count[S[i - 1] - 'a']--;
			count[S[i + K - 1] - 'a']++;
			x.Add(new Tuple<int, int[]>(i, (int[])count.Clone()));
		}
		x.Sort(Comp);
		for (var i = 0; i < x.Count; )
		{
			var tmp = new List<int>();
			var j = i;
			while (j < x.Count && Comp(x[i], x[j]) == 0)
			{
				tmp.Add(x[j].Item1);
				j++;
			}
			if (tmp.Max() - tmp.Min() >= K) return true;
			i = j;
		}
		return false;
	}
	int Comp(Tuple<int,int[]> a, Tuple<int,int[]> b)
	{
		for (var i = 0; i < a.Item2.Length; i++)
		{
			var c = a.Item2[i].CompareTo(b.Item2[i]);
			if (c != 0) return c;
		}
		return 0;
	}
}