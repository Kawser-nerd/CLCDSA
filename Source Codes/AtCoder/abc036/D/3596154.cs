using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_036
    {
        static Node[] nodes;
        static bool[] visited;
        static long mask = 1000000000 + 7;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            nodes = new Node[n];
            visited = new bool[n];
            for(int i = 0; i < n; i++)
            {
                nodes[i] = new Node(n);
            }
            for (int i = 0; i < n - 1; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0] - 1;
                int b = ab[1] - 1;
                nodes[a].edges.Add(new Edge(b, 1));
                nodes[b].edges.Add(new Edge(a, 1));
            }
            long[] cnts = DFS(0);
            Console.WriteLine((cnts[0] + cnts[1]) % mask);
        }

        static long[] DFS(int index)
        {
            //Console.WriteLine(index);
            visited[index] = true;
            long[] cnts = new long[2] { 1, 1 };
            for(int i = 0; i < nodes[index].edges.Count; i++)
            {
                int nextIndex = nodes[index].edges[i].toIndex;
                if (visited[nextIndex]) continue;

                long[] tempCnts = DFS(nextIndex);
                //white
                cnts[0] *= ((tempCnts[0] + tempCnts[1]) % mask);
                cnts[0] %= mask;
                //black
                cnts[1] *= tempCnts[0];
                cnts[1] %= mask;
            }
            return cnts;
        }

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

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}