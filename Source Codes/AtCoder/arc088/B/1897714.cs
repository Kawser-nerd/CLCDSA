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
		var S = Console.ReadLine();
		var N = S.Length;
		var s = S.Select(c => c - '0').ToArray();
		var bit = new BinaryIndexedTree(s);
		int k = 0, l = 0, r = N;
		while (true)
		{
			var t = bit.Sum(l, r);
			if (t == 0 || t == r - l) break;
			bit.Add(l, -s[l]);
			bit.Add(r - 1, -s[r - 1]);
			l++; r--; k++;
		}
		Console.WriteLine(N - k);
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
	public BinaryIndexedTree(int[] array) : this(array.Length)
	{
		for (var i = 0; i < Size; i++) bit[i + 1] = array[i];
		for (var i = 1; i < Size; i++) if (i + (i & (-i)) <= Size) bit[i + (i & (-i))] += bit[i];
	}
	public void Add(int index, int value) { for (var i = index + 1; i <= Size; i += i & (-i)) bit[i] += value; }
	int Sum(int to) { var sum = 0; for (var i = to; i > 0; i -= i & (-i)) sum += bit[i]; return sum; }
	public int Sum(int from, int to) => Sum(to) - Sum(from);
}