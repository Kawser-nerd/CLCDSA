using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 100000000000007;
    public static void Main()
    {
        int N = NextInt();
        Node[] node = new Node[N];
        for (int i = 0; i < N; i++) node[i] = new Node(i);
        int[] a = new int[N - 1];
        int[] b = new int[N - 1];
        long[] c = new long[N - 1];
        for (int i = 0; i < N - 1; i++)
        {
            int A = NextInt() - 1;
            int B = NextInt() - 1;
            int C = NextInt();
            Edge e = new Edge();
            e.to = B;
            e.cost = C;
            node[A].relate.Add(e);
            e = new Edge();
            e.to = A;
            e.cost = C;
            node[B].relate.Add(e);
        }
        int Q = NextInt();
        int K = NextInt() - 1;
        Stack<Node> stack = new Stack<Node>();
        stack.Push(node[K]);
        while (stack.Count() != 0)
        {
            Node now = stack.Pop();
            now.visit = true;
            foreach (var e in now.relate)
            {
                if (!node[e.to].visit)
                {
                    node[e.to].cost = now.cost + e.cost;
                    stack.Push(node[e.to]);
                }
            }
        }
        for(int i = 0;i < Q; i++)
        {
            Console.WriteLine(node[NextInt()-1].cost + node[NextInt() - 1].cost);
        }
    }
}
public class Node
{
    public List<Edge> relate = new List<Edge>();
    public int name = 0;
    public bool visit = false;
    public long cost = 0;
    public Node(int name) { this.name = name; }
}
public class Edge
{
    public int to;
    public long cost;
}
public class Input
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