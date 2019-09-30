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
class E { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	uint[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(uint.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		//SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		//Out.Flush();
	}
	int N;
	uint[][] surf;
	int[] per;
	ulong[] hash;
	Dictionary<ulong, int> cnt = new Dictionary<ulong, int>();
	void Solve()
	{
		N = F();
		surf = new uint[N][];
		per = new int[N];
		hash = new ulong[N];
		for (var i = 0; i < N; i++)
		{
			surf[i] = G();
			per[i] = Period(surf[i][0], surf[i][1], surf[i][2], surf[i][3]);
			if (per[i] == 1) hash[i] = Hash1(surf[i][0]);
			else if (per[i] == 2) hash[i] = Hash2(surf[i][0], surf[i][1]);
			else hash[i] = Hash(surf[i][0], surf[i][1], surf[i][2], surf[i][3]);
			if (!cnt.ContainsKey(hash[i])) cnt[hash[i]] = 0;
			cnt[hash[i]]++;
		}
		var e = 0L;
		for (var i = 0; i < N; i++)
			for (var j = 0; j < i; j++)
			{
				var count = 0L;
				cnt[hash[i]]--;
				cnt[hash[j]]--;
				for (var rj = 0; rj < per[j]; rj++)
				{
					var x = surf[i];
					var y = new uint[4];
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
						if (!cnt.ContainsKey(h))
						{
							p = 0;
							break;
						}
						if (!dup.ContainsKey(h)) dup[h] = 0;
						p *= (4 / Period(h)) * (cnt[h] - dup[h]);
						dup[h]++;
					}
					count += p;
				}
				e += count * (4 / per[j]);
				cnt[hash[i]]++;
				cnt[hash[j]]++;
			}
		Console.WriteLine(e / 3);
	}
	static ulong Hash(uint i, uint j, uint k, uint l)
	{
		var a = ((ulong)i << 30) | ((ulong)j << 20) | (k << 10) | l;
		a = Math.Min(a, ((ulong)j << 30) | ((ulong)k << 20) | (l << 10) | i);
		a = Math.Min(a, ((ulong)k << 30) | ((ulong)l << 20) | (i << 10) | j);
		a = Math.Min(a, ((ulong)l << 30) | ((ulong)i << 20) | (j << 10) | k);
		return a;
	}
	static ulong Hash1(uint i)
	{
		return ((ulong)i << 30) | ((ulong)i << 20) | (i << 10) | i;
	}
	static ulong Hash2(uint i, uint j)
	{
		if (i > j) return ((ulong)j << 30) | ((ulong)i << 20) | (j << 10) | i;
		return ((ulong)i << 30) | ((ulong)j << 20) | (i << 10) | j;
	}
	const ulong p1 = (1 << 30) | (1 << 20) | (1 << 10) | 1;
	const ulong p2 = (1 << 20) | 1;
	static int Period(ulong h)
	{
		return h % p2 == 0 ? h % p1 == 0 ? 1 : 2 : 4;
	}
	static int Period(uint i, uint j, uint k, uint l)
	{
		return i == k && j == l ? i == j ? 1 : 2 : 4;
	}
}