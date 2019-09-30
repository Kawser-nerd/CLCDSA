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
        var g = new LowestCommonAncestor(N, E, 0, 1);
        var ans = new StringBuilder();
        foreach (var q in Q)
        {
            int a = q[0] - 1, b = q[1] - 1;
            int len = 1 + g.Dist(a, b);
            ans.Append(len + "\n");
        }
        Console.Write(ans);
    }
}

public class LowestCommonAncestor
{
    List<int>[] G;
    RangeMinQueryIndex Rmq;
    List<int> Vs = new List<int>();
    List<int> depth = new List<int>();
    int[] Id, depthAt;

    public LowestCommonAncestor(int N)
    {
        G = new List<int>[N];
        for (int i = 0; i < N; i++) G[i] = new List<int>();
    }
    public LowestCommonAncestor(int N, int[][] E, int root = 0, int origin = 0)
    {
        G = new List<int>[N];
        for (int i = 0; i < N; i++) G[i] = new List<int>();
        if (E != null) Array.ForEach(E, e => AddEdge(e[0] - origin, e[1] - origin));
        Init(root);
    }

    public void AddEdge(int a, int b) { G[a].Add(b); G[b].Add(a); }

    public int Get(int a, int b)
    {
        int L = Math.Min(Id[a], Id[b]);
        int R = Math.Max(Id[a], Id[b]) + 1;
        int i = Rmq.Get(L, R);
        return Vs[i];
    }

    public int Depth(int a) { return depthAt[a]; }
    public int Dist(int a, int b)
    {
        return depthAt[a] + depthAt[b] - depthAt[Get(a, b)] * 2;
    }

    public void Init(int root)
    {
        Id = new int[G.Length];
        depthAt = new int[G.Length];
        DFS(root, -1, 0);
        Rmq = new RangeMinQueryIndex(depth.Count);
        for (int i = 0; i < depth.Count; i++)
            Rmq.Set(i, depth[i]);
    }

    void DFS(int v, int prev, int d)
    {
        Id[v] = Vs.Count;
        Vs.Add(v);
        depth.Add(d);
        depthAt[v] = d;
        foreach (int next in G[v])
            if (next != prev)
            {
                DFS(next, v, d + 1);
                Vs.Add(v);
                depth.Add(d);
            }
    }
}

public class RangeMinQueryIndex
{
    static readonly int INF = (int)1e9;
    public readonly int N;
    readonly int[] tree;
    readonly int[] index;

    public RangeMinQueryIndex(int N)
    {
        while (N < 2 || (N & (N - 1)) != 0) { N += N & -N; }
        this.N = N;
        tree = new int[N * 2];
        index = new int[N * 2];
        for (int i = 0; i < tree.Length; i++) tree[i] = INF;
    }
    public void Set(int i, int val)
    {
        int id = i;
        i += N - 1;
        tree[i] = val;
        index[i] = id;
        while (i > 0)
        {
            i = (i - 1) / 2;
            int L = i * 2 + 1, R = i * 2 + 2;
            if (tree[L] <= tree[R]) { tree[i] = tree[L]; index[i] = index[L]; }
            else { tree[i] = tree[R]; index[i] = index[R]; }
        }
    }
    // [L, R)
    public int Get(int L, int R) { int v = -1; return Rec(0, ref v, 0, N, L, R); }
    private int Rec(int i, ref int val, int currL, int currR, int L, int R)
    {
        if (currL >= R || currR <= L) { val = INF; return -1; }
        if (currL >= L && currR <= R) { val = tree[i]; return index[i]; }
        int mid = (currL + currR) / 2;
        int Lv = INF, Rv = INF;
        int Li = Rec(i * 2 + 1, ref Lv, currL, mid, L, R);
        int Ri = Rec(i * 2 + 2, ref Rv, mid, currR, L, R);
        if (Lv <= Rv) { val = Lv; return Li; }
        val = Rv; return Ri;
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