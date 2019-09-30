using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	public K()
	{
		var N = G[0];
		var A = G;
		WriteLine(FirstBinary(1, N, p => Check(A, p)));
	}
	int FirstBinary(int min, int max, Predicate<int> pred)
	{
		while (min < max)
		{
			var mid = (min + max) / 2;
			if (pred(mid)) max = mid;
			else min = mid + 1;
		}
		return min;
	}
	bool Check(int[] A, int P)
	{
		var S = new Integer(A[0], P);
		foreach (var a in A.Skip(1))
			if (a > S.Length) S.Add(a - S.Length);
			else
			{
				S.Cut(a);
				if (!S.Increment()) return false;
			}
		return true;
	}
}
struct Block
{
	public readonly int Num, Count;
	public Block(int n, int c) { Num = n; Count = c; }
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
		Block p = b;
		if (C > 0 && blocks[C - 1].Num == b.Num) p = new Block(b.Num, b.Count + Pop().Count);
		blocks.Add(p);
		sum.Add(sum[C] + p.Count);
		C++;
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
		if (blocks[C - 1].Num == P - 1 && C == 1) return false;
		// n*p p*x => n*(p-1) (n+1)*1 0*x
		if (blocks[C - 1].Num == P - 1)
		{
			var n = blocks[C - 2].Num;
			var p = blocks[C - 2].Count;
			Pop(); Pop();
			if (p > 1) Add(new Block(n, p - 1));
			Add(new Block(n + 1, 1));
			Add(new Block(0, x));
		}
		// n*x => n*(x-1) (n+1)*1
		else
		{
			var n = blocks[C - 1].Num;
			Pop();
			if (x > 1) Add(new Block(n, x - 1));
			Add(new Block(n + 1, 1));
		}
		return true;
	}
}