using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        string[] s = Console.ReadLine().Split(' ');
        int n, m;
        n = int.Parse(s[0]);
        m = int.Parse(s[1]);
        Graph g = new Graph(n);
        for (int i = 0; i < m; i++)
        {
            s = Console.ReadLine().Split(' ');
            int a, b;
            a = int.Parse(s[0]);
            b = int.Parse(s[1]);
            g.SetEdge(a, b);
            g.SetEdge(b, a);
        }
        bool f = false;
        foreach (var e in g.node[0].edge)
        {
            f = f || e.G.Child.Contains(g.node[n - 1]);
            if (f)
                break;
        }
        Console.WriteLine(f ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
class Node
{
    public int id;
    public List<Edge> edge = new List<Edge>();
    public List<Node> Child = new List<Node>();
    public Node(int id) { this.id = id; }
}
class Edge
{
    public Node S;
    public Node G;
    public Edge(Node S, Node G)
    {
        this.S = S;
        this.G = G;
    }
}
class Graph
{
    public Node[] node;
    public Graph(int n)
    {
        node = new Node[n];
        for (int i = 0; i < n; i++)
            node[i] = new Node(i + 1);
    }
    public void SetEdge(int n1, int n2)
    {
        if (n1 > node.Length || n1 <= 0 || n2 > node.Length || n2 <= 0)
            return;
        Edge e = new Edge(node[n1 - 1], node[n2 - 1]);
        node[n1 - 1].edge.Add(e);
        node[n1 - 1].Child.Add(node[n2 - 1]);
    }
}