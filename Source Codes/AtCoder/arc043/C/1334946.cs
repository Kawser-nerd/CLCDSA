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
		var N = F();
		var A = G();
		var B = G();
		var rev = new int[N];
		for (var i = 0; i < N; i++) rev[--A[i]] = i;
		for (var i = 0; i < N; i++) B[i] = rev[B[i] - 1];
		var inv = new int[N];
		var s = 0L;
		var bit = new BinaryIndexedTree(N);
		for (var i = 0; i < N; i++)
		{
			s += inv[B[i]] = bit.Sum(B[i], N);
			bit.Add(B[i], 1);
		}
		if (s % 2 == 1) Console.WriteLine(-1);
		else
		{
			if (s > 0)
			{
				s /= 2;
				var done = 0;
				while (s >= inv[done]) s -= inv[done++];
				var k = N - 1;
				for (var j = N - 1; j >= done; j--)
				{
					while (B[k] < done) k--;
					B[j] = B[k--];
				}
				for (var j = 0; j < done; j++) B[j] = j;
				for (var j = done; s > 0 && j < N; j++)
				{
					for (k = N - 1; s > 0 && k > j; k--)
						if (B[k - 1] > B[k])
						{
							var t = B[k];
							B[k] = B[k - 1];
							B[k - 1] = t;
							s--;
						}
				}
			}
			for (var i = 0; i < N; i++) B[i] = A[B[i]] + 1;
			Console.WriteLine(string.Join(" ", B));
		}
	}
}
class BinaryIndexedTree
{
	public readonly int Size;
	readonly int[] bit;
	public BinaryIndexedTree(int size)
	{
		Size = size;
		bit = new int[size + 1];
	}
	public void Add(int index, int value) { for (var i = index + 1; i <= Size; i += i & (-i)) bit[i] += value; }
	public int Sum(int from, int to) => Sum(to) - Sum(from);
	int Sum(int to) { var sum = 0; for (var i = to; i > 0; i -= i & (-i)) sum += bit[i]; return sum; }
}