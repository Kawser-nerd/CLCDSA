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
		var A = G;
		int N = A[0], K = A[1], Q = A[2];
		A = G;
		var s = new HashSet<int>(A);
		var min = int.MaxValue;
		foreach (var y in s)
		{
			var small = new List<int>();
			var l = 0;
			while (l < N)
			{
				if (A[l] < y) { l++; continue; }
				var r = l + 1;
				while (r < N && A[r] >= y) r++;
				var t = new List<int>();
				for (var j = l; j < r; j++) t.Add(A[j]);
				t.Sort();
				small.AddRange(t.Take(t.Count - K + 1));
				l = r;
			}
			small.Sort();
			if (small.Count >= Q) min = Min(min, small[Q - 1] - y);
		}
		WriteLine(min);
	}
}