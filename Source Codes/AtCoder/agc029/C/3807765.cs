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
				S.Take(a);
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
	readonly Stack<Block> blocks;
	readonly Stack<int> sum; // sum[n] = Sum(i in [0,n), blocks[i].Count)
	public int Length => sum.Peek();
	public readonly int P;
	public Integer(int n, int p) { blocks = new Stack<Block>(); blocks.Push(new Block(0, n)); sum = new Stack<int>(); sum.Push(0); sum.Push(n); P = p; }
	public void Add(int c) => Push(new Block(0, c));
	Block Pop()
	{
		var x = blocks.Pop();
		sum.Pop();
		return x;
	}
	void Push(Block b)
	{
		if (b.Count == 0) return;
		Block p = b;
		if (Length > 0 && blocks.Peek().Num == b.Num) p = new Block(b.Num, b.Count + Pop().Count);
		blocks.Push(p);
		sum.Push(Length + p.Count);
	}
	public void Take(int c)
	{
		var b = new Block();
		while (Length > c) b = Pop();
		if (Length < c) Push(new Block(b.Num, c - Length));
	}
	public bool Increment()
	{
		var b = Pop();
		var x = b.Num;
		var n = b.Count;
		if (x == P - 1 && Length == 0) return false;
		// y*m x*n => y*(m-1) (y+1)*1 0*n
		if (x == P - 1)
		{
			b = Pop();
			var y = b.Num;
			var m = b.Count;
			Push(new Block(y, m - 1));
			Push(new Block(y + 1, 1));
			Push(new Block(0, n));
		}
		// x*n => x*(n-1) (x+1)*1
		else
		{
			Push(new Block(x, n - 1));
			Push(new Block(x + 1, 1));
		}
		return true;
	}
}