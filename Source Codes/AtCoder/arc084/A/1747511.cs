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
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F();
		var A = G();
		var B = G();
		var C = G();
		Array.Sort(A);
		Array.Sort(B);
		Array.Sort(C);
		var s = 0L;
		int i = 0, k = 0;
		for (var j = 0; j < N; j++)
		{
			while (i < N && A[i] < B[j]) i++;
			while (k < N && B[j] >= C[k]) k++;
			s += i * (long)(N - k);
		}
		Console.WriteLine(s);
	}
}