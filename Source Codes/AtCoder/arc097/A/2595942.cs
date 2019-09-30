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
		var s = Str;
		var K = F;
		var min = new SortedSet<string>();
		for (var i = 0; i < s.Length; i++)
		{
			for (var l = 1; l <= 5 && i + l <= s.Length; l++)
			{
				var t = s.Substring(i, l);
				if (min.Count < 5) min.Add(t);
				else
				{
					var M = min.Max;
					if (t.CompareTo(M) < 0 && !min.Contains(t))
					{
						min.Remove(M);
						min.Add(t);
					}
				}
			}
		}
		WriteLine(min.ToList()[K - 1]);
	}
}