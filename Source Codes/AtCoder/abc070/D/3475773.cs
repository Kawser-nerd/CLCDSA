using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_070
    {
        static Node[] nodes;
        static long[] distances;
        static bool[] isMin;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            nodes = new Node[n];
            distances = new long[n];
            isMin = new bool[n];
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node(n);
                distances[i] = long.MaxValue;
                isMin[i] = false;
            }
            for (int i = 0; i < n-1; i++)
            {
                int[] abc = ReadInts();
                nodes[abc[0] - 1].edges.Add(new Edge(abc[1] - 1, abc[2]));
                nodes[abc[1] - 1].edges.Add(new Edge(abc[0] - 1, abc[2]));
            }
            int[] qk = ReadInts();
            DFS(qk[1] - 1, 0);

            var res = new long[qk[0]];
            for (int i = 0; i < qk[0]; i++)
            {
                int[] xy = ReadInts();
                res[i] = distances[xy[0] - 1]
                    + distances[xy[1] - 1];
            }
            for(int i = 0; i < qk[0]; i++)
            {
                Console.WriteLine(res[i]);
            }
            /*for(int i = 0; i < n; i++)
            {
                Console.WriteLine(distances[i]);
            }*/
        }

        static void DFS(int index,long distance)
        {
            if (distances[index] < distance) return;
            distances[index] = distance;

            for(int i = 0; i < nodes[index].edges.Count; i++)
            {
                Edge edge = nodes[index].edges[i];
                DFS(edge.toIndex, distance + edge.distance);
            }
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        class Node
        {
            public List<Edge> edges;
            public Node(int length)
            {
                edges = new List<Edge>();
            }
        }

        class Edge
        {
            public int toIndex;
            public int distance;

            public Edge(int toIndex, int distance)
            {
                this.toIndex = toIndex;
                this.distance = distance;
            }
        }
    }
}