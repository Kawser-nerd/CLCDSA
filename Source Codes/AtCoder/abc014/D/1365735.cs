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
        int N = Reader.Int();
        var E = Reader.IntTable(N - 1);
        int NQ = Reader.Int();
        var Q = Reader.IntTable(NQ);
        var g = new LowestCommonAncestor(N, E, 1);
        var ans = new StringBuilder();
        foreach (var q in Q)
        {
            int a = q[0] - 1, b = q[1] - 1;
            int len = 1 + g.Dist(a, b);
            ans.AppendLine(len + "");
        }
        Console.Write(ans);
    }
}

public class LowestCommonAncestor
{
    int N;
    List<int>[] G;
    int[] id, depth, parent;
    long[] seg, Q = new long[100];

    public LowestCommonAncestor(int N)
    {
        G = new List<int>[N];
        for (int i = 0; i < N; i++) G[i] = new List<int>();
    }
    public LowestCommonAncestor(int N, int[][] E, int origin = 0, int root = 0)
    {
        G = new List<int>[N];
        for (int i = 0; i < N; i++) G[i] = new List<int>();
        if (E != null) Array.ForEach(E, e => AddEdge(e[0] - origin, e[1] - origin));
        Build(root);
    }

    public void AddEdge(int a, int b) { G[a].Add(b); G[b].Add(a); }

    public void Build(int root)
    {
        id = new int[G.Length];
        depth = new int[G.Length];
        parent = new int[G.Length];
        for (int i = 0; i < parent.Length; i++) parent[i] = -1;
        seg = new long[G.Length * 2 - 1];
        DFS(root);
        BuildSegmentTree();
    }

    public int LCA(int a, int b)
    {
        if (id[a] < id[b]) return (int)RangeMin(id[a], id[b] + 1);
        return (int)RangeMin(id[b], id[a] + 1);
    }

    public int Depth(int a) { return depth[a]; }

    public int Dist(int a, int b) { return depth[a] + depth[b] - depth[LCA(a, b)] * 2; }

    void DFS(int root)
    {
        var stack = new int[G.Length * 2];
        stack[0] = root;
        int index = 0;
        for (int si = 1; si > 0; )
        {
            int v = stack[--si];
            if (v < 0) { seg[index++] = ((long)depth[~v] << 32) + ~v; continue; }
            id[v] = index;
            seg[index++] = ((long)depth[v] << 32) + v;
            foreach (int next in G[v])
                if (next != parent[v])
                {
                    stack[si++] = ~v;
                    stack[si++] = next;
                    parent[next] = v;
                    depth[next] = depth[v] + 1;
                }
        }
    }

    void BuildSegmentTree()
    {
        N = 2;
        while (N < seg.Length) N *= 2;
        Array.Resize(ref seg, N * 2);
        Array.Copy(seg, 0, seg, N, G.Length * 2 - 1);
        for (int i = G.Length * 2 - 1; i < N; i++) seg[N + i] = long.MaxValue;
        for (int i = N - 1; i > 0; i--)
            seg[i] = Math.Min(seg[i << 1], seg[i << 1 | 1]);
    }

    long RangeMin(int L, int R)
    {
        long res = long.MaxValue;
        Q[0] = 1L << 32;
        for (int s = 0, t = 1, len = N, first = 1; s != t; ++s)
        {
            int i = (int)(Q[s] >> 32), a = (int)Q[s];
            if (s == first) { len >>= 1; first = t; }
            if (seg[i] >= res) continue;
            if (a >= L && a + len <= R) { res = seg[i]; continue; }
            int mid = a + (len >> 1);
            if (mid > L) Q[t++] = ((long)(i << 1) << 32) + a;
            if (mid < R) Q[t++] = ((long)(i << 1 | 1) << 32) + mid;
        }
        return res;
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
    static void Init() { Dispose(); A = new string[0]; }
    public static void Set(TextReader r) { Init(); reader = r; }
    public static void Set(string file) { Init(); reader = new StreamReader(file); }
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
    public static void Dispose() { reader.Dispose(); }
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