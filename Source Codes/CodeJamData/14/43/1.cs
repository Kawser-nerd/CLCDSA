using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class C
{
	static int W, H;
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] parts = Console.ReadLine().Split();
			W = int.Parse(parts[0]);
			H = int.Parse(parts[1]);
			int B = int.Parse(parts[2]);
			bool[,] occ = new bool[W, H];
			for (int i = 0; i < B; i++)
			{
				parts = Console.ReadLine().Split();
				int X0 = int.Parse(parts[0]);
				int Y0 = int.Parse(parts[1]);
				int X1 = int.Parse(parts[2]);
				int Y1 = int.Parse(parts[3]);

				for (int x = X0; x <= X1; x++)
					for (int y = Y0; y <= Y1; y++)
						occ[x, y] = true;
			}
			MinCostMaxFlow mf = new MinCostMaxFlow(W * H * 2 + 2);
			int source = W * H * 2;
			int sink = source + 1;
			for (int x = 0; x < W; x++)
			{
				for (int y = 0; y < H; y++)
				{
					if (occ[x, y]) continue;

					mf.Add(num(x, y, true), num(x, y, false), 1, 0);

					if (y == 0) mf.Add(source, num(x, y, true), 1, 0);
					if (y == H - 1) mf.Add(num(x, y, false), sink, 1, 0);

					if (y > 0     && !occ[x, y - 1]) mf.Add(num(x, y, false), num(x, y - 1, true), 1, 0);
					if (y < H - 1 && !occ[x, y + 1]) mf.Add(num(x, y, false), num(x, y + 1, true), 1, 0);
					if (x > 0     && !occ[x - 1, y]) mf.Add(num(x, y, false), num(x - 1, y, true), 1, 0);
					if (x < W - 1 && !occ[x + 1, y]) mf.Add(num(x, y, false), num(x + 1, y, true), 1, 0);
				}
			}

			Console.WriteLine("Case #" + CASE + ": " + mf.NetworkFlow(source, sink).Cap);
		}
	}

	static int num(int x, int y, bool ing)
	{
		return y * W + x + (ing ? W * H : 0);
	}
}

public class MaxFlow
{
	class Edge
	{
		public int f, t, cap, flow;

		public Edge(int f, int t, int cap, int flow)
		{
			this.f = f;
			this.t = t;
			this.cap = cap;
			this.flow = flow;
		}
	}

	public int Nodes;
	LinkedList<Edge>[] Neighbours;

	public MaxFlow(int Nodes)
	{
		this.Nodes = Nodes;
		Neighbours = new LinkedList<Edge>[Nodes];
		for (int i = 0; i < Nodes; i++)
			Neighbours[i] = new LinkedList<Edge>();
	}

	public void Add(int From, int To, int Cap)
	{
		Edge e = new Edge(From, To, Cap, 0);
		Neighbours[From].AddLast(e);
		Neighbours[To].AddLast(e);
	}

	public int NetworkFlow(int From, int To)
	{
		Edge[] parent = new Edge[Nodes];
		int[] cap = new int[Nodes];

		int total = 0;
		while (true)
		{
			for (int i = 0; i < Nodes; i++)
				parent[i] = null;
			parent[From] = null;
			cap[From] = int.MaxValue;
			Queue<int> Q = new Queue<int>();
			Q.Enqueue(From);
			while (Q.Count > 0 && parent[To] == null)
			{
				int act = Q.Dequeue();
				foreach (Edge e in Neighbours[act])
				{
					int next = e.f == act ? e.t : e.f;
					if (parent[next] == null && next != From && (e.f == act ? e.cap > e.flow : e.cap < e.flow))
					{
						parent[next] = e;
						cap[next] = Math.Min(cap[act], e.f == act ? e.cap - e.flow : e.flow - e.cap);
						Q.Enqueue(next);
					}
				}
			}

			if (parent[To] == null)
				return total;

			total += cap[To];
			int j = To;
			while (j != From)
			{
				if (parent[j].f == j)
				{
					parent[j].flow -= cap[To];
					j = parent[j].t;
				}
				else
				{
					parent[j].flow += cap[To];
					j = parent[j].f;
				}
			}
		}
	}
}


public class MinCostMaxFlow
{
	public int Nodes;
	public LinkedList<Edge>[] Edges;

	public class Edge
	{
		public int from, to, cap, cost, flow;
		public Edge rev;

		public Edge(int f, int t, int ca, int co)
		{
			from = f;
			to = t;
			cap = ca;
			cost = co;
			flow = 0;
			rev = null;
		}
	}

	public struct Ret
	{
		public int Cost, Cap;
	}

	public MinCostMaxFlow(int Nodes)
	{
		this.Nodes = Nodes;
		Edges = new LinkedList<Edge>[Nodes];
		for (int i = 0; i < Nodes; i++)
			Edges[i] = new LinkedList<Edge>();
	}

	public void Add(int From, int To, int Cap, int Cost)
	{
		Edges[From].AddLast(new Edge(From, To, Cap, Cost));
	}

	public Ret NetworkFlow(int From, int To)
	{
		Edge[] parent = new Edge[Nodes];
		int[] dist = new int[Nodes];
		int[] cap = new int[Nodes];
		bool changed;
		Ret ret = new Ret();
		ret.Cap = 0;
		ret.Cost = 0;
		while (true)
		{
			bool[] done = new bool[Nodes];
			done[From] = true;
			cap[From] = int.MaxValue;
			Queue<int> Q = new Queue<int>();
			Q.Enqueue(From);
			while (Q.Count > 0)
			{
				int i = Q.Dequeue();
				foreach (Edge e in Edges[i])
				{
					if (e.cap > e.flow && !done[e.to])
					{
						changed = done[e.to] = true;
						parent[e.to] = e;
						cap[e.to] = Math.Min(cap[i], e.cap - e.flow);
						Q.Enqueue(e.to);
					}
				}
			}

			if (!done[To])
				return ret;

			ret.Cap += cap[To];
			ret.Cost += cap[To] * dist[To];

			int j = To;
			while (j != From)
			{
				if (parent[j].rev == null)
				{
					parent[j].rev = new Edge(parent[j].to, parent[j].from, 0, -parent[j].cost);
					parent[j].rev.rev = parent[j];
					Edges[parent[j].to].AddLast(parent[j].rev);
				}

				parent[j].flow += cap[To];
				parent[j].rev.flow -= cap[To];
				j = parent[j].from;
			}
		}
	}
}