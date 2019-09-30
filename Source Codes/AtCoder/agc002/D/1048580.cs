using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    int N, M, NQ;
    int[][] E, Q;

    public void Solve()
    {
        Init();
        Queue<List<int>> cand = new Queue<List<int>>(), nextCand;
        Queue<int> range = new Queue<int>(), nextRange;
        cand.Enqueue(Enu.Range(0, NQ).ToList());
        range.Enqueue(0); range.Enqueue(M);
        var ans = new int[NQ];

        for (; cand.Count > 0; cand = nextCand, range = nextRange)
        {
            nextCand = new Queue<List<int>>();
            nextRange = new Queue<int>();
            var uf = new UnionFind(N);
            while (cand.Count > 0)
            {
                var who = cand.Dequeue();
                int L = range.Dequeue(), R = range.Dequeue(), mid = L + R >> 1;
                for (int i = L; i < mid; i++) uf.Unite(E[i][0], E[i][1]);
                var next = new[] { new List<int>(), new List<int>() };
                foreach (int i in who)
                {
                    int num = uf.Count(Q[i][0]) + (uf.Same(Q[i][0], Q[i][1]) ? 0 : uf.Count(Q[i][1]));
                    if (num >= Q[i][2]) { ans[i] = mid; next[0].Add(i); }
                    else next[1].Add(i);
                }
                for (int i = mid; i < R; i++) uf.Unite(E[i][0], E[i][1]);
                if (L == R - 1) { who.ForEach(i => ans[i] = R); continue; }
                nextCand.Enqueue(next[0]); nextCand.Enqueue(next[1]);
                nextRange.Enqueue(L); nextRange.Enqueue(mid);
                nextRange.Enqueue(mid); nextRange.Enqueue(R);
            }
        }

        Console.WriteLine(string.Join("\n", ans));
    }

    void Init()
    {
        N = Reader.Int();
        M = Reader.Int();
        E = Reader.IntTable(M);
        NQ = Reader.Int();
        Q = Reader.IntTable(NQ);
        foreach (var e in E) { e[0]--; e[1]--; }
        foreach (var q in Q) { q[0]--; q[1]--; }
    }
}

class UnionFind
{
    private int[] parent;
    private byte[] rank;

    public UnionFind(int N)
    {
        parent = new int[N];
        rank = new byte[N];
        for (int i = 0; i < N; i++) parent[i] = -1;
    }
    public int Root(int x)
    {
        if (parent[x] < 0) return x;
        return parent[x] = Root(parent[x]);
    }
    public bool Same(int x, int y)
    {
        return Root(x) == Root(y);
    }
    public int Count(int x)
    {
        return -parent[Root(x)];
    }
    public bool Unite(int x, int y)
    {
        x = Root(x); y = Root(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) { var t = x; x = y; y = t; }
        if (rank[x] == rank[y]) rank[y]++;
        parent[y] += parent[x];
        parent[x] = y;
        return true;
    }
    public Dictionary<int, List<int>> Components()
    {
        var dic = new Dictionary<int, List<int>>();
        for (int i = 0; i < parent.Length; i++)
        {
            int root = Root(i);
            if (!dic.ContainsKey(root)) dic[root] = new List<int>();
            dic[root].Add(i);
        }
        return dic;
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