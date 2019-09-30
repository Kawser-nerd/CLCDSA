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
		var B = G();
		var rev = new int[N];
		var bit = new BinaryIndexedTree(N);
		for (var i = 0; i < N; i++)
		{
			rev[--B[i]] = i;
			bit.Add(i, 1);
		}
		var s = 0L;
		for (var i = 0; i < N; i++)
		{
			s += Min(bit.Sum(0, rev[i]), bit.Sum(rev[i] + 1, N));
			bit.Add(rev[i], -1);
		}
		WriteLine(s);
	}
}
class BinaryIndexedTree
{
	public int Size { get; private set; }
	readonly int[] bit;
	public BinaryIndexedTree(int s)
	{
		Size = s;
		bit = new int[s + 1];
	}
	public void Add(int index, int value) { for (var i = index + 1; i <= Size; i += i & (-i)) bit[i] += value; }
	public int Sum(int from, int to) => Sum(to) - Sum(from);
	int Sum(int to) { var sum = 0; for (var i = to; i > 0; i -= i & (-i)) sum += bit[i]; return sum; }
}