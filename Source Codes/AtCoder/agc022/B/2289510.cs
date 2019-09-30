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
	long FL() => long.Parse(ReadLine());
	int[] G() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
	long[] GL() => ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).Select(long.Parse).ToArray();
	public const int MOD = 1000000007;
	public K()
	{
		//for (var i = 3; i < 1000; i++) Solve(i);
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		WriteLine(string.Join(" ", Solve(F())));
		Out.Flush();
	}
	IList<int> Solve(int N)
	{
		if (N == 3) return new[] { 2, 3, 25 };
		var M = 30000;
		var good = new SortedSet<int>();
		for (var p = 2; p <= M; p += 2) good.Add(p);
		for (var p = 3; p <= M; p += 3) good.Add(p);
		var ans = new HashSet<int>();
		var tmp = good.ToArray();
		for (var i = 0; i < N - 2; i++) ans.Add(tmp[i]);
		var s = ans.Sum(i => (long)i);
		for (var j = 0; j < 6; j++)
			for (var k = j; k < 6; k++)
				if ((s + j + k) % 6 == 0)
					for (var a = j; a <= M; a += 6)
						if (!ans.Contains(a))
							for (var b = k; b <= M; b += 6)
								if (!ans.Contains(b) && a != b && GCD(s + b, a) > 1 && GCD(s + a, b) > 1 && a > 1 && b > 1)
								{
									ans.Add(a);
									ans.Add(b);
									return ans.ToList();
								}
		return null;
	}
	public static long GCD(long a, long b)
	{
		var n = (ulong)Abs(a); var m = (ulong)Abs(b);
		if (n == 0) return (long)m; if (m == 0) return (long)n;
		int zm = 0, zn = 0;
		while ((n & 1) == 0) { n >>= 1; zn++; }
		while ((m & 1) == 0) { m >>= 1; zm++; }
		while (m != n)
		{
			if (m > n) { m -= n; while ((m & 1) == 0) m >>= 1; }
			else { n -= m; while ((n & 1) == 0) n >>= 1; }
		}
		return (long)n << Min(zm, zn);
	}
}