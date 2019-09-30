using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    private struct Pair { public int x, y; }
    public static void Main()
    {
        long N = NextLong();
        int M = NextInt();
        UnionFind UF = new UnionFind((int)N);
        Pair[] p = new Pair[M];
        for (int i = 0; i < M; i++)
        {
            p[i].x = NextInt() - 1;
            p[i].y = NextInt() - 1;
        }
        Array.Reverse(p);
        List<long> ans = new List<long>();
        long box = (N - 1) * N / 2;
        for (int i = 0; i < M; i++)
        {
            ans.Add(box);
            if (UF.Same(p[i].x, p[i].y)) continue;
            else { box -= UF.Get(p[i].x) * UF.Get(p[i].y); }
            UF.Unite(p[i].x, p[i].y);
        }
        ans.Reverse();
        ans.ToList().ForEach(Console.WriteLine);
    }
}

public class UnionFind
{
    private List<int> parent = new List<int>();
    private void Swap(ref int a, ref int b) { int c = a; a = b; b = c; }

    public UnionFind(int N)
    {
        for (int i = 0; i < N; i++) { parent.Add(-1); }
    }

    public int Root(int a)
    {
        if (parent[a] < 0) return a;
        else return parent[a] = Root(parent[a]);
    }

    public void Unite(int a, int b)
    {
        a = Root(a);
        b = Root(b);
        if (a == b) return;
        if (parent[a] > parent[b]) Swap(ref a, ref b);
        parent[a] += parent[b];
        parent[b] = a;
    }

    public int Get(int a) { return -parent[Root(a)]; }

    public bool Same(int a, int b) { return (Root(a) == Root(b)); }
}

public class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static char NextChar() { Confirm(); return char.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}