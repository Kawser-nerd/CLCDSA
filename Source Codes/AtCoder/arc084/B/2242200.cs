using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Threading.Tasks;

namespace AtCoder
{
    class Node
    {
        public int Distance { get; set; }
        public List<Tuple<Node, int>> Children { get; private set; }
        public Node()
        {
            Distance = int.MaxValue;
            Children = new List<Tuple<Node, int>>();
        }
        public void Add(Node node, int cost)
        {
            Children.Add(new Tuple<Node, int>(node, cost));
        }
    }

    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static int Solve(int K)
        {
            var nodes = new Node[K];
            for (int i = 0; i < K; ++i) { nodes[i] = new Node(); }
            for (int i = 0; i < K; ++i)
            {
                nodes[i].Add(nodes[(i + 1) % K], 1);
                nodes[i].Add(nodes[(i * 10) % K], 0);
            }
            var q = new Queue<Node>();
            nodes[1].Distance = 1;
            q.Enqueue(nodes[1]);
            while (q.Count > 0)
            {
                Node node1 = q.Dequeue();
                foreach (var tuple in node1.Children)
                {
                    Node node2 = tuple.Item1;
                    int cost = tuple.Item2;
                    if (node1.Distance + cost < node2.Distance)
                    {
                        node2.Distance = node1.Distance + cost;
                        q.Enqueue(node2);
                    }
                }
            }
            return nodes[0].Distance;
        }

        static void Main(string[] args)
        {
            int K = ReadInt();
            Console.WriteLine(Solve(K));
        }
    }
}