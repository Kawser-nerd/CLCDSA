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
		var S = Console.ReadLine().ToArray();
		var T = S.Reverse().ToArray();
		var A = Z(S);
		var C = Z(T);
		var N = S.Length;
		var ans = 0L;
		for (var i = 1; i < N; i++)
		{
			var a = Min(A[i], N - i - 1);
			var c = Min(C[N - i], N - i - 1);
			if (i > N - i && a > 0 && c > 0 && a + c >= N - i) ans += a + c - (N - i) + 1;
		}
		Console.WriteLine(ans);
	}
	int[] Z(IList<char> s)
	{
		int N = s.Count, i = 1, j = 0;
		var A = new int[N];
		A[0] = N;
		while (i < N)
		{
			while (i + j < N && s[j] == s[i + j]) ++j;
			A[i] = j;
			if (j == 0)
			{
				++i;
				continue;
			}
			var k = 1;
			while (i + k < N && k + A[k] < j)
			{
				A[i + k] = A[k];
				++k;
			}
			i += k;
			j -= k;
		}
		return A;
	}
}