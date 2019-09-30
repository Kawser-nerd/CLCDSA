using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int N;
    static int M;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        M = Input.NextInt();

        var nodes = Enumerable.Range(0, N).Select(n => new BellmanFord.Node()).ToArray();

        var edges = new List<BellmanFord.Edge>();
        for (int i = 0; i < M; i++)
        {
            var abc = Input.LineInt();
            var a = abc[0] - 1;
            var b = abc[1] - 1;
            var c = -abc[2];

            var ef = nodes[a].CreateEdge(nodes[b], c);
            edges.Add(ef);
        }

        var search = new BellmanFord();
        search.Search(nodes, edges, nodes[0]);

        var negOfMaxCost = nodes[N - 1].MinDistance;

        Console.WriteLine(negOfMaxCost == long.MinValue ? "inf" : (-negOfMaxCost).ToString());
    }
}

public class BellmanFord
{
    public class Edge
    {
        public Edge(Node start, Node end, long weight)
        {
            StartNode = start;
            EndNode = end;
            Weight = weight;
        }

        public Node StartNode { get; set; }
        public Node EndNode { get; set; }
        public long Weight { get; set; }
    }

    public class Node
    {
        public List<Edge> Edges { get; set; } = new List<Edge>();
        public long Distance { get; set; } = long.MaxValue;
        public Node Prev { get; set; }
        public bool IsNegative { get; set; }
        public long MinDistance => IsNegative ? long.MinValue : Distance;

        public bool Visited => Distance != long.MaxValue;

        public Edge CreateEdge(Node destination, long distance)
        {
            var edge = new Edge(this, destination, distance);
            Edges.Add(edge);
            return edge;
        }

        public override string ToString()
        {
            return $"Distance:{Distance}, IsNegative:{IsNegative}";
        }
    }

    public void Search(IList<Node> nodes, IList<Edge> edges, Node root)
    {
        foreach (var node in nodes)
        {
            node.Distance = long.MaxValue;
            node.Prev = null;
            node.IsNegative = false;
        }

        root.Distance = 0;

        for (int i = 0; i < nodes.Count - 1; i++)
        {
            foreach (var edge in edges)
            {
                if (!edge.StartNode.Visited)
                    continue;
                var newDistance = edge.StartNode.Distance + edge.Weight;
                if (edge.EndNode.Distance > newDistance)
                {
                    edge.EndNode.Distance = newDistance;
                    edge.EndNode.Prev = edge.StartNode;
                }
            }
        }

        for (int i = 0; i < nodes.Count - 1; i++)
        {
            foreach (var edge in edges)
            {
                if (!edge.StartNode.Visited)
                    continue;

                var newDistance = edge.StartNode.Distance + edge.Weight;
                if (edge.EndNode.Distance > newDistance)
                {
                    edge.EndNode.Distance = newDistance;
                    edge.EndNode.IsNegative = true;
                }
                if (edge.StartNode.IsNegative)
                    edge.EndNode.IsNegative = true;
            }
        }
    }
}

public static class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}