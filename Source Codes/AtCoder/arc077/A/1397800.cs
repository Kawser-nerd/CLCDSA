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
class Z { static void Main() => new K(); }
class K
{
	int F() => int.Parse(ReadLine());
	long FL() => int.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F();
		var a = G();
		var b = new List<int>(N);
		for (var i = N - 1; i >= 0; i -= 2) b.Add(a[i]);
		for (var i = N % 2; i < N; i += 2) b.Add(a[i]);
		Console.WriteLine(string.Join(" ", b));
	}
	public static List<long> GetPrimes(long n)
	{
		if (n < 3) n = 3;
		var m = (n - 1) >> 1;
		var primes = new List<long>();
		primes.Add(2);
		var composites = new bool[m];
		composites[0] = false;
		for (var p = 0L; p < m; p++)
		{
			if (!composites[p])
			{
				var pnum = 2 * p + 3;
				primes.Add(pnum);
				for (var k = 3 * p + 3; k < m; k += pnum) composites[k] = true;
			}
		}
		return primes;
	}
}