using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamCs
{
    class Program
    {
        public static List<Node> nodes;
        public static int addedNodes;

        public static void Main(string[] args)
        {
            using (var reader = new StreamReader("A.in"))
            using (var writer = new StreamWriter("A.out"))
            {
                int testCount = int.Parse(reader.ReadLine());
                for (int test = 1; test <= testCount; test++)
                {
                    var line = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                    int n = line[0], m = line[1];

                    nodes = new List<Node>();
                    nodes.Add(new Node {Name = ""});
                    
                    for (int i = 0; i < n; i++)
                    {
                        var directory =
                            reader.ReadLine().Split(new[] {'/'}, StringSplitOptions.RemoveEmptyEntries).ToList();
                        Add(nodes[0], directory, 0, false);
                    }

                    addedNodes = 0;
                    for (int i = 0; i < m; i++)
                    {
                        var directory =
                            reader.ReadLine().Split(new[] { '/' }, StringSplitOptions.RemoveEmptyEntries).ToList();
                        Add(nodes[0], directory, 0, true);
                    }

                    writer.WriteLine("Case #{0}: {1}", test, addedNodes);
                }
            }
        }

        private static void Add(Node root, List<string> directory, int index, bool countAdding)
        {
            if (index >= directory.Count) return;
            
            for (int i = 0; i < root.Children.Count; ++i)
                if (nodes[root.Children[i]].Name == directory[index])
                {
                    Add(nodes[root.Children[i]], directory, index + 1, countAdding);
                    return;
                }
            if (countAdding)
                ++addedNodes;
            nodes.Add(new Node { Name = directory[index]});
            root.Children.Add(nodes.Count - 1);
            Add(nodes[nodes.Count - 1], directory, index + 1, countAdding);
        }
    }

    internal class Node
    {
        public List<int> Children = new List<int>();
        public string Name;
    }
}
