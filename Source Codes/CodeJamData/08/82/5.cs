using System;
using System.Collections.Generic;

public class B
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		B task = new B ();
		
		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}

	
	public string Solve ()
	{
		int n = int.Parse (Console.ReadLine ());

		Dictionary<string, Col> colors = new Dictionary<string, Col> ();
		
		for (int i = 0; i < n; ++i)
		{
			string[] ss = Console.ReadLine ().Split (' ');

			Col col;
			if (!colors.TryGetValue (ss[0], out col))
				colors.Add (ss[0], col = new Col ());
			
			col.ranges.Add (new Range (int.Parse (ss[1]), int.Parse (ss[2])));
		}

		List<Col> cols = new List<Col> (colors.Values);
		
		foreach (Col col in cols)
			col.Cleanup ();

		int best = int.MaxValue;

		int?[][] r = new int?[3][];
		
		for (int i = 0; i < cols.Count; ++i)
			for (int j = i; j < cols.Count; ++j)
				for (int k = j; k < cols.Count; ++k)
			{
				r[0] = cols[i].next;
				r[1] = cols[j].next;
				r[2] = cols[k].next;

				int to = 0;
				int used = 0;
				
				while (to < 10000 && used < best)
				{
					int next = -1;

					for (int q = 0; q < 3; ++q)
						if (r[q][to + 1].HasValue)
							next = Math.Max (next, r[q][to + 1].Value);
					
					if (next == -1)
						break;
					
					to = next;
					++used;
				}
				
				if (to == 10000)
					best = Math.Min (best, used);
			}

		if (best == int.MaxValue)
			return "IMPOSSIBLE";
		
		return best.ToString ();
	}
}

class Range : IComparable<Range>
{
	public Range (int a, int b)
	{
		this.a = a;
		this.b = b;
	}
	
	public int a, b;


	public int CompareTo (Range r)
	{
		if (this.a < r.a)
			return -1;
		if (this.a > r.a)
			return 1;
		if (this.b > r.b)
			return -1;
		if (this.b < r.b)
			return 1;
		return 0;
	}
}

class Col
{
	public Col ()
	{
		this.ranges = new List<Range> ();
	}
	
	public List<Range> ranges;
	public int?[] next;
	
	public void Cleanup ()
	{
		this.ranges.Sort ();
		
		int now = 1;
		
		while (now < ranges.Count)
		{
			if (ranges[now].a >= ranges[now - 1].a && ranges[now].b <= ranges[now - 1].b)
				ranges.RemoveAt (now);
			else
				++now;
		}

		next = new int?[10001];

		now = 0;
		int nextx = ranges[0].b;
		
		for (int i = ranges[0].a; i <= 10000; ++i)
		{
			while (now < ranges.Count && ranges[now].a <= i)
			{
				nextx = Math.Max (nextx, ranges[now].b);
				++now;
			}

			if (nextx >= i)
				next[i] = nextx;
		}
	}
	
}
