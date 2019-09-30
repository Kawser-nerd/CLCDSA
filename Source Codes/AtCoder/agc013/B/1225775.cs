using System.Collections.Generic;
using System.IO;
using System.Linq;
using System;
using static System.Math;
using static System.Console;

class E { static void Main() => new J(); }
class J
{
	int F() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	int MOD = 1000000007;
	public J()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var I = G();
		int N = I[0], M = I[1];
		var es = new List<int>[N];
		for (var i = 0; i < N; i++) es[i] = new List<int>();
		for (var i = 0; i < M; i++)
		{
			I = G(); I[0]--; I[1]--;
			es[I[0]].Add(I[1]);
			es[I[1]].Add(I[0]);
		}
		var ans = new List<int>{ I[0] };
		var s = new HashSet<int>{ I[0], I[1] };
		while (true)
		{
			var u = ans.Last();
			var flag = false;
			foreach (var v in es[u])
				if (!s.Contains(v))
				{
					ans.Add(v);
					s.Add(v);
					flag = true;
					break;
				}
			if (!flag) break;
		}
		var ans2 = new List<int>{ I[1] };
		while (true)
		{
			var u = ans2.Last();
			var flag = false;
			foreach (var v in es[u])
				if (!s.Contains(v))
				{
					ans2.Add(v);
					s.Add(v);
					flag = true;
					break;
				}
			if (!flag) break;
		}
		ans2.Reverse();
		ans2.AddRange(ans);
		WriteLine(ans2.Count);
		WriteLine(string.Join(" ", ans2.Select(i => i + 1)));
	}
}