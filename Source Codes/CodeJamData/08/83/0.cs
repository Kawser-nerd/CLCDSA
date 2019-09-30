using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;

public class ProblemC
{
    static void Main(string[] args)
    {
//        TextReader sr = new StreamReader(@"c:\temp\c.in");
//        TextReader sr = new StreamReader(@"c:\temp\c-small-attempt0.in");
        TextReader sr = new StreamReader(@"c:\temp\c-large.in");
        //		TextReader sr = Console.In;
        		TextWriter sw = new StreamWriter(@"c:\temp\c.out");
//        TextWriter sw = Console.Out;

        int N = int.Parse(sr.ReadLine());
        for (int caseNo = 1; caseNo <= N; caseNo++)
        {
            sw.Write("Case #" + caseNo + ": ");
            Solve(sr, sw);
        }
        sw.Close();
    }

    private const long MOD = 1000000009;

    private static void Solve(TextReader sr, TextWriter sw)
    {
        string[] split = sr.ReadLine().Split(' ');
        int n = int.Parse(split[0]);
        int k = int.Parse(split[1]);
        Graph g = new Graph(n);
        for (int i = 0; i < n - 1; i++)
        {
            string[] split1 = sr.ReadLine().Split(' ');
            int a = int.Parse(split1[0]) - 1;
            int b = int.Parse(split1[1]) - 1;
            g.AddEdge(a, b);
        }

        /*Random r = new Random(0);
        g = new Graph(500);
        for (int i = 0; i < 499; i++)
        {
            int a = r.Next(i + 1);
            g.AddEdge(i, a);
        }
        k = 1000;*/

        RootedTree rt = new RootedTree(g, g.GetNode(0));
        long ans = Count(rt.Root, k);
        sw.WriteLine(ans);
    }

    private static long Count(RootedTreeNode node, int k)
    {
        long avail = k;
        if (node.Children.Length == 0)
            return 1;
        if (node.Parent != null)
            avail -= node.Parent.Node.Degree;
        if (avail <= 0)
            return 0;
        long prod = 1;
        for (int i = 0; i < node.Children.Length; i++)
        {
            prod *= avail;
            prod %= MOD;
            prod *= Count(node.Children[i], k);
            prod %= MOD;
            avail--;
        }
        return prod;
    }
}

public abstract class NodeFactory
{
    public abstract Node CreateNode(Graph graph, int index);
}

public class SimpleNodeFactory : NodeFactory
{
    public override Node CreateNode(Graph graph, int index)
    {
        return new Node(graph, index);
    }
}

public class Graph
{
    private readonly Node[] nodes;
    private List<Edge> edges;
    internal List<Edge>[] NodeEdges { get; private set; }

    private NodeFactory NodeFactory { get; set; }

    public Graph(int noNodes)
        : this(new SimpleNodeFactory(), noNodes)
    {
    }

    public Graph(NodeFactory nodeFactory, int noNodes)
    {
        NodeFactory = nodeFactory;

        edges = new List<Edge>();
        nodes = new Node[noNodes];
        NodeEdges = new List<Edge>[noNodes];
        for (int i = 0; i < noNodes; i++)
        {
            nodes[i] = NodeFactory.CreateNode(this, i);
            NodeEdges[i] = new List<Edge>();
        }
    }

    public void AddEdge(int a, int b)
    {
        AddEdge(new Edge(GetNode(a), GetNode(b)));
    }

    public void AddEdge(Edge e)
    {
        if (e == null || e.A.Graph != this)
            throw new ArgumentException();
        edges.Add(e);
        NodeEdges[e.A.Index].Add(e);
        NodeEdges[e.B.Index].Add(e);
    }

    public Node GetNode(int index)
    {
        return nodes[index];
    }

    public ICollection<Edge> Edges
    {
        get { return new ReadOnlyCollection<Edge>(edges); }
    }

    public ICollection<Node> Nodes
    {
        get { return new ReadOnlyCollection<Node>(nodes); }
    }
}

