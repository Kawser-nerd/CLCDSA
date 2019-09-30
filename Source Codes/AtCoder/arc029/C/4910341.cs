using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _029
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
            List<Edge>[] graph = new List<Edge>[n + 1];
            for (int i = 0; i <= n; i++) graph[i] = new List<Edge>();

            for(int i = 0; i < n; i++)
            {
                long c = ReadInt();
                graph[0].Add(new Edge(i + 1, c));
            }

            for(int i = 0; i < m; i++)
            {
                int[] param = ReadInts();
                int a = param[0];
                int b = param[1];
                int r = param[2];
                graph[a].Add(new Edge(b, r));
                graph[b].Add(new Edge(a, r));
            }

            PriorityQueue<int> priorityQueue = new PriorityQueue<int>();
            bool[] visited = new bool[n + 1];
            priorityQueue.Enqueue(0, 0);
            long res = 0;
            while (priorityQueue.Exist())
            {
                var pair = priorityQueue.Dequeue();
                long dist = pair.Key;
                int now = pair.Value;
                if (visited[now]) continue;

                visited[now] = true;
                res += dist;
                for(int i = 0; i < graph[now].Count; i++)
                {
                    if (visited[graph[now][i].to]) continue;

                    priorityQueue.Enqueue(graph[now][i].dist,
                        graph[now][i].to);
                }
            }
            WriteLine(res);
        }

        class Edge
        {
            public int to;
            public long dist;
            public Edge(int to,long dist)
            {
                this.to = to;
                this.dist = dist;
            }
        }

        class PriorityQueue<T>
        {
            private readonly List<KeyValuePair<long, T>> list;
            private int count;

            public PriorityQueue()
            {
                list = new List<KeyValuePair<long, T>>();
                count = 0;
            }

            private void Add(KeyValuePair<long, T> pair)
            {
                if (count == list.Count)
                {
                    list.Add(pair);
                }
                else
                {
                    list[count] = pair;
                }
                count++;
            }

            private void Swap(int a, int b)
            {
                KeyValuePair<long, T> tmp = list[a];
                list[a] = list[b];
                list[b] = tmp;
            }

            public void Enqueue(long key, T value)
            {
                Add(new KeyValuePair<long, T>(key, value));
                int c = count - 1;
                while (c > 0)
                {
                    int p = (c - 1) / 2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    c = p;
                }
            }

            public KeyValuePair<long, T> Dequeue()
            {
                KeyValuePair<long, T> pair = list[0];
                count--;
                if (count == 0) return pair;

                list[0] = list[count];
                int p = 0;
                while (true)
                {
                    int c1 = p * 2 + 1;
                    int c2 = p * 2 + 2;
                    if (c1 >= count) break;

                    int c = (c2 >= count || list[c1].Key < list[c2].Key)
                        ? c1 : c2;
                    if (list[c].Key >= list[p].Key) break;

                    Swap(p, c);
                    p = c;
                }
                return pair;
            }
            public bool Exist() { return count > 0; }
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