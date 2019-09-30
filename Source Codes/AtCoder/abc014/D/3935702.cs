using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_014
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var nodes = new Node[n];
            var xys = new int[n - 1][];
            for(int i = 0; i < n; i++)
            {
                nodes[i] = new Node();
            }
            for(int i = 0; i < n - 1; i++)
            {
                int[] xy = ReadInts();
                int x = xy[0] - 1;
                int y = xy[1] - 1;
                nodes[x].edges.Add(new Edge(y, 1));
                nodes[y].edges.Add(new Edge(x, 1));
            }

            var parents = new int[n, 20];
            var ranks = new int[n];
            var queue = new Queue<int[]>();
            queue.Enqueue(new int[3] { 0, -1, 0 });
            var visited = new bool[n];
            while (queue.Count > 0)
            {
                int[] param = queue.Dequeue();
                if (visited[param[0]]) continue;

                parents[param[0], 0] = param[1];
                visited[param[0]] = true;
                ranks[param[0]] = param[2];
                Node nowNode = nodes[param[0]];
                for(int i = 0; i < nowNode.edges.Count; i++)
                {
                    Edge edge = nowNode.edges[i];
                    queue.Enqueue(
                        new int[3] { edge.toIndex, param[0], param[2] + 1 });
                }
            }
            /*
            for(int i = 0; i < n; i++)
            {
                Console.WriteLine(parents[i, 0]);
            }
            */
            for(int i = 1; i < 20; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if (parents[j, i - 1] == -1)
                    {
                        parents[j, i] = -1;
                    }
                    else
                    {
                        parents[j, i] = parents[parents[j, i - 1], i - 1];
                    }
                }
            }

            int q = ReadInt();
            var abs = new int[q][];
            for(int i = 0; i < q; i++)
            {
                abs[i] = ReadInts();
            }

            for (int i = 0; i < q; i++)
            {
                int a = abs[i][0] - 1;
                int b = abs[i][1] - 1;
                if (ranks[a] > ranks[b])
                {
                    int temp = a;
                    a = b;
                    b = temp;
                }
                int distance = ranks[b] - ranks[a];
                for (int j = 19; j >= 0; j--)
                {
                    if (ranks[b]
                        - ranks[a] < 1 << j) continue;

                    b = parents[b, j];
                }

                while (a!=b)
                {
                    for (int j = 0; j < 20; j++)
                    {
                        if (parents[a, j] == parents[b, j])
                        {
                            if (j == 0)
                            {
                                a = parents[a, j];
                                b = parents[b, j];
                                distance += 2;
                            }
                            else
                            {
                                a = parents[a, j - 1];
                                b = parents[b, j - 1];
                                distance += 2 << (j - 1);
                            }
                            break;
                        }
                    }
                }
                Console.WriteLine(distance + 1);
            }
        }

        class Node
        {
            public List<Edge> edges;
            public int rank;
            public int[] parents;
            public Node()
            {
                edges = new List<Edge>();
            }
        }

        class Edge
        {
            public int toIndex;
            public long distance;

            public Edge(int toIndex, long distance)
            {
                this.toIndex = toIndex;
                this.distance = distance;
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