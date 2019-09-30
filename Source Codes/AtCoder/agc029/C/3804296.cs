using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;
class Z { static void Main() => new K(); }
class K
{
	int F => int.Parse(Str);
	long FL => long.Parse(Str);
	int[] G => Strs.Select(int.Parse).ToArray();
	long[] GL => Strs.Select(long.Parse).ToArray();
	string Str => ReadLine();
	string[] Strs => Str.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
	const int MOD = 1000000007;
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	void Solve()
	{
		var N = F;
		var A = G;
		var flag = true;
		for (var i = 1; i < A.Length; i++) flag &= A[i - 1] < A[i];
		if (flag) { WriteLine(1); return; }
		// A < B
		// S < S + (0)*(B-A)
		// A > B
		// S > S[:i-1]+(c+1)+0*(B-i+1) (max S = c, i = min_i (S[i]=c) > 0, i < B)
		// aaaa < b, ab, aab, aaab, aaaaa
		// aaab < b, ab, aab, aaba, aaaba
		// aaba < b, ab, aba, aabb, aabaa
		// aabb < b, ab, aba, abaa, aabba
		// abaa < b, ba, abb, abab, abaaa
		// abab < b, ba, abb, abba, ababa
		// abba < b, ba, baa, abbb, abbaa
		// abbb < b, ba, baa, baaa, abbba
		// bbbb < c, ca, caa, caaa, bbbba
		// aa < aaa < ab < b < ba
		// var S = new List<int>();
		// for (var i = 0; i < A[0]; i++) S.Add(0);
		WriteLine(Func.FirstBinary(1, N, p => Check(A, p)));
	}
	bool Check(int[] A, int P)
	{
		var S = new Integer(A[0], P);
		S.Check();
		foreach (var a in A.Skip(1))
		{
			if (a > S.Length) { S.Add(a - S.Length); S.Check(); }
			else
			{
				S.Cut(a);
				S.Check();
				if (!S.Increment()) return false;
				S.Check();
			}
			if (S.Length != a) throw new Exception();
			// WriteLine(S);
		}
		return true;
	}
}
struct Block
{
	public readonly int Num, Count;
	public Block(int n, int c) { Num = n; Count = c; }
	public override string ToString() => $"({Num} * {Count})";
}
class Integer
{
	readonly List<Block> blocks;
	readonly List<int> sum; // sum[n] = Sum(i in [0,n), blocks[i].Count)
	int C;
	public int Length => sum[C];
	public readonly int P;
	public Integer(int n, int p) { blocks = new List<Block> { new Block(0, n) }; sum = new List<int> { 0, n }; C = 1; P = p; }
	public void Add(int c) { Add(new Block(0, c)); }
	Block Pop()
	{
		var x = blocks[C - 1];
		blocks.RemoveAt(C - 1);
		sum.RemoveAt(C);
		C--;
		return x;
	}
	void Add(Block b)
	{
		blocks.Add(b);
		sum.Add(sum[C] + b.Count);
		C++;
		Compress();
	}
	public void Check()
	{
		// return;
		if (C != blocks.Count || C + 1 != sum.Count) throw new Exception($"C={C}, blk={blocks.Count}, sum={sum.Count}");
		for (var i = Max(0, C - 4); i < C; i++) if (sum[i + 1] != sum[i] + blocks[i].Count) throw new Exception($"sum={string.Join(", ", sum)}, blocks={string.Join(", ", blocks.Select(b => b.Count))}");
		for (var i = Max(1, C - 4); i < C; i++) if (blocks[i - 1].Num == blocks[i].Num) throw new Exception($"blocks={string.Join(", ", blocks.Select(b => b.Num))}");
	}
	public void Cut(int c)
	{
		Block b = new Block();
		while (Length > c) b = Pop();
		if (Length < c) Add(new Block(b.Num, c - Length));
	}
	public bool Increment()
	{
		var x = blocks[C - 1].Count;
		// p*x => p*(x-1) P*1
		if (blocks[C - 1].Num == P - 1 && C == 1) return false;
		// n*p p*x => n*(p-1) (n+1)*1 0*x
		if (blocks[C - 1].Num == P - 1)
		{
			var n = blocks[C - 2].Num;
			var p = blocks[C - 2].Count;
			Pop(); Pop();
			if (p == 1)
			{
				Add(new Block(n + 1, 1));
				Add(new Block(0, x));
			}
			else
			{
				Add(new Block(n, p - 1));
				Add(new Block(n + 1, 1));
				Add(new Block(0, x));
			}
		}
		// n*x => n*(x-1) (n+1)*1
		else
		{
			var n = blocks[C - 1].Num;
			Pop();
			if (x == 1) Add(new Block(n + 1, 1));
			else
			{
				Add(new Block(n, x - 1));
				Add(new Block(n + 1, 1));
			}
		}
		return true;
	}
	public void Compress()
	{
		var i = C - 1;
		while (i > 0 && blocks[i].Num == blocks[i - 1].Num)
		{
			blocks[i - 1] = new Block(blocks[i - 1].Num, blocks[i - 1].Count + blocks[i].Count);
			sum[i] += blocks[i].Count;
			blocks.RemoveAt(i);
			sum.RemoveAt(i + 1);
			i--;
			C--;
		}
	}
	public override string ToString() => string.Join(" ", blocks);
}
static class Func
{
	public static int FirstBinary(int min, int max, Predicate<int> pred)
	{
		while (min < max)
		{
			var mid = (min + max) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
	}
}