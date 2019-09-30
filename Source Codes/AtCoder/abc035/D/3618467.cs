using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_035
    {
        static Node[] nodes;
        static long[] goDistances;
        static long[] backDistances;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nmt = ReadInts();
            int n = nmt[0];
            int m = nmt[1];
            long t = nmt[2];
            long[] array = ReadLongs();
            nodes = new Node[n];
            goDistances = new long[n];
            backDistances = new long[n];
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node();
                goDistances[i] = -1;
                backDistances[i] = -1;
            }
            for (int i = 0; i < m; i++)
            {
                int[] abc = ReadInts();
                int a = abc[0] - 1;
                int b = abc[1] - 1;
                long c = abc[2];
                nodes[a].goEdges.Add(new Edge(b, c));
                nodes[b].backEdges.Add(new Edge(a, c));
            }

            goDistances = BFS(goDistances,false);
            backDistances = BFS(backDistances,true);
            long max = long.MinValue;
            for (int i = 0; i < n; i++)
            {
                //Console.WriteLine(goDistances[i]);
                //Console.WriteLine(backDistances[i]);
                if (goDistances[i] == -1
                    || backDistances[i] == -1
                    || goDistances[i] + backDistances[i] >= t) continue;

                long temp = (t - goDistances[i] - backDistances[i]) * array[i];
                max = Math.Max(max, temp);
            }

            Console.WriteLine(max);
        }

        static long[] BFS(long[] distances,bool back)
        {
            var queue = new Queue<int>();
            queue.Enqueue(0);
            distances[0] = 0;
            while (queue.Count > 0)
            {
                int index = queue.Dequeue();
                List<Edge> edges = back ? nodes[index].backEdges
                    : nodes[index].goEdges;
                for (int i = 0; i < edges.Count; i++)
                {
                    int toIndex = edges[i].toIndex;
                    long nextDistance = distances[index]
                        + edges[i].distance;
                    if (distances[toIndex] >= 0
                        && distances[toIndex] < nextDistance) continue;

                    queue.Enqueue(toIndex);
                    distances[toIndex] = nextDistance;
                }
            }
            return distances;
        }

        class Node
        {
            public List<Edge> goEdges;
            public List<Edge> backEdges;
            public Node()
            {
                goEdges = new List<Edge>();
                backEdges = new List<Edge>();
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