public class Node
{
    public Graph Graph { get; private set; }
    public int Index { get; private set; }
    public int Degree
    {
        get { return Graph.NodeEdges[Index].Count; }
    }

    public Node(Graph graph, int index)
    {
        Graph = graph;
        Index = index;
    }

    public IEnumerable<Node> GetAdjacentNodes()
    {
        foreach (Edge edge in Graph.NodeEdges[Index])
        {
            if (edge.A != this)
                yield return edge.A;
            if (edge.B != this)
                yield return edge.B;
        }
    }

    public IEnumerable<Edge> GetAdjacentEdges()
    {
        return new ReadOnlyCollection<Edge>(Graph.NodeEdges[Index]);
    }
}

public class Edge
{
    public Node A { get; set; }
    public Node B { get; set; }

    public Edge(Node a, Node b)
    {
        if (a == null || b == null || a.Graph != b.Graph)
            throw new ArgumentException();
        A = a;
        B = b;
    }
}

public class RootedTree
{
    public RootedTreeNode Root { get; private set; }
    private readonly RootedTreeNode[] RootedTreeNodes;
    private RootedTreeNode[,] lcaPreprocess;

    public RootedTree(Graph graph, Node root)
    {
        if (graph == null || root == null || root.Graph != graph || graph.Edges.Count != graph.Nodes.Count - 1)
            throw new ArgumentException();
        RootedTreeNodes = new RootedTreeNode[graph.Nodes.Count];
        Root = new RootedTreeNode(this, root, null);
    }

    public RootedTreeNode GetNode(int index)
    {
        return RootedTreeNodes[index];
    }

    internal void SetNode(RootedTreeNode treeNode)
    {
        RootedTreeNodes[treeNode.Node.Index] = treeNode;
    }

    private RootedTreeNode[,] PreprocessLCA()
    {
        int N = RootedTreeNodes.Length, M = 0;
        while ((1 << M) < N)
            M++;
        var p = new RootedTreeNode[N, M];

        for (int i = 0; i < N; i++)
            p[i, 0] = RootedTreeNodes[i].Parent;

        for (int j = 1; 1 << j < N; j++)
            for (int i = 0; i < N; i++)
                if (p[i, j - 1] != null)
                    p[i, j] = p[p[i, j - 1].Node.Index, j - 1];

        return p;
    }

    public RootedTreeNode GetLowestCommonAncestor(RootedTreeNode p, RootedTreeNode q)
    {
        if (lcaPreprocess == null)
            lcaPreprocess = PreprocessLCA();

        if (p.Level < q.Level)
        {
            RootedTreeNode tmp = p;
            p = q;
            q = tmp;
        }

        int log;
        for (log = 1; 1 << log <= p.Level; log++) ;
        log--;

        for (int i = log; i >= 0; i--)
            if (p.Level - (1 << i) >= q.Level)
                p = lcaPreprocess[p.Node.Index, i];

        if (p == q)
            return p;

        for (int i = log; i >= 0; i--)
            if (lcaPreprocess[p.Node.Index, i] != null &&
                lcaPreprocess[p.Node.Index, i] != lcaPreprocess[q.Node.Index, i])
            {
                p = lcaPreprocess[p.Node.Index, i];
                q = lcaPreprocess[q.Node.Index, i];
            }

        return p.Parent;
    }
}

public class RootedTreeNode
{
    public RootedTree Tree { get; private set; }
    public Node Node { get; private set; }
    public RootedTreeNode Parent { get; set; }
    public int Level { get; private set; }

    public RootedTreeNode[] Children { get; private set; }

    public RootedTreeNode(RootedTree tree, Node node, RootedTreeNode parent)
    {
        Tree = tree;
        Node = node;
        Parent = parent;
        Level = parent == null ? 0 : (parent.Level + 1);

        var children = new List<RootedTreeNode>(node.Degree);
        foreach (Node child in Node.GetAdjacentNodes().Where(x => Parent == null || x != Parent.Node))
            children.Add(new RootedTreeNode(tree, child, this));
        Children = children.ToArray();

        tree.SetNode(this);
    }
}