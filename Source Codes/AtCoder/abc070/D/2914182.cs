using System;
using System.Linq;
using System.Collections.Generic;

namespace abc070_d
{
	class Program
	{
		static List<Tuple<int, long>>[] d;
		static bool[] visited;
		static long[] dist;
		static void dfs(int start, long cost)
		{
			visited[start] = true;
			dist[start] = cost;
			foreach (var tup in d[start])
			{
				if (!visited[tup.Item1])
				{
					dfs(tup.Item1, cost + tup.Item2);
				}
			}
			//visited[start] = false;
		}
		static void Main(string[] args)
		{
			int V = int.Parse(Console.ReadLine());
			d = new List<Tuple<int, long>>[V]; visited = new bool[V]; dist = new long[V];
			for (int i = 0; i < V; i++) d[i] = new List<Tuple<int, long>>();
			for (int i = 0; i < V - 1; i++)
			{
				int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
				x[0]--; x[1]--;
				d[x[0]].Add(new Tuple<int, long>(x[1], x[2]));
				d[x[1]].Add(new Tuple<int, long>(x[0], x[2]));
			}
			int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
			dfs(a[1] - 1, 0);
			for (int i = 0; i < a[0]; i++)
			{
				int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
				x[0]--; x[1]--;
				Console.WriteLine(dist[x[0]] + dist[x[1]]);
			}
		}
	}
}