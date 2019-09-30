using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, M, Q;
        public Graph G;
        public int[] QV, QD, QC;
        public int[,] DP; // V, Depth
        public int MXD = 10;

        public void Run()
        {
            // Input
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }

            // Graph
            G = new Graph(N);
            for (int i = 0; i < M; i++)
            {
                var line = Input.ReadIntArray();
                int u = line[0] - 1;
                int v = line[1] - 1;
                // ?????
                var e1 = new Edge(u, v, 0);
                var e2 = new Edge(v, u, 0);
                e1.Rev = e2;
                e2.Rev = e1;
                G[u].Edges.Add(e1);
                G[v].Edges.Add(e2);
            }

            // Query
            Q = Input.ReadInt();
            QV = new int[Q];
            QD = new int[Q];
            QC = new int[Q];
            for (int q = 0; q < Q; q++)
            {
                var line = Input.ReadIntArray();
                int v = line[0] - 1;
                int d = line[1];
                int c = line[2];
                QV[q] = v;
                QD[q] = d;
                QC[q] = c;
            }

            DP = new int[N, MXD + 1];

            for (int q = Q-1; q >= 0; q--)
            {
                int v = QV[q];
                int d = QD[q];
                int c = QC[q];
                Fill(v, d, c);
            }

            for (int i = 0; i < N; i++)
            {
                Console.WriteLine(DP[i, 0]);
            }

        }

        public void Fill(int v, int d, int c)
        {
            if (DP[v, d] != 0) return;
            for (int dd = d; dd >= 0; dd--)
            {
                if(DP[v, dd] != 0) break;
                DP[v, dd] = c;
            }

            if (d == 0) return;
            foreach (var e in G[v].Edges)
            {
                Fill(e.To, d-1, c);
            }
        }
    }

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
        public Edge Rev;

        public Edge(int fr, int to, int cost = 0)
        {
            From = fr;
            To = to;
            Cost = cost;
        }

        public bool IsRev(Edge e)
        {
            return Rev != null && (e == Rev);
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