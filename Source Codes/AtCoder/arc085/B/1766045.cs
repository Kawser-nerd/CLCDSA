using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using static System.Console;
class Z { static void Main() => new K(); }
struct P : IEquatable<P>
{
	public readonly int Player, Left, Card;
	public P(int p, int q, int r) { Player = p; Left = q; Card = r; }
	public bool Equals(P p) => Player == p.Player && Left == p.Left && Card == p.Card;
}
class K
{
	int[] G() => ReadLine().Split().Select(int.Parse).ToArray();
	public K()
	{
		a = G();
		N = a[0];
		Y = a[2];
		a = G();
		WriteLine(Calc(0, 0, Y));
	}
	int N, Y;
	readonly int[] a;
	readonly Dictionary<P, int> memo = new Dictionary<P, int>();
	readonly Func<int, int, int>[] c = { Max, Min };
	int Calc(int p, int q, int r)
	{
		var k = new P(p, q, r);
		if (!memo.ContainsKey(k))
		{
			memo[k] = Abs(a[N - 1] - r);
			for (var i = q; i < N - 1; i++) memo[k] = c[k.Player](memo[k], Calc(1 - p, i + 1, a[i]));
		}
		return memo[k];
	}
}