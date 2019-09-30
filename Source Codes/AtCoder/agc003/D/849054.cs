using System;
using System.Collections.Generic;
class E { static void Main() { new K(); } }
class K
{
	public K()
	{
		var N = int.Parse(Console.ReadLine());
		var ps = GetPrimes(100100);
		var p2 = new Dictionary<long, int>();
		foreach (var p in ps) p2.Add(p * (long)p, p);
		var z = new long[N];
		var cnt = new Dictionary<long, int>();
		var w = new Dictionary<long, long>();
		for (var i = 0; i < N; i++)
		{
			var num = long.Parse(Console.ReadLine());
			var fact = new List<int>();
			var t = 1L;
			for (var j = 0; j < ps.Count; j++)
			{
				var x = ps[j];
				var cube = x * (long)x * x;
				if (cube > num) break;
				if (num % x == 0)
				{
					fact.Add(x);
					while (num % cube == 0) num /= cube;
					if (num % (x * (long)x) == 0) t *= x;
					else if (num % x == 0) t *= x * (long)x;
				}
			}
			z[i] = num;
			if (!w.ContainsKey(z[i]))
			{
				foreach (var p in fact) while (num % p == 0) num /= p;
				if (p2.ContainsKey(num))  t *= p2[num];
				else { if (num < 100100) t *= num * num; else t = -1; }
				w[z[i]] = t;
				cnt[z[i]] = 1;
			}
			else cnt[z[i]]++;
		}
		var sum = 0;
		var set = new HashSet<long>(z);
		var done = new HashSet<long>();
		if (set.Contains(1)) { sum++; set.Remove(1); }
		foreach (var x in set)
		{
			if (done.Contains(x)) continue;
			var y = w[x];
			if (cnt.ContainsKey(y)) sum += Math.Max(cnt[x], cnt[y]);
			else sum += cnt[x];
			done.Add(x);
			done.Add(y);
		}
		Console.WriteLine(sum);
	}
	List<int> GetPrimes(int n)
	{
		var m = (n - 1) >> 1;
		var primes = new List<int>((int)(n / Math.Log(n)));
		primes.Add(2);
		var composites = new bool[m];
		composites[0] = false;
		for (var p = 0; p < m; p++)
			if (!composites[p])
			{
				var pnum = 2 * p + 3;
				primes.Add(pnum);
				for (var k = 3 * p + 3; k < m; k += pnum) composites[k] = true;
			}
		return primes;
	}
}