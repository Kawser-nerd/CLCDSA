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
		var I = G;
		int N = I[0], M = I[1];
		var qs = new List<Query>(M);
		for (var i = 0; i < M; i++) qs.Add(new Query(G));
		qs.Sort();
		var s = 0;
		for (var i = 0; i < M; )
		{
			var j = i + 1;
			while (j < M && qs[j].L < qs[i].R) j++;
			s++;
			i = j;
		}
		WriteLine(s);
	}
}
struct Query : IComparable<Query>
{
	public readonly int L, R;
	public Query(int[] i) { L = i[0] - 1; R = i[1] - 1; }
	public int CompareTo(Query query) => R.CompareTo(query.R);
}