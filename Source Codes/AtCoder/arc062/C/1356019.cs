using System.Collections.Generic;
using System.Linq;
using System;
using static System.Math;
using static System.Console;
class E { static void Main() => new K(); }
class K
{
	public K()
	{
		var N = int.Parse(ReadLine());
		var surf = new uint[N][];
		var per = new int[N];
		var hash = new ulong[N];
		var dict = new Dictionary<ulong, int>();
		for (var i = 0; i < N; i++)
		{
			surf[i] = ReadLine().Split().Select(uint.Parse).ToArray();
			per[i] = surf[i][0] == surf[i][2] && surf[i][1] == surf[i][3] ? surf[i][0] == surf[i][1] ? 1 : 2 : 4;
			if (per[i] == 1) hash[i] = Hash1(surf[i][0]);
			else if (per[i] == 2) hash[i] = Hash2(surf[i][0], surf[i][1]);
			else hash[i] = Hash(surf[i][0], surf[i][1], surf[i][2], surf[i][3]);
			if (!dict.ContainsKey(hash[i])) dict[hash[i]] = 0;
			dict[hash[i]]++;
		}
		var a = 0L;
		var y = new uint[4];
		for (var i = 0; i < N; i++)
			for (var j = i + 1; j < N; j++)
			{
				var count = 0L;
				dict[hash[i]]--;
				dict[hash[j]]--;
				for (var rj = 0; rj < per[j]; rj++)
				{
					var x = surf[i];
					for (var k = 0; k < 4; k++) y[k] = surf[j][(k + rj) % 4];
					var s = new[] {
						Hash(y[3], y[2], x[3], x[2]),
						Hash(y[2], y[1], x[0], x[3]),
						Hash(y[1], y[0], x[1], x[0]),
						Hash(y[0], y[3], x[2], x[1])
					};
					var p = 1L;
					var dup = new Dictionary<ulong, int>();
					foreach (var h in s)
					{
						if (!dict.ContainsKey(h)) { p = 0; break; }
						if (!dup.ContainsKey(h)) dup[h] = 0;
						p *= (h % p2 == 0 ? h % p1 == 0 ? 4 : 2 : 1) * (dict[h] - dup[h]);
						dup[h]++;
					}
					count += p;
				}
				a += count * (4 / per[j]);
				dict[hash[i]]++;
				dict[hash[j]]++;
			}
		WriteLine(a / 3);
	}
	static ulong Hash(uint i, uint j, uint k, uint l)
	{
		var a = ((ulong)i << 30) | (j << 20) | (k << 10) | l;
		a = Min(a, ((ulong)j << 30) | (k << 20) | (l << 10) | i);
		a = Min(a, ((ulong)k << 30) | (l << 20) | (i << 10) | j);
		a = Min(a, ((ulong)l << 30) | (i << 20) | (j << 10) | k);
		return a;
	}
	static ulong Hash1(uint i) => ((ulong)i << 30) | (i << 20) | (i << 10) | i;
	static ulong Hash2(uint i, uint j)
	{
		if (i > j) return ((ulong)j << 30) | (i << 20) | (j << 10) | i;
		return ((ulong)i << 30) | (j << 20) | (i << 10) | j;
	}
	const ulong p1 = (1 << 30) | (1 << 20) | (1 << 10) | 1;
	const ulong p2 = (1 << 20) | 1;
}