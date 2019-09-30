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
		var cnt = 0;
		while (true)
		{
			int i = 0, j = 0;
			for (var k = 0; k < 3; k++)
			{
				if (I[k] > I[i]) i = k;
				if (I[k] < I[j]) j = k;
			}
			if (I[i] - I[j] >= 2)
			{
				var k = (I[i] - I[j]) / 2;
				I[j] += 2 * k;
				cnt += k;
				continue;
			}
			WriteLine(cnt + I.Count(x => x != I[j]));
			return;
		}
	}
}