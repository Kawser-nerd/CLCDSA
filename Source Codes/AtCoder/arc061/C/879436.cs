using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly long Big = (long)1e9;

    public void Solve()
    {
        int N = Reader.Int(), M = Reader.Int();
        var E = new List<Edge>[N + M * 2];
        for (int i = 0; i < E.Length; i++) E[i] = new List<Edge>();
        var dic = new Dictionary<long, int>();
        int numNodes = N;

        Func<int, int, int> ColorNode = (at, color) =>
        {
            long key = (long)at * Big + color;
            if (dic.ContainsKey(key)) return dic[key];
            return dic[key] = numNodes++;
        };
        Action<int, int, int> AddEdge = (a, b, c) =>
        {
            E[a].Add(new Edge(b, c));
            E[b].Add(new Edge(a, c));
        };

        for (int i = 0; i < M; i++)
        {
            int a = Reader.Int() - 1, b = Reader.Int() - 1, c = Reader.Int();
            int a2 = ColorNode(a, c);
            int b2 = ColorNode(b, c);
            AddEdge(a, a2, 1);
            AddEdge(b, b2, 1);
            AddEdge(a2, b2, 0);
        }
        var cost = ShortestPath(0, E);
        Console.WriteLine((cost[N - 1] == INF) ? -1 : cost[N - 1] / 2);
    }

    static readonly int INF = (int)1e9;
    int[] ShortestPath(int start, List<Edge>[] E)
    {
        int N = E.Length;
        bool[] inQue = new bool[N];
        var que = new Queue<int>();
        que.Enqueue(start);
        var minCost = new int[N];
        for (int i = 0; i < N; i++) minCost[i] = INF;
        minCost[start] = 0;

        while (que.Count > 0)
        {
            int v = que.Dequeue();
            inQue[v] = false;
            foreach (var e in E[v])
                if (minCost[v] + e.cost < minCost[e.to])
                {
                    minCost[e.to] = minCost[v] + e.cost;
                    if (!inQue[e.to])
                    {
                        inQue[e.to] = true;
                        que.Enqueue(e.to);
                    }
                }
        }
        return minCost;
    }

    struct Edge
    {
        public int to;
        public int cost;
        public Edge(int to, int cost) { this.to = to; this.cost = cost; }
        public override string ToString() { return "to:" + to + " cost:" + cost; }
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
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
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