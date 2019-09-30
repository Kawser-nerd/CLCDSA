using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			int N = int.Parse(Console.ReadLine());
			string[][] sent = new string[N][];
			for (int i = 0; i < N; i++)
				sent[i] = Console.ReadLine().Split();

			HashSet<string> en = new HashSet<string>();
			for (int i = 0; i < sent[0].Length; i++)
				en.Add(sent[0][i]);

			HashSet<string> fr = new HashSet<string>();
			for (int i = 0; i < sent[1].Length; i++)
				fr.Add(sent[1][i]);

			HashSet<string> overlap = new HashSet<string>(en);
			overlap.IntersectWith(fr);

			HashSet<string>[] realSent = new HashSet<string>[N];
			realSent[0] = new HashSet<string>();
			realSent[1] = new HashSet<string>();
			for (int i = 2; i < N; i++)
			{
				realSent[i] = new HashSet<string>();
				for (int j = 0; j < sent[i].Length; j++)
				{
					if (overlap.Contains(sent[i][j])) continue;

					if (en.Contains(sent[i][j]))
						realSent[0].Add(sent[i][j]);
					if (fr.Contains(sent[i][j]))
						realSent[1].Add(sent[i][j]);
					realSent[i].Add(sent[i][j]);
				}
			}

			Console.WriteLine("Case #" + CASE + ": " + (overlap.Count + Solve(realSent)));
		}

	}

	public static int Solve(HashSet<string>[] sent)
	{
		int N = sent.Length;
		Dictionary<string, int> words = new Dictionary<string, int>();
		int[][] ws = new int[N][];
		for (int i = 0; i < N; i++)
		{
			ws[i] = new int[sent[i].Count];
			int j = 0;
			foreach (string w in sent[i])
			{
				if (!words.ContainsKey(w))
					words[w] = words.Count;
				ws[i][j++] = words[w];
			}
		}

		MaxFlow mf = new MaxFlow(N + words.Count * 2);
		for (int i = 0; i < words.Count; i++)
			mf.Add(N + i, N + words.Count + i, 1);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < ws[i].Length; j++)
			{
				mf.Add(i, N + ws[i][j], 1);
				mf.Add(N + words.Count + ws[i][j], i, 1);
			}
		}

		return mf.NetworkFlow(0, 1);
	}

	public class MaxFlow
	{
		public int Nodes;
		public int[,] Capacity;
		LinkedList<int>[] Neighbours;
		bool[,] NeighbourAdded;

		public MaxFlow(int Nodes)
		{
			this.Nodes = Nodes;
			Neighbours = new LinkedList<int>[Nodes];
			for (int i = 0; i < Nodes; i++)
				Neighbours[i] = new LinkedList<int>();
			Capacity = new int[Nodes, Nodes];
			NeighbourAdded = new bool[Nodes, Nodes];
		}

		public void Add(int From, int To, int Cap)
		{
			Capacity[From, To] += Cap;
			if (!NeighbourAdded[From, To])
			{
				NeighbourAdded[From, To] = true;
				NeighbourAdded[To, From] = true;
				Neighbours[From].AddLast(To);
				Neighbours[To].AddLast(From);
			}
		}

		public int NetworkFlow(int From, int To)
		{
			int[,] flow = new int[Nodes, Nodes];
			int[] parent = new int[Nodes];
			int[] cap = new int[Nodes];

			int total = 0;
			while (true)
			{
				for (int i = 0; i < Nodes; i++)
					parent[i] = -1;
				parent[From] = -2;
				cap[From] = int.MaxValue;
				Queue<int> Q = new Queue<int>();
				Q.Enqueue(From);
				while (Q.Count > 0 && parent[To] == -1)
				{
					int act = Q.Dequeue();
					foreach (int next in Neighbours[act])
					{
						if (parent[next] == -1 && Capacity[act, next] > flow[act, next])
						{
							parent[next] = act;
							cap[next] = Math.Min(cap[act], Capacity[act, next] - flow[act, next]);
							Q.Enqueue(next);
						}
					}
				}

				if (parent[To] == -1)
					return total;

				total += cap[To];
				int j = To;
				while (j != From)
				{
					flow[parent[j], j] += cap[To];
					flow[j, parent[j]] -= cap[To];
					j = parent[j];
				}
			}
		}
	}


	/*
	public static int Solve(HashSet<string>[] sent)
	{
		int N = sent.Length;
		Dictionary<string, int> words = new Dictionary<string, int>();
		int[][] ws = new int[N][];
		for (int i = 0; i < N; i++)
		{
			ws[i] = new int[sent[i].Count];
			int j = 0;
			foreach(string w in sent[i])
			{
				if (!words.ContainsKey(w))
					words[w] = words.Count;
				ws[i][j++] = words[w];
			}
		}


		int ans = int.MaxValue;
		for (int i = 0; i < (1 << (N - 2)); i++)
		{
			bool[] en = new bool[words.Count];
			bool[] fr = new bool[words.Count];
			int cur = 0;
			for (int j = 0; j < N; j++)
			{
				bool isEn = (j == 0 || (j != 1 && ((1 << (j - 2)) & i) > 0));
				for (int k = 0; k < ws[j].Length; k++)
				{

					if (isEn && !en[ws[j][k]])
					{
						if (fr[ws[j][k]]) cur++;
						en[ws[j][k]] = true;
					}
					else if (!isEn && !fr[ws[j][k]])
					{
						if (en[ws[j][k]]) cur++;
						fr[ws[j][k]] = true;
					}
				}
			}

			ans = Math.Min(ans, cur);
		}

		return ans;
	}
	 * */
}
