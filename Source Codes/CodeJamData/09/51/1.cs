using System;
using System.Collections.Generic;
using System.Text;

struct Box : IComparable<Box>
{
	public int x, y;

	public Box (int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	public int CompareTo (Box other)
	{
		if (this.x < other.x)
			return -1;
		if (this.x > other.x)
			return 1;

		return this.y.CompareTo (other.y);
	}
}

class Pos : IEquatable<Pos>
{
	static int bol;
	static int[] dx = new int[] { -1, 1, 0, 0};
	static int[] dy = new int[] { 0, 0, -1, 1};
	public List<Box> boxes;
	bool haz;

	public Pos ()
	{
		this.boxes = new List<Box> ();
		this.haz = false;
	}

	public void Add (int x, int y)
	{
		this.boxes.Add (new Box (x, y));
	}

	private void Go (int q)
	{
		bol |= 1 << q;

		for (int i = 0; i < this.boxes.Count; ++i)
			if ((bol & (1 << i)) == 0)
				if (Math.Abs (boxes[q].x - boxes[i].x) + Math.Abs (boxes[q].y - boxes[i].y) == 1)
					Go (i);
	}

	public void Finish ()
	{
		this.boxes.Sort ();
		bol = 0;
		Go (0);
		haz = bol != (1 << this.boxes.Count) - 1;
	}

	public Pos Dup ()
	{
		Pos res = new Pos ();
		foreach (Box b in boxes)
			res.boxes.Add (b);

		return res;
	}

	public IEnumerable<Pos> Gen (bool[,] map)
	{
		for (int i = 0; i < boxes.Count; ++i)
		{
			int x = boxes[i].x;
			int y = boxes[i].y;

			for (int d = 0; d < 4; ++d)
				if (map[x + dx[d], y + dy[d]] && map[x - dx[d], y - dy[d]])
			{
				bool ok = true;
				for (int q = 0; ok && q < boxes.Count; ++q)
					if (q != i)
				{
					if (boxes[q].x == x + dx[d] && boxes[q].y == y + dy[d])
						ok = false;
					if (boxes[q].x == x - dx[d] && boxes[q].y == y - dy[d])
						ok = false;
				}

				if (!ok)
					continue;

				Pos next = this.Dup ();
				next.boxes[i] = new Box (x + dx[d], y + dy[d]);
				next.Finish ();

				if (!this.haz || !next.haz)
					yield return next;
			}
		}
	}

	public bool Equals (Pos other)
	{
		for (int i = 0; i < boxes.Count; ++i)
			if (!this.boxes[i].Equals (other.boxes[i]))
				return false;

		return true;
	}

	public override int GetHashCode ()
	{
		int res = 0;
		foreach (Box b in boxes)
			res = 9001 * res + b.x * 12 + b.y;

		return res;
	}
}


public class A
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		A task = new A ();

		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}

	public string Solve ()
	{
		int r, c;
		string[] ss = Console.ReadLine ().Split (' ');
		r = int.Parse (ss[0]);
		c = int.Parse (ss[1]);

		bool[,] map = new bool[r + 2, c + 2];
		Pos start = new Pos ();
		Pos stop = new Pos ();

		for (int i = 0; i < r; ++i)
		{
			string s = Console.ReadLine ();
			for (int j = 0; j < c; ++j)
			{
				map[i + 1, j + 1] = s[j] != '#';

				if (s[j] == 'o' || s[j] == 'w')
					start.Add (i + 1, j + 1);
				if (s[j] == 'x' || s[j] == 'w')
					stop.Add (i + 1, j + 1);
			}
		}

		start.Finish ();
		stop.Finish ();

		Dictionary<Pos, bool> bol = new Dictionary<Pos, bool> ();
		List<Pos> now = new List<Pos> ();
		now.Add (start);
		bol[start] = true;

		int cnt = 0;

		while (!bol.ContainsKey (stop) && now.Count > 0)
		{
			++cnt;
			List<Pos> next = new List<Pos> ();

			foreach (Pos pos in now)
			{
				foreach (Pos pos2 in pos.Gen (map))
					if (!bol.ContainsKey (pos2))
				{
					bol[pos2] = true;
					next.Add (pos2);
				}
			}

			now = next;
		}

		if (now.Count == 0)
			return "-1";

		return cnt.ToString ();
	}
}
