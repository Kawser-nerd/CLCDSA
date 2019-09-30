using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_010
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nge = ReadInts();
            int n = nge[0];
            int g = nge[1];
            int e = nge[2];
            if (g == 0)
            {
                Console.WriteLine(0);
                return;
            }

            int length = n + 1;
            var graph = new List<Edge>[length];
            for (int i = 0; i < length; i++) graph[i] = new List<Edge>();

            int[] ps = ReadInts();
            for (int i = 0; i < g; i++)
            {
                int num = ps[i];
                graph[num].Add(
                    new Edge(length - 1, 1, graph[length - 1].Count));
                graph[length - 1].Add(
                    new Edge(num, 1, graph[num].Count - 1));
            }

            for (int i = 0; i < e; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0];
                int b = ab[1];
                graph[a].Add(new Edge(b, 1, graph[b].Count));
                graph[b].Add(new Edge(a, 1, graph[a].Count - 1));
            }

            int[] levels;
            int res = 0;
            do
            {
                levels = BFS(graph, 0);
                int[] iterator = new int[length];
                int flow = 0;
                do
                {
                    flow = DFS(ref iterator, ref graph, levels,
                        0, length - 1, int.MaxValue);
                    res += flow;
                } while (flow > 0);
            } while (levels[length - 1] > 0);
            Console.WriteLine(res);
        }

        //calc min distance
        static int[] BFS(List<Edge>[] graph, int start)
        {
            int[] levels = new int[graph.Length];
            for (int i = 0; i < levels.Length; i++)
            {
                levels[i] = -1;
            }
            levels[start] = 0;

            Queue<int> queue = new Queue<int>();
            queue.Enqueue(start);

            while (queue.Count > 0)
            {
                int index = queue.Dequeue();
                for (int i = 0; i < graph[index].Count; i++)
                {
                    Edge edge = graph[index][i];
                    if (edge.capacity > 0 && levels[edge.to] < 0)
                    {
                        levels[edge.to] = levels[index] + 1;
                        queue.Enqueue(edge.to);
                    }
                }
            }
            return levels;
        }

        static int DFS(ref int[] iterator, ref List<Edge>[] graph,
            int[] levels, int now, int goal, int flow)
        {
            if (now == goal) return flow;

            for (; iterator[now] < graph[now].Count; iterator[now]++)
            {
                Edge edge = graph[now][iterator[now]];
                if (edge.capacity > 0 && levels[now] < levels[edge.to])
                {
                    int cnt = DFS(ref iterator, ref graph, levels,
                        edge.to, goal, Math.Min(flow, edge.capacity));
                    if (cnt > 0)
                    {
                        edge.capacity -= cnt;
                        graph[edge.to][edge.reverse].capacity += cnt;
                        return cnt;
                    }
                }
            }
            return 0;
        }

        class Edge
        {
            public int to;
            public int capacity;
            public int reverse;
            public Edge(int to, int capacity, int reverse)
            {
                this.to = to;
                this.capacity = capacity;
                this.reverse = reverse;
            }
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}