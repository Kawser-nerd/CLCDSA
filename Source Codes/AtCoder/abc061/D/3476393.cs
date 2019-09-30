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
                long d = -line[2];

                // ?????
                var e1 = new Edge(u, v, d);
                G[u].Edges.Add(e1);
            }

            G[0].Dist = 0;

            // bellman-ford
            for (int t = 0; t < N; t++)
            {
                for (int i = 0; i < N; i++)
                {
                    var node = G[i];
                    if (node.Dist == long.MaxValue) continue;
                    foreach (var edge in node.Edges)
                    {
                        G[edge.To].Dist = Math.Min(G[edge.To].Dist, edge.Cost + node.Dist);
                    }
                }
            }

            long distN = G[N - 1].Dist;

            // another loops
            for (int t = 0; t < N; t++)
            {
                for (int i = 0; i < N; i++)
                {
                    var node = G[i];
                    if (node.Dist == long.MaxValue) continue;
                    foreach (var edge in node.Edges)
                    {
                        G[edge.To].Dist = Math.Min(G[edge.To].Dist, edge.Cost + node.Dist);
                    }
                }
            }

            if (distN == G[N - 1].Dist)
            {
                Console.WriteLine(-distN);
            }
            else
            {
                Console.WriteLine("inf");
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
        public long Dist;
        public int No;

        public Node(int no)
        {
            this.No = no;
            Dist = long.MaxValue;
            Edges = new List<Edge>();
        }
    }

    internal class Edge
    {
        public int From;
        public int To;
        public long Cost;
        public Edge Rev;

        public Edge(int fr, int to, long cost = 0)
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

    // ???IComparable?????
    class EdgeData : IComparable<EdgeData>, IComparable
    {
        public long Dist;
        public Edge Edge;
        public EdgeData(long dist, Edge edge)
        {
            Dist = dist;
            Edge = edge;
        }

        public int CompareTo(EdgeData other)
        {
            return Dist.CompareTo(other.Dist);
        }

        public int CompareTo(object obj)
        {
            if (obj == null) return 1;
            if (GetType() != obj.GetType()) throw new ArgumentException();
            return CompareTo((EdgeData)obj);
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