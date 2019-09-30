using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int sx, sy, tx, ty;
    static bool revx;
    static bool revy;

    public static void Main(string[] args)
    {
        checked
        {
            sx = Input.NextInt();
            sy = Input.NextInt();
            tx = Input.NextInt();
            ty = Input.NextInt();

            tx -= sx;
            ty -= sy;

            revx = tx < 0; if (revx) tx = -tx;
            revy = ty < 0; if (revy) ty = -ty;

            var sb = new StringBuilder();
            if (tx == 0)
            {
                sb.Append(MakeR());
                for (int i = 0; i < ty; i++)
                    sb.Append(MakeU());
                sb.Append(MakeL());
                sb.Append(MakeD());
                sb.Append(MakeR());
                sb.Append(MakeR());
                for (int i = 0; i < ty + 2; i++)
                    sb.Append(MakeU());
                sb.Append(MakeL());
                sb.Append(MakeL());
                sb.Append(MakeD());
                sb.Append(MakeL());
                for (int i = 0; i < ty; i++)
                    sb.Append(MakeD());
                sb.Append(MakeR());
            }
            else if (ty == 0)
            {
                for (int i = 0; i < tx; i++)
                    sb.Append(MakeR());
                sb.Append(MakeU());
                for (int i = 0; i < tx; i++)
                    sb.Append(MakeL());
                sb.Append(MakeD());

                sb.Append(MakeD());
                for (int i = 0; i < tx; i++)
                    sb.Append(MakeR());
                sb.Append(MakeU());

                sb.Append(MakeR());
                sb.Append(MakeU());
                sb.Append(MakeU());
                for (int i = 0; i < tx+2; i++)
                    sb.Append(MakeL());
                sb.Append(MakeD());
                sb.Append(MakeD());
                sb.Append(MakeR());
            }
            else
            {
                for (int i = 0; i < tx; i++)
                    sb.Append(MakeR());
                for (int i = 0; i < ty + 1; i++)
                    sb.Append(MakeU());
                for (int i = 0; i < tx + 1; i++)
                    sb.Append(MakeL());
                for (int i = 0; i < ty + 1; i++)
                    sb.Append(MakeD());
                sb.Append(MakeR());
                sb.Append(MakeD());
                for (int i = 0; i < tx + 1; i++)
                    sb.Append(MakeR());
                for (int i = 0; i < ty + 1; i++)
                    sb.Append(MakeU());
                for (int i = 0; i < tx + 1; i++)
                    sb.Append(MakeL());
                for (int i = 0; i < ty; i++)
                    sb.Append(MakeD());
            }

            Console.WriteLine(sb.ToString());
        }
    }

    static string MakeL() => !revx ? "L" : "R";
    static string MakeR() => revx ? "L" : "R";
    static string MakeU() => !revy ? "U" : "D";
    static string MakeD() => revy ? "U" : "D";


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