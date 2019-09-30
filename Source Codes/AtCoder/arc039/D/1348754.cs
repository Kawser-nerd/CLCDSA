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
        //Test();
        int N = Reader.Int(), M = Reader.Int();
        var E = Reader.IntTable(M);
        int NQ = Reader.Int();
        var Q = Reader.IntTable(NQ);
        var comp = new TwoEdgeConnectedComponent(N, E, 1);
        var hld = new HLDecomposition(comp.Count);
        for (int a = 0; a < comp.Count; a++)
            foreach (int b in comp[a].Edges)
                if (a < b)
                    hld.AddEdge(a, b);
        hld.Build();
        var ans = new bool[NQ];
        for (int i = 0; i < NQ; i++)
        {
            int a = comp.VtoComponentId(Q[i][0] - 1);
            int b = comp.VtoComponentId(Q[i][1] - 1);
            int c = comp.VtoComponentId(Q[i][2] - 1);
            ans[i] = a == b && a == c || hld.Dist(a, b) + hld.Dist(b, c) == hld.Dist(a, c);
        }
        Console.WriteLine(string.Join("\n", ans.Select(b => b ? "OK" : "NG")));
    }

    void Test()
    {
        int N = (int)1e5;
        int M = N - 1; // (int)2e5;
        var E = new int[M][];
        int ei = 0;
        for (int i = 0; i < M; i++)
        {
            E[i] = new int[] { i + 1, i + 2 };
        }
        int NQ = (int)1e5;
        var Q = new int[NQ][];
        var random = new Random(0);
        for (int i = 0; i < NQ; i++)
            Q[i] = new[] { random.Next(N) + 1, random.Next(N) + 1, random.Next(N) + 1 };

        var sw = Stopwatch.StartNew();
        var comp = new TwoEdgeConnectedComponent(N, E, 1);
        Console.WriteLine("TwoEdge: " + sw.ElapsedMilliseconds);

        sw.Restart();

        var hld = new HLDecomposition(comp.Count);
        for (int a = 0; a < comp.Count; a++)
            foreach (int b in comp[a].Edges)
                if (a < b)
                    hld.AddEdge(a, b);
        hld.Build();

        Console.WriteLine("HLD: " + sw.ElapsedMilliseconds);
        sw.Restart();

        var ans = new bool[NQ];
        for (int i = 0; i < NQ; i++)
        {
            int a = comp.VtoComponentId(Q[i][0] - 1);
            int b = comp.VtoComponentId(Q[i][1] - 1);
            int c = comp.VtoComponentId(Q[i][2] - 1);
            ans[i] = a == b && a == c || hld.Dist(a, b) + hld.Dist(b, c) == hld.Dist(a, c);
        }
        Console.WriteLine(sw.ElapsedMilliseconds);
        Console.ReadLine();
    }
}

public class Component
{
    public int[] Vertexes;
    public int[] Edges;
    public Component(int[] vs) { Vertexes = vs; }
}

public class TwoEdgeConnectedComponent
{
    int N, id;
    List<int>[] E;
    int[] VtoCompId, order;
    bool[] inS;
    Stack<int> S = new Stack<int>(), roots = new Stack<int>();
    HashSet<long> BridgesSet = new HashSet<long>();
    List<Component> Components = new List<Component>();
    public List<int[]> Bridges = new List<int[]>();

    public int Count { get { return Components.Count; } }

    public Component this[int i] { get { return Components[i]; } }

    public bool IsBridge(int a, int b) { return BridgesSet.Contains(ToKey(a, b)); }

    public int VtoComponentId(int v) { return VtoCompId[v]; }

    public bool SameComponent(int a, int b) { return VtoCompId[a] == VtoCompId[b]; }


    public TwoEdgeConnectedComponent(int N) { Init(N); }
    public TwoEdgeConnectedComponent(int N, int[][] E, int origin = 0)
    {
        Init(N);
        Array.ForEach(E, e => AddEdge(e[0] - origin, e[1] - origin));
        Decompose();
    }

    void Init(int N)
    {
        this.N = N;
        VtoCompId = new int[N];
        order = new int[N];
        inS = new bool[N];
        E = new List<int>[N];
        for (int i = 0; i < N; i++) E[i] = new List<int>();
    }

    public void AddEdge(int a, int b)
    {
        E[a].Add(b);
        E[b].Add(a);
    }

    public void Decompose()
    {
        for (int i = 0; i < N; i++)
            if (order[i] == 0)
                DFS(i, -1);
        Bridges.Sort((a, b) => a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        foreach (var comp in Components)
        {
            var es = new HashSet<int>();
            foreach (int a in comp.Vertexes)
                foreach (int b in E[a])
                    es.Add(VtoCompId[b]);
            comp.Edges = es.ToArray();
            Array.Sort(comp.Edges);
        }
    }

    void DFS(int v, int prev)
    {
        order[v] = ++id;
        roots.Push(v);
        S.Push(v);
        inS[v] = true;
        foreach (int next in E[v])
            if (order[next] == 0)
                DFS(next, v);
            else if (next != prev && inS[next])
                while (order[roots.Peek()] > order[next]) roots.Pop();
        if (roots.Peek() != v) return;
        if (prev != -1) AddBridge(prev, v);
        AddComponent(prev, v);
    }

    void AddBridge(int a, int b)
    {
        //BridgesSet.Add(ToKey(a, b));
        Bridges.Add(new[] { Math.Min(a, b), Math.Max(a, b) });
    }

    void AddComponent(int prev, int root)
    {
        int compId = Components.Count;
        var vs = new List<int>();
        for (; ; )
        {
            int v = S.Pop();
            inS[v] = false;
            VtoCompId[v] = compId;
            vs.Add(v);
            if (v == root) break;
        }
        vs.Sort();
        Components.Add(new Component(vs.ToArray()));
        roots.Pop();
    }

    long ToKey(long a, long b) { return a < b ? a * N + b : b * N + a; }

}


class HLDecomposition
{
    public int N;
    List<int>[] E;
    int[] Y, X, Size, Parent, Up, UnderL, UnderR;
    List<List<int>> Path = new List<List<int>>();
    List<int> PathDepth = new List<int>();


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