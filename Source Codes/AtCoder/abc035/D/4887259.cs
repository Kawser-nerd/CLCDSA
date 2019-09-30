using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static int M;
    static int T;
    static int[] A;
    static Dijkstra.Node[] fnodes;
    static Dijkstra.Node[] rnodes;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        M = Input.NextInt();
        T = Input.NextInt();
        A = Input.LineInt();

        InitNodes(fnodes = new Dijkstra.Node[N]);
        InitNodes(rnodes = new Dijkstra.Node[N]);

        for (int i = 0; i < M; i++)
        {
            var abc = Input.LineInt();
            var a = abc[0] - 1;
            var b = abc[1] - 1;
            var c = abc[2];

            fnodes[a].CreateEdge(fnodes[b], c);
            rnodes[b].CreateEdge(rnodes[a], c);
        }

        var search = new Dijkstra();
        search.Search(fnodes[0]);
        search.Search(rnodes[0]);

        long max = long.MinValue;
        for (int i = 0; i < N; i++)
        {
            if (!fnodes[i].Reachable || !rnodes[i].Reachable)
                continue;
            var aa = fnodes[i].MinDistance + rnodes[i].MinDistance;
            var mm = fnodes[i].Money;
            var ax = (T - aa) * mm;
            max = Math.Max(max, ax);
        }

        Console.WriteLine(max);
    }

    static void InitNodes(Dijkstra.Node[] nodes)
    {
        for (int i = 0; i < nodes.Length; i++)
        {
            nodes[i] = new Dijkstra.Node() { Money = A[i] };
        }
    }
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
    }

    public class Node
    {
        public List<Edge> Edges { get; set; } = new List<Edge>();
        public long MinDistance { get; set; } = long.MaxValue;
        public bool Reachable => MinDistance != long.MaxValue;

        public Edge CreateEdge(Node destination, long distance)
        {
            var edge = new Edge(this, destination, distance);
            Edges.Add(edge);
            return edge;
        }

        public long Money = 0;

        public override string ToString()
        {
            return $"Distance:{MinDistance}, Money:{Money}";
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
                    queue.Enqueue(new Tuple<long, Node>(altDistance, edge.EndNode));
                }
            }
        }
    }
}

class PriorityQueue<T>
{
    private readonly List<T> heap;
    private readonly Comparison<T> compare;
    private int size;
    public PriorityQueue() : this(Comparer<T>.Default) { }
    public PriorityQueue(IComparer<T> comparer) : this(16, comparer.Compare) { }
    public PriorityQueue(Comparison<T> comparison) : this(16, comparison) { }
    public PriorityQueue(int capacity, Comparison<T> comparison)
    {
        this.heap = new List<T>(capacity);
        this.compare = comparison;
    }
    public void Enqueue(T item)
    {
        this.heap.Add(item);
        var i = size++;
        while (i > 0)
        {
            var p = (i - 1) >> 1;
            if (compare(this.heap[p], item) <= 0)
                break;
            this.heap[i] = heap[p];
            i = p;
        }
        this.heap[i] = item;

    }
    public T Dequeue()
    {
        var ret = this.heap[0];
        var x = this.heap[--size];
        var i = 0;
        while ((i << 1) + 1 < size)
        {
            var a = (i << 1) + 1;
            var b = (i << 1) + 2;
            if (b < size && compare(heap[b], heap[a]) < 0) a = b;
            if (compare(heap[a], x) >= 0)
                break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        heap.RemoveAt(size);
        return ret;
    }
    public T Peek() { return heap[0]; }
    public int Count { get { return size; } }
    public bool Any() { return size > 0; }
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