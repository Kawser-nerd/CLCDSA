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
		var I = G();
		int N = I[0], M = I[1];
		var a = new int[N][];
		for (int i = 0; i < N; i++) a[i] = G().Select(x => x - 1).ToArray();
		var ng = new bool[M];
		var min = N + 1;
		for (var i = 0; i < M; i++)
		{
			var count = new int[M];
			for (int j = 0; j < N; j++)
				for (var k = 0; k < M; k++)
					if (!ng[a[j][k]])
					{
						count[a[j][k]]++;
						break;
					}
			//Console.WriteLine("ng = " + string.Join(", ", closed));
			//Console.WriteLine("c = " + string.Join(", ", count));
			var star = 0;
			for (var j = 0; j < M; j++) if (count[star] < count[j]) star = j;
			min = Min(min, count[star]);
			ng[star] = true;
		}
		WriteLine(min);
	}
}