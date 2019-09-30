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
		var d = new Dictionary<int, int>();
		foreach (var a in A)
		{
			if (!d.ContainsKey(a)) d[a] = 0;
			d[a]++;
		}
		var ans = 0;
		var ks = d.Keys.ToList();
		ks.Sort((x, y) => y.CompareTo(x));
		var pow = new List<int>();
		var q = 1L;
		while (q < int.MaxValue)
		{
			pow.Add((int)q);
			q *= 2;
		}
		foreach (var k in ks)
		{
			if (!d.ContainsKey(k)) continue;
			foreach (var p in pow)
			{
				if (d.ContainsKey(p - k))
				{
					if (p - k != k)
					{
						var pair = Min(d[k], d[p - k]);
						if (d[p - k] <= pair) d.Remove(p - k);
						else d[p - k] -= pair;
						ans += pair;
					}
					else ans += d[k] / 2;
					d.Remove(k);
					break;
				}
			}
		}
		WriteLine(ans);
	}
}