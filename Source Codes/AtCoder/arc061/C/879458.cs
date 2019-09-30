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
        int cost = BFS01(0, N - 1, E);
        Console.WriteLine((cost == INF) ? -1 : cost / 2);
    }

    static readonly int INF = (int)1e9;
    int BFS01(int S, int T, List<Edge>[] E)
    {
        var deq = new Deque<long>();
        int N = E.Length;
        var minCost = new int[N];
        for (int i = 0; i < N; i++) minCost[i] = INF;
        minCost[S] = 0;
        deq.PushBack((long)S << 32);
        while (deq.Count > 0)
        {
            long mask = deq.PopFront();
            int a = (int)(mask >> 32), cost = (int)mask;
            if (cost > minCost[a]) continue;
            if (a == T) return cost;
            foreach (var e in E[a])
                if (minCost[e.to] == INF)
                {
                    minCost[e.to] = minCost[a] + e.cost;
                    if (e.cost == 0)
                        deq.PushFront(((long)e.to << 32) + minCost[a]);
                    else
                        deq.PushBack(((long)e.to << 32) + minCost[a] + 1);
                }
        }
        return INF;
    }

    class Deque<T>
    {
        private T[] A = new T[3];
        private int L;
        public int Count { get; private set; }

        public T PeekFront() { return A[L]; }
        public T PeekBack() { return A[(L + Count - 1) % A.Length]; }
        public void PushFront(T val)
        {
            if (Count++ == A.Length) DoubleArray();
            L = (L + A.Length - 1) % A.Length;
            A[L] = val;
        }
        public void PushBack(T val)
        {
            if (Count == A.Length) DoubleArray();
            A[(L + Count++) % A.Length] = val;
        }
        public T PopFront()
        {
            if (Count-- == 0) throw new InvalidOperationException("empty");
            T res = A[L];
            L = (L + 1) % A.Length;
            return res;
        }
        public T PopBack()
        {
            if (Count-- == 0) throw new InvalidOperationException("empty");
            return A[(L + Count) % A.Length];
        }
        public void DoubleArray()
        {
            T[] next = new T[A.Length * 2];
            Array.Copy(A, L, next, 0, A.Length - L);
            Array.Copy(A, 0, next, A.Length - L, L);
            L = 0;
            A = next;
        }
    }

    struct Edge
    {
        public int to;
        public int cost;
        public Edge(int to, int c)
        {
            this.to = to; this.cost = c;
        }
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