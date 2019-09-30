using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Codeforces
{
	internal class Template
	{
		private void Solve()
		{
			var h = cin.NextInt();
			var w = cin.NextInt();
			var sx = 0;
			var sy = 0;
			var tx = 0;
			var ty = 0;
			var source = 0;
			var sink = 1;
			var hh = 2;
			var ww = hh + h;
			var graph = new MaxFlowGraph(2 + h + w);
			for (var i = 0; i < h; i++)
			{
				var line = cin.NextString();
				for (var j = 0; j < line.Length; j++)
				{
					if (line[j] == 'o')
					{
						graph.AddUndirectedEdge(i + hh, j + ww, 1);
					}
					else if (line[j] == 'S')
					{
						sy = i;
						sx = j;
						graph.AddUndirectedEdge(source, i + hh, 1000000000);
						graph.AddUndirectedEdge(source, j + ww, 1000000000);
					}
					else if (line[j] == 'T')
					{
						ty = i;
						tx = j;
						graph.AddUndirectedEdge(i + hh, sink, 1000000000);
						graph.AddUndirectedEdge(j + ww, sink, 1000000000);
					}
				}
			}
			if (sx == tx || sy == ty)
			{
				Console.WriteLine(-1);
				return;
			}
			var flow = graph.MaxFlow(source, sink);
			Console.WriteLine(flow);

		}

		public class MaxFlowDinic
		{
			public static long INF = 1l << 50;

			public long[] flow, capa;
			public int[] now, level, eadj, eprev, elast;
			public int eidx, N, M;

			public MaxFlowDinic(int nodes, int edges)
			{
				this.N = nodes;
				this.M = edges;

				flow = new long[2 * M];
				capa = new long[2 * M];
				eadj = new int[2 * M];
				eprev = new int[2 * M];
				elast = new int[N];
				level = new int[N];
				now = new int[N];
				elast.Fill(-1);
				eidx = 0;
			}

			public void add_edge(int a, int b, long c)
			{
				eadj[eidx] = b; flow[eidx] = 0; capa[eidx] = c; eprev[eidx] = elast[a]; elast[a] = eidx++;
				eadj[eidx] = a; flow[eidx] = c; capa[eidx] = c; eprev[eidx] = elast[b]; elast[b] = eidx++;
			}

			public long dinic(int source, int sink)
			{
				long res, flow = 0;
				while (bfs(source, sink))
				{
					Array.Copy(elast, 0, now, 0, N);
					while ((res = dfs(source, INF, sink)) > 0)
						flow += res;
				}
				return flow;
			}

			private bool bfs(int source, int sink)
			{
				level.Fill(-1);
				int front = 0, back = 0;
				int[] queue = new int[N];

				level[source] = 0;
				queue[back++] = source;

				while (front < back && level[sink] == -1)
				{
					int node = queue[front++];
					for (int e = elast[node]; e != -1; e = eprev[e])
					{
						int to = eadj[e];
						if (level[to] == -1 && flow[e] < capa[e])
						{
							level[to] = level[node] + 1;
							queue[back++] = to;
						}
					}
				}

				return level[sink] != -1;
			}

			private long dfs(int cur, long curflow, int goal)
			{
				if (cur == goal) return curflow;

				for (int e = now[cur]; e != -1; now[cur] = e = eprev[e])
				{
					if (level[eadj[e]] > level[cur] && flow[e] < capa[e])
					{
						long res = dfs(eadj[e], Math.Min(curflow, capa[e] - flow[e]), goal);
						if (res > 0)
						{
							flow[e] += res;
							flow[e ^ 1] -= res;
							return res;
						}
					}
				}
				return 0;
			}
		}



		public class MaxFlowGraph
		{
			public const int Inf = 1000000000;
			public readonly int N;
			public readonly int[,] Mates;
			public readonly int[,] Capacity;
			public int[,] Flow;

			public MaxFlowGraph(int numVertices)
			{
				N = numVertices;
				Mates = new int[N, N + 1];
				Capacity = new int[N, N];
				Flow = new int[N, N];
			}

			public void AddUndirectedEdge(int u, int v, int capacity)
			{
				Capacity[u, v] += capacity;
				Capacity[v, u] += capacity;
				Mates[u, ++Mates[u, 0]] = v;
				Mates[v, ++Mates[v, 0]] = u;
			}

			public void AddDirectedEdge(int u, int v, int capacity)
			{
				Capacity[u, v] += capacity;
				Mates[u, ++Mates[u, 0]] = v;
				Mates[v, ++Mates[v, 0]] = u;
			}

			private int[] _h, _e, _cur;
			private Queue<int> _q;
			public int MaxFlow(int from, int to)
			{
				_h = new int[N]; _e = new int[N]; _cur = new int[N];
				Flow = new int[N, N];
				_h[from] = N;
				for (int i = 0; i < N; ++i) _cur[i] = 1;
				_q = new Queue<int>();
				for (int i = 1; i <= Mates[from, 0]; ++i)
				{
					int v = Mates[from, i];
					Flow[from, v] = Capacity[from, v];
					Flow[v, from] = -Flow[from, v];
					_e[v] = Capacity[from, v];
					_q.Enqueue(v);
				}
				while (_q.Count > 0)
				{
					int u = _q.Dequeue();
					if (u == from || u == to) continue;
					Relax(u);
				}
				return _e[to];
			}

			void Lift(int u)
			{
				int minh = Inf;
				for (int i = 1; i <= Mates[u, 0]; ++i)
				{
					int v = Mates[u, i];
					if (Capacity[u, v] - Flow[u, v] > 0) minh = Math.Min(minh, _h[v]);
				}
				_h[u] = minh + 1;
			}

			void Push(int u, int v)
			{
				int d = Math.Min(Capacity[u, v] - Flow[u, v], _e[u]);
				_e[u] -= d; Flow[u, v] += d; Flow[v, u] = -Flow[u, v]; _e[v] += d;
			}

			void Relax(int u)
			{
				while (_e[u] > 0)
				{
					int v = Mates[u, _cur[u]];
					if (_cur[u] > Mates[u, 0])
					{
						Lift(u);
						_cur[u] = 1;
					}
					else if (Capacity[u, v] - Flow[u, v] > 0 && _h[u] == _h[v] + 1)
					{
						Push(u, v);
						_q.Enqueue(v);
						++_cur[u];
					}
					else ++_cur[u];
				}
			}
		}

		private static readonly Scanner cin = new Scanner();

		private static void Main()
		{
			new Template().Solve();
			Console.ReadLine();
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}

	public static class ArrayExtensions
	{
		public static void Fill<T>(this T[] originalArray, T with)
		{
			for (int i = 0; i < originalArray.Length; i++)
			{
				originalArray[i] = with;
			}
		}
	}
}