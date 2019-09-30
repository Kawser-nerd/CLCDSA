using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _037
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            List<int>[] graph = new List<int>[n];
            for (int i = 0; i < n; i++) graph[i] = new List<int>();
            for(int i = 0; i < m; i++)
            {
                int[] uv = ReadInts();
                int u = uv[0] - 1;
                int v = uv[1] - 1;
                graph[u].Add(v);
                graph[v].Add(u);
            }
            bool[] visited = new bool[n];
            int res = 0;
            for(int i = 0; i < n; i++)
            {
                if (visited[i]) continue;

                int[] nodeEdges = DFS(graph, ref visited, i);
                if (2 * nodeEdges[0] - 2 == nodeEdges[1]) res++;
            }
            WriteLine(res);
        }

        static int[] DFS(List<int>[] graph, ref bool[] visited, int now)
        {
            visited[now] = true;

            int nodes = 1;
            int edges = graph[now].Count;
            for(int i = 0; i < graph[now].Count; i++)
            {
                int index = graph[now][i];
                if (visited[index]) continue;

                int[] nodeEdges = DFS(graph, ref visited, index);
                nodes += nodeEdges[0];
                edges += nodeEdges[1];
            }
            return new int[2] { nodes, edges };
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}