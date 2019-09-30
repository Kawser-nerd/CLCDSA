using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    // libs ----------
    internal class Solution
    {
        public int N, M;
        public Graph G;
        public string S;
        public void Run()
        {
            // Input
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }
            S = Console.ReadLine();

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

            for (int i = 0; i < N; i++)
            {
                var node = G[i];
                foreach (var e in node.Edges)
                {
                    if (S[e.To] == 'A')
                        node.A++;
                    else
                        node.B++;
                }
            }

            for (int i = 0; i < N; i++)
            {
                dfs(i);
            }

            for (int i = 0; i < N; i++)
            {
                if (!G[i].Deleted)
                {
                    Console.WriteLine("Yes");
                    return;

                }
            }

            Console.WriteLine("No");
        }

        void dfs(int n)
        {
            var node = G[n];
            if (node.Deleted) return;

            if (node.A == 0 || node.B == 0)
            {
                node.Deleted = true;
                foreach (var e in node.Edges)
                {
                    var eto = G[e.To];
                    if (!eto.Deleted)
                    {
                        if (S[n] == 'A')
                            eto.A--;
                        else
                        {
                            eto.B--;
                        }

                        if (eto.A == 0 || eto.B == 0)
                        {
                            dfs(e.To);
                        }
                    }
                }
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
        public int A, B;
        public int No;
        public bool Deleted;

        public Node(int no)
        {
            this.No = no;
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