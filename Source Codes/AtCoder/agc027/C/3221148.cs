using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Node
    {
        private readonly char item;
        public bool exists = true;
        public List<Node> edges = new List<Node>();
        public Node(char c)
        {
            item = c;
        }
        public bool Good()
        {
            return edges.Any(edge => edge.item == 'A')
                && edges.Any(edge => edge.item == 'B');
        }
    }
    class Program
    {
        static bool Solve(int N, Node[] nodes)
        {
            var q = new Queue<Node>();
            foreach (var node in nodes)
            {
                if (!node.Good()) { q.Enqueue(node); }
            }
            while (q.Count > 0)
            {
                var node = q.Dequeue();
                if (node.exists && !node.Good())
                {
                    for (int i = 0; i < node.edges.Count; ++i)
                    {
                        var child = node.edges[i];
                        child.edges.Remove(node);
                        q.Enqueue(child);
                    }
                    node.exists = false;
                }
            }
            return nodes.Any(node => node.exists);
        }
        static void Main(string[] args)
        {
            int[] V1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int N = V1[0];
            int M = V1[1];
            string s = Console.ReadLine();
            var nodes = new Node[N];
            for (int i = 0; i < N; ++i) { nodes[i] = new Node(s[i]); }
            for (int i = 0; i < M; ++i)
            {
                int[] V2 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                var a = nodes[V2[0] - 1];
                var b = nodes[V2[1] - 1];
                a.edges.Add(b);
                b.edges.Add(a);
            }
            Console.WriteLine(Solve(N, nodes) ? "Yes" : "No");
        }
    }
}