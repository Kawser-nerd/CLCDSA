using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{

    internal class Solution
    {
        public int N, M;
        public Graph G;

        public void Run()
        {
            N = Input.ReadInt();
            G = new Graph(N);
            for (int i = 0; i < N - 1; i++)
            {
                var line = Input.ReadIntArray();
                int a = line[0] - 1;
                int b = line[1] - 1;
                G[a].Edges.Add(new Edge(a, b, 0));
                G[b].Edges.Add(new Edge(b, a, 0));
            }

            // ??????????????
            var D = new int[N];
            for (int i = 0; i < N; i++)
            {
                D[i] = Dist(i);
            }

            // ?????????
            int colors = D.Max() - D.Min() + 1;

            // ????????????
            var cand = new List<int>();
            for (int i = 0; i < N; i++)
            {
                if(D[i] == D.Min()) cand.Add(i);
            }

            if (cand.Count == 2)
            {
                long leaves = CountLeaves.Run(G, cand[0], cand[1]);
                Console.WriteLine("{0} {1}", colors, leaves);
            }
            else
            {
                // N >= 2

                // ??????????
                long leaves = CountLeaves.Run(G, cand[0]);

                // ???????????????
                foreach (var e in G[cand[0]].Edges)
                {
                    long l = CountLeaves.Run(G, cand[0], e.To);
                    leaves = Math.Min(leaves, l);
                }
                Console.WriteLine("{0} {1}", colors, leaves);
            }

        }

        // ?????????
        public int Dist(int x)
        {
            return DfsDist(new Edge(-1, x, 0));
        }

        public int DfsDist(Edge e)
        {
            int ret = 0;
            foreach (var ee in G[e.To].Edges)
            {
                if(e.From != ee.To) ret = Math.Max(DfsDist(ee) + 1, ret);
            }
            return ret;
        }

    }

    internal class CountLeaves
    {
        public Graph G;
        public long[] Degrees;

        public static long Run(Graph G, int c)
        {
            var CL = new CountLeaves();
            CL.G = G;
            CL.Degrees = new long[100];
            CL.Count(new Edge(-1, c, 0), 0);

            long ret = 1;
            for (int i = 0; i < CL.Degrees.Length; i++)
            {
                if (CL.Degrees[i] != 0) ret *= CL.Degrees[i];
            }
            return ret;
        }

        public static long Run(Graph G, int c1, int c2)
        {
            var CL = new CountLeaves();
            CL.G = G;
            CL.Degrees = new long[100];
            CL.Count(new Edge(c1, c2, 0), 0);
            CL.Count(new Edge(c2, c1, 0), 0);

            long ret = 1;
            for (int i = 0; i < CL.Degrees.Length; i++)
            {
                if (CL.Degrees[i] != 0) ret *= CL.Degrees[i];
            }

            ret *= 2;
            return ret;
        }

        public void Count(Edge e, int d)
        {
            var edges = G[e.To].Edges.Where(ee => ee.To != e.From).ToArray();
            Degrees[d] = Math.Max(Degrees[d], edges.Length);

            foreach (var ee in edges)
            {
                Count(ee, d+1);
            }
        }
    }

    // libs ----------
    internal class Graph
    {
        public List<Node> Nodes;

        public Node this[int i]
        {
            set { Nodes[i] = value; }
            get { return Nodes[i]; }
        }

        public Graph(int N)
        {
            Nodes = new List<Node>();
            for (int i = 0; i < N; i++)
            {
                Nodes.Add(new Node(i));
            }
        }

    }

    internal class Node
    {
        public List<Edge> Edges;
        public int Dist;
        public int No;

        public Node(int no)
        {
            this.No = no;
            Dist = int.MaxValue;
            Edges = new List<Edge>();
        }
    }

    internal class Edge
    {
        public int From;
        public int To;
        public int Cost;

        public Edge(int fr, int to, int cost = 0)
        {
            From = fr;
            To = to;
            Cost = cost;
        }

    }

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}