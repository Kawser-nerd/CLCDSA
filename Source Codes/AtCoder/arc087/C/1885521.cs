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
	Node root = new Node();
	readonly List<long> l = new List<long>();
	long L;
	public K()
	{
		var I = GL();
		var N = I[0];
		L = I[1];
		for (var i = 0; i < N; i++)
		{
			var s = Console.ReadLine();
			var n = root;
			for (var j = 0; j < s.Length; j++)
			{
				var x = s[j] - '0';
				n = n[x] = n[x] ?? new Node(n);
			}
		}
		DFS(root);
		var g = 0L;
		foreach (var x in l) g ^= F(x);
		Console.WriteLine(g != 0 ? "Alice" : "Bob");
	}
	long F(long n)
	{
		var c = 1L;
		while (n % 2 == 0) { c <<= 1; n >>= 1; }
		return c;
	}
	void DFS(Node n)
	{
		if (n == null) return;
		if (n.Count == 1) l.Add(L - n.Depth);
		DFS(n.Left);
		DFS(n.Right);
	}
}
class Node
{
	public Node Left, Right;
	public readonly int Depth;
	public Node this[int i] { get { return i == 0 ? Left : Right; } set { if (i == 0) Left = value; else Right = value; } }
	public int Count { get { return (Left == null ? 0 : 1) + (Right == null ? 0 : 1); } }
	public Node() { }
	public Node(Node p) { Depth = p.Depth + 1; }
}