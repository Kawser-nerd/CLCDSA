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
        var g = new HLDecomposition(N, E, 1);
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

public class HLDecomposition
{
    int N;
    List<int>[] E;
    public int[] Y, X, Size, Parent, Up, UnderL, UnderR;
    public List<List<int>> Path = new List<List<int>>();
    List<int> PathDepth = new List<int>();


    // F(pathId, L, R)
    public void Query(int a, int b, Action<int, int, int> F)
    {
        for (int at = Y[a], L = 0, R, na = a, nb = b; a != -1; a = na, b = nb)
        {
            if (Y[a] == Y[b]) { at = Y[a]; L = Math.Min(X[a], X[b]); R = Math.Max(X[a], X[b]); na = -1; }
            else if (PathDepth[Y[a]] >= PathDepth[Y[b]]) { at = Y[a]; L = 0; R = X[a]; na = Up[a]; }
            else { at = Y[b]; L = 0; R = X[b]; nb = Up[b]; }
            F(at, L, R + 1);
        }
    }

    public HLDecomposition(int N) { Init(N); }
    public HLDecomposition(int N, int[][] E, int origin = 0)
    {
        Init(N);
        Array.ForEach(E, e => AddEdge(e[0] - origin, e[1] - origin));
        Build();
    }

    void Init(int N)
    {
        this.N = N;
        Y = new int[N]; X = new int[N];
        Size = new int[N]; Parent = new int[N]; Up = new int[N];
        UnderL = new int[N]; UnderR = new int[N];
        E = new List<int>[N];
        for (int i = 0; i < N; i++) E[i] = new List<int>();
    }

    public void AddEdge(int a, int b)
    {
        E[a].Add(b);
        E[b].Add(a);
    }

    public void Build()
    {
        CountNodes();
        CompressPath();
    }

    void CountNodes()
    {
        var stack = new Stack<int>();
        var nodes = new int[N];
        int ni = N - 1;
        stack.Push(0);
        while (stack.Count > 0)
        {
            int a = stack.Pop();
            for (int ei = 0; ei < E[a].Count; ei++)
            {
                int b = E[a][ei];
                if (b == Parent[a]) { E[a].RemoveAt(ei); ei--; }
                else { Parent[b] = a; stack.Push(b); }
            }
            nodes[ni--] = a;
        }
        foreach (int a in nodes)
        {
            Size[a] = 1;
            var e = E[a];
            for (int i = 0; i < e.Count; i++)
            {
                int b = e[i];
                Size[a] += Size[b];
                if (Size[b] > Size[e[0]]) { int t = e[0]; e[0] = b; e[i] = t; }
            }
        }
    }

    void CompressPath()
    {
        var stack = new Stack<int>();
        stack.Push(0);
        while (stack.Count > 0)
        {
            int a = stack.Pop();
            if (a < 0) { UnderR[~a] = Path.Count; continue; }
            if (X[a] == 0)
            {
                Path.Add(new List<int>());
                PathDepth.Add(a == 0 ? 0 : PathDepth[Y[Parent[a]]] + 1);
            }
            int pathId = Y[a] = Path.Count - 1;
            Path[pathId].Add(a);
            Up[a] = Parent[Path[pathId][0]];
            UnderL[a] = Path.Count;
            stack.Push(~a);
            if (E[a].Count == 0) continue;
            for (int i = E[a].Count - 1; i > 0; i--)
                stack.Push(E[a][i]);
            X[E[a][0]] = X[a] + 1;
            stack.Push(E[a][0]);
        }
    }

    public int LCA(int a, int b)
    {
        if (Y[a] == Y[b]) return (X[a] < X[b]) ? a : b;
        if (PathDepth[Y[a]] >= PathDepth[Y[b]])
            return LCA(Parent[Path[Y[a]][0]], b);
        return LCA(a, Parent[Path[Y[b]][0]]);
    }

    public int Dist(int a, int b)
    {
        if (Y[a] == Y[b]) return Math.Abs(X[a] - X[b]);
        if (PathDepth[Y[a]] >= PathDepth[Y[b]])
            return X[a] + 1 + Dist(Parent[Path[Y[a]][0]], b);
        return X[b] + 1 + Dist(a, Parent[Path[Y[b]][0]]);
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