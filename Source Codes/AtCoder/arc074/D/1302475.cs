using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int H = Reader.Int(), W = Reader.Int();
        var grid = Reader.StringArray(H);
        Func<int, int> RowId = r => r;
        Func<int, int> ColId = c => H + c;
        int S = H + W, T = S + 1;
        var dinic = new Dinic(H + W + 2);

        for (int r = 0; r < H; r++)
            for (int c = 0; c < W; c++)
                if (grid[r][c] == 'o')
                {
                    dinic.AddEdge(RowId(r), ColId(c), 1);
                    dinic.AddEdge(ColId(c), RowId(r), 1);
                }
                else if (grid[r][c] == 'S')
                {
                    dinic.AddEdge(S, RowId(r), Dinic.INF);
                    dinic.AddEdge(S, ColId(c), Dinic.INF);
                }
                else if (grid[r][c] == 'T')
                {
                    dinic.AddEdge(RowId(r), T, Dinic.INF);
                    dinic.AddEdge(ColId(c), T, Dinic.INF);
                }

        int ans = dinic.MaxFlow(S, T);
        Console.WriteLine(ans >= Dinic.INF ? -1 : ans);
    }
}

public class Dinic
{
    public static readonly int INF = (int)1e9;
    List<Edge>[] G;
    int S, T;
    int[] level;
    int[] iter;

    public Dinic(int V)
    {
        G = new List<Edge>[V];
        for (int i = 0; i < V; i++) G[i] = new List<Edge>();
    }
    public void AddEdge(int from, int to, int capacity)
    {
        G[from].Add(new Edge(to, capacity, G[to].Count));
        G[to].Add(new Edge(from, 0, G[from].Count - 1));
    }
    public int MaxFlow(int s, int t)
    {
        S = s; T = t;
        int flow = 0;
        level = new int[G.Length];
        while (true)
        {
            BFS();
            if (level[T] < 0) return flow;
            iter = new int[G.Length];
            int f;
            while ((f = DFS(S, INF)) > 0) { flow += f; }
        }
    }
    void BFS()
    {
        for (int i = 0; i < level.Length; i++) level[i] = -1;
        Queue<int> que = new Queue<int>();
        que.Enqueue(S);
        level[S] = 0;
        while (que.Count > 0)
        {
            int v = que.Dequeue();
            foreach (Edge e in G[v])
                if (e.capacity > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    que.Enqueue(e.to);
                }
        }
    }
    int DFS(int v, int flow)
    {
        if (v == T) return flow;
        while (iter[v] < G[v].Count)
        {
            Edge e = G[v][iter[v]];
            if (e.capacity > 0 && level[v] < level[e.to])
            {
                int d = DFS(e.to, Math.Min(flow, e.capacity));
                if (d > 0)
                {
                    e.capacity -= d;
                    G[e.to][e.reverse].capacity += d;
                    return d;
                }
            }
            iter[v]++;
        }
        return 0;
    }
}

public class Edge
{
    public int to, reverse;
    public int capacity;
    public Edge(int to, int capacity, int reverse)
    {
        this.to = to;
        this.capacity = capacity;
        this.reverse = reverse;
    }
    public override string ToString()
    {
        return "to:" + to + " cap:" + capacity;
    }
}



class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string[] Split(string s) { return s.Split(separator, op); }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}