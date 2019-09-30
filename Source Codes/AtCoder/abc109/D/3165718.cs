using System.Collections.Generic;
using System.IO;
using System.Linq;
using static System.Console;
class Z { static void Main() => new K(); }
class K
{
	struct Point
	{
		public int X, Y;
		public Point(int x, int y) { X = x; Y = y; }
		public T At<T>(T[,] a) => a[X, Y];
		public bool In(int x, int y) => 0 <= X && X < x && 0 <= Y && Y < y;
		public Point Add(Point d) => new Point(X + d.X, Y + d.Y);
		public void Add(int[,] a, int v) { a[X, Y] += v; }
		public static IEnumerable<Query> GetPoints(int X, int Y)
		{
			var d = new Point(0, 1);
			var n = new Point(1, 0);
			for (var p = new Point(0, 0); p.In(X, Y);)
			{
				for (var q = p.Add(d); q.In(X, Y); p = q, q = q.Add(d)) yield return new Query(p, q);
				if (p.X < X - 1) yield return new Query(p, p.Add(n));
				p = p.Add(n);
				d.Y *= -1;
			}
		}
	}
	struct Query
	{
		public readonly Point From, To;
		public Query(Point f, Point t) { From = f; To = t; }
		public override string ToString() => $"{From.Y + 1} {From.X + 1} {To.Y + 1} {To.X + 1}";
	}
	int[] G => ReadLine().Split().Select(int.Parse).ToArray();
	public K()
	{
		SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
		Solve();
		Out.Flush();
	}
	int X, Y;
	int[,] map;
	readonly List<Query> qs = new List<Query>();
	void Solve()
	{
		var I = G;
		Y = I[0]; X = I[1];
		map = new int[X, Y];
		for (var y = 0; y < Y; y++)
		{
			I = G;
			for (var x = 0; x < X; x++) map[x, y] = I[x];
		}
		foreach (var q in Point.GetPoints(X, Y))
			if (q.From.At(map) % 2 == 1)
			{
				q.From.Add(map, -1);
				q.To.Add(map, 1);
				qs.Add(q);
			}
		WriteLine(qs.Count);
		foreach (var mv in qs) WriteLine(mv);
	}
}