using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static int M;
    static PNode[] nodes;

    public static void Main(string[] args)
    {
        checked
        {
            N = Input.NextInt();
            M = Input.NextInt();

            InitNodes(nodes = new PNode[N]);

            var edges = new List<Dijkstra.Edge>();

            for (int i = 0; i < M; i++)
            {
                var abc = Input.LineInt();
                var a = abc[0] - 1;
                var b = abc[1] - 1;
                var c = abc[2];

                var ef = nodes[a].CreateEdge(nodes[b], c);
                var er = nodes[b].CreateEdge(nodes[a], c);
                ef.ReverseEdge = er;
                er.ReverseEdge = ef;
                edges.Add(ef);
            }

            for (int i = 0; i < N; i++)
            {
                if (nodes[i].Edges.Any(n => n.State == EdgeState.ND))
                {
                    var search = new Dijkstra();
                    search.Search(nodes[i]);

                    foreach (var node in nodes.Where(n => n != nodes[i]))
                    {
                        node.InEdge.State = EdgeState.Use;
                    }
                    foreach (var aroundE in nodes[i].Edges)
                    {
                        if (aroundE.State != EdgeState.Use)
                        {
                            aroundE.State = EdgeState.DontUse;
                        }
                    }

                    // clear info
                    foreach (var node in nodes)
                    {
                        node.InEdge = null;
                        node.Reset();
                    }
                }
            }

            Console.WriteLine(edges.Count(n => n.State != EdgeState.Use));
        }
    }

    static void InitNodes(PNode[] nodes)
    {
        for (int i = 0; i < nodes.Length; i++)
            nodes[i] = new PNode();
    }

    public class PNode : Dijkstra.Node
    {
        public override string ToString()
        {
            return $"Distance:{MinDistance}";
        }
    }
}

public enum EdgeState
{
    ND,
    Use,
    DontUse,
}

public class Dijkstra
{
    public class Edge
    {
        public Edge(Node start, Node end, long distance)
        {
            StartNode = start;
            EndNode = end;
            Distance = distance;
        }

        public Node StartNode { get; set; }
        public Node EndNode { get; set; }
        public long Distance { get; set; }

        public Edge ReverseEdge;

        private EdgeState _State = EdgeState.ND;
        public EdgeState State
        {
            get
            {
                return _State;
            }
            set
            {
                _State = ReverseEdge._State = value;
            }
        }
    }

    public class Node
    {
        const long MaxLength = long.MaxValue;

        public List<Edge> Edges { get; set; } = new List<Edge>();
        public long MinDistance { get; set; } = MaxLength;
        public Edge InEdge { get; set; }

        public void Reset()
        {
            MinDistance = MaxLength;
        }

        public bool Visited => MinDistance != MaxLength;

        public Edge CreateEdge(Node destination, long distance)
        {
            var edge = new Edge(this, destination, distance);
            Edges.Add(edge);
            return edge;
        }
    }

    public void Search(Node root)
    {
        var queue = new PriorityQueue<Tuple<long, Node>>((a, b) =>
        {
            var d = a.Item1 - b.Item1;
            if (d < 0) return -1;
            if (d > 0) return 1;
            return 0;
        });

        root.MinDistance = 0;
        queue.Enqueue(new Tuple<long, Node>(0, root));

        while (queue.Count > 0)
        {
            var a = queue.Dequeue();
            var cost = a.Item1;
            var node = a.Item2;
            foreach (var edge in node.Edges)
            {
                var altDistance = node.MinDistance + edge.Distance;
                if (edge.EndNode.MinDistance > altDistance)
                {
                    edge.EndNode.MinDistance = altDistance;
                    edge.EndNode.InEdge = edge;
                    queue.Enqueue(new Tuple<long, Node>(altDistance, edge.EndNode));
                }
            }
        }
    }
}

public class PriorityQueue<T>
{
    List<T> list = new List<T>();
    readonly IComparer<T> comp = Comparer<T>.Default;
    class Comparer : IComparer<T>
    {
        readonly Comparison<T> comparison;
        public Comparer(Comparison<T> comparison) { this.comparison = comparison; }
        public int Compare(T x, T y) { return comparison(x, y); }
    }

    public PriorityQueue() { }
    public PriorityQueue(Comparison<T> comp) { this.comp = new Comparer(comp); }
    public void Enqueue(T item)
    {
        int i = list.BinarySearch(item, comp);
        list.Insert(i < 0 ? ~i : i, item);
    }
    public T Dequeue() { T r = list[0]; list.RemoveAt(0); return r; }
    public T Peek() { return list[0]; }
    public int Count { get { return list.Count; } }
    public T this[int i] { get { return list[i]; } set { list[i] = value; } }
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