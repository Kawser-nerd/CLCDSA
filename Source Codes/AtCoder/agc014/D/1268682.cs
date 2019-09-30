//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public class Tree
    {
        public Node Root;
        public Node[] Leaves;  // ?????Leaves???????

        public Tree(IEnumerable<long>[] adjacency_list)
        {
            Root = Node.FromAdjacencyList(adjacency_list, 0, null);

            Leaves = SearchLeaves(Root).ToArray();
        }

        private IEnumerable<Node> SearchLeaves(Node v)
        {
            if (v.Children.Length == 0)
            {
                return new[] { v };
            }

            var ret = new List<Node>();

            foreach (var c in v.Children)
            {
                ret.AddRange(SearchLeaves(c));
            }

            return ret;
        }

        public class Node
        {
            public Node Parent;
            public Node[] Children;
            public long Id;
            public int Degree { get { return Children.Length; } }

            public Node(Node parent, Node[] children, long id) { Parent = parent; Children = children; Id = id; }

            public override string ToString()
            {
                return Id + (Children.Length == 0 ? "" : "[" + string.Join(",", Children.Select(x => x.ToString())) + "]");
            }

            public static Node FromAdjacencyList(IEnumerable<long>[] adjacency_list, long rootIndex = 0, long? parentIndex = null)
            {
                var arr = (adjacency_list[rootIndex] as long[]) ?? adjacency_list[rootIndex].ToArray();

                var children = arr.Where(x => x != parentIndex).Select(x => FromAdjacencyList(adjacency_list, x, rootIndex)).ToArray();

                var root = new Node(null, children, rootIndex);

                foreach (var c in children)
                {
                    c.Parent = root;
                }

                return root;
            }
        }

        public override string ToString()
        {
            return Root.ToString();
        }
    }

    public static void Main()
    {
        var N = long.Parse(Console.ReadLine());

        var adj = new List<long>[N];
        for (int i = 0; i < N; i++)
        {
            adj[i] = new List<long>();
        }

        for (var i = 0; i < N - 1; i++)
        {
            var line1 = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

            adj[line1[0] - 1].Add(line1[1] - 1);
            adj[line1[1] - 1].Add(line1[0] - 1);
        }

        var tree = new Tree(adj);
        //Console.WriteLine(new Tree(adj).ToString());
        //Console.WriteLine(String.Join(",", new Tree(adj).Leaves.Select(x => x.Id)));

        var q = new Queue<Tree.Node>();
        foreach (var v in tree.Leaves)
        {
            q.Enqueue(v);
        }

        while (q.Count != 0)
        {
            var next = q.Dequeue();

            if (next.Parent == null)
            {
                // ????0?
                Console.WriteLine("First");
                return;
            }

            if (next.Parent.Degree == 1)
            {
                if (next.Parent.Parent == null)
                {
                    // ???
                    Console.WriteLine("Second");
                    return;
                }

                // next ? next.Parent ???????
                next.Parent.Parent.Children = next.Parent.Parent.Children.Where(x => x != next.Parent).ToArray();
                if (next.Parent.Parent.Degree == 0)
                {
                    q.Enqueue(next.Parent.Parent);
                }
            }
            else
            {
                if (next.Parent.Children.All(x => x.Degree == 0))
                {
                    // next.Parent????2???????? ?
                    Console.WriteLine("First");
                    return;
                }
                else
                {
                    // ???
                    q.Enqueue(next);
                }
            }
        }
    }
}