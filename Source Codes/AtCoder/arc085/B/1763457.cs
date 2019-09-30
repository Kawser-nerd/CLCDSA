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
struct P : IEquatable<P>, IComparable<P>
{
	public readonly int Player, Left, Card;
	public P(int p, int q, int r)
	{
		Player = p;
		Left = q;
		Card = r;
	}
	public bool Equals(P p) => Player == p.Player && Left == p.Left && Card == p.Card;
	public override bool Equals(object obj) => obj is P && Equals((P)obj);
	public override int GetHashCode() => Player.GetHashCode() ^ Left.GetHashCode() ^ Card.GetHashCode();
	public override string ToString() => string.Format("({0}, {1}, {2})", Player == 0 ? "X" : "Y", Left, Card);
	public int CompareTo(P p) => Left == p.Left ? Player == p.Player ? Card.CompareTo(p.Card) : Player.CompareTo(p.Player) : Left.CompareTo(p.Left);
}
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
	readonly Dictionary<P, int> memo = new Dictionary<P, int>();
	int N, Y;
	int[] a;
	void Solve()
	{
		a = G();
		N = a[0];
		Y = a[2];
		a = G();
		Console.WriteLine(Calc(0, 0, Y));
		//Console.WriteLine(Calc2(1, 0, Y));
		//var t = memo.Keys.ToList();
		//t.Sort();
		// foreach (var k in t) Console.WriteLine($"{k} -> {memo[k]}");
	}
	// ?? p ?????????, a[q], ..., a[N-1] ??????????,
	// p ??????????? r ?????????????, p ?????????????
	// p = 0 -> X, p = 1 -> Y
	int Calc(int p, int q, int r)
	{
		var k = new P(p, q, r);
		Set(k);
		return memo[k];
	}
	readonly Func<int,int,bool>[] c = { Comp, Comp2 };
	static bool Comp(int a, int b) => a > b;
	static bool Comp2(int a, int b) => a < b;
	void Set(P k)
	{
		if (memo.ContainsKey(k)) return;
		//memo[k] = a[N - 1];
		memo[k] = Abs(a[N - 1] - k.Card);
		for (var i = k.Left; i < N - 1; i++)
		{
			var t = Calc(1 - k.Player, i + 1, a[i]);
			if (c[k.Player](t, memo[k]))
			{
				//memo[k] = a[i];
				memo[k] = t;
			}
		}
	}
}