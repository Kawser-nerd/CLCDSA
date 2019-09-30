using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var a = sc.Integer();
            var F = new int[a];
            var T = new int[a];
            for (int i = 0; i < a; i++)
            {
                F[i] = sc.Integer() - 1;
                T[i] = sc.Integer() - 1;
            }
            var b = sc.Integer();
            var A = new int[b];
            var B = new int[b];
            for (int i = 0; i < b; i++)
            {
                A[i] = sc.Integer() - 1;
                B[i] = sc.Integer() - 1;
            }
            var max = 0;
            for (int i = 0; i < 1 << b; i++)
            {
                var G = new SCCGraph(n);
                for (int j = 0; j < a; j++)
                    G.AddEdge(T[j], F[j]);


                var dame = new bool[n];
                for (int j = 0; j < b; j++)
                {
                    if ((i >> j & 1) == 1)
                    {
                        G.AddEdge(A[j], B[j]);
                    }
                    else
                    {
                        dame[A[j]] = true;
                    }
                }
                G.Build();
                var ok = Enumerate(G.Size, x => true);
                for (int j = 0; j < G.Size; j++)
                {
                    if (G.S[j].Count > 1 || ok[j] == false || dame[G.S[j][0]])
                    {
                        ok[j] = false;
                        foreach (var to in G.G[j])
                            ok[to.to] = false;
                    }
                }
                var cnt = ok.Count(x => x);
                max = Math.Max(max, cnt);
                Debug.WriteLine(cnt);

            }
            IO.Printer.Out.WriteLine(max);


        }

        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex
{
    static public string AsString(this IEnumerable<char> ie) { return new string(System.Linq.Enumerable.ToArray(ie)); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") { return string.Join(st, ie); }
    static public void Main()
    {
        var solver = new Program.Solver();
        solver.Solve();
        Program.IO.Printer.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;
    public class Printer : StreamWriter
    {
        static Printer() { Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false }; }
        public static Printer Out { get; set; }
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(System.IO.Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
        public Printer(System.IO.Stream stream, Encoding encoding) : base(stream, encoding) { }
        public void Write<T>(string format, T[] source) { base.Write(format, source.OfType<object>().ToArray()); }
        public void WriteLine<T>(string format, T[] source) { base.WriteLine(format, source.OfType<object>().ToArray()); }
    }
    public class StreamScanner
    {
        public StreamScanner(Stream stream) { str = stream; }
        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }
        private byte read()
        {
            if (isEof) return 0;
            if (ptr >= len) { ptr = 0; if ((len = str.Read(buf, 0, 1024)) <= 0) { isEof = true; return 0; } }
            return buf[ptr++];
        }
        public char Char() { byte b = 0; do b = read(); while ((b < 33 || 126 < b) && !isEof); return (char)b; }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n'; b = (char)read())
                if (b == 0) break;
                else if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { var s = Scan(); return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN; }
        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n) { return enumerate(n, Char); }
        public string[] Scan(int n) { return enumerate(n, Scan); }
        public double[] Double(int n) { return enumerate(n, Double); }
        public int[] Integer(int n) { return enumerate(n, Integer); }
        public long[] Long(int n) { return enumerate(n, Long); }
    }
}
#endregion
#region  StronglyConnectedComponentsDecomposition
public class SCCGraph
{
    List<Edge>[] g, rg;
    int[] group;
    /// <summary>???????</summary>
    public List<Edge>[] G;
    /// <summary>???????</summary>
    public List<Edge>[] L;
    /// <summary>???????????????</summary>
    public List<int>[] S;
    public int Size { get { return G.Length; } }
    public SCCGraph(int n)
    {
        g = new List<Edge>[n];
        rg = new List<Edge>[n];
        for (int i = 0; i < n; i++)
        {
            g[i] = new List<Edge>();
            rg[i] = new List<Edge>();
        }

    }
    public void AddEdge(int f, int t, long cost = 0)
    {
        g[f].Add(new Edge(f, t, cost));
        rg[t].Add(new Edge(t, f, cost));
    }
    private int Decomposite()
    {
        var n = g.Length;
        var vs = new List<int>(n);



        //dfs
        {
            var iter = new int[n];
            var used = new bool[n];

            for (int i = 0; i < used.Length; i++)
            {
                if (used[i]) continue;

                var stack = new Stack<int>();
                stack.Push(i);
                used[i] = true;
                while (stack.Any())
                {
                    var p = stack.Peek();
                    while (iter[p] < g[p].Count && used[g[p][iter[p]].to]) iter[p]++;
                    if (iter[p] < g[p].Count)
                    {
                        var to = g[p][iter[p]].to;
                        used[to] = true;
                        stack.Push(to);
                    }
                    else
                    {
                        vs.Add(p); stack.Pop();
                    }
                }
            }
        }
        //rdfs
        {
            var iter = new int[n];
            var used = new bool[n];
            group = new int[n];
            var k = 0;
            for (int i = vs.Count - 1; i >= 0; i--)
            {
                if (used[vs[i]]) continue;
                var stack = new Stack<int>();
                stack.Push(vs[i]);
                used[vs[i]] = true;
                group[vs[i]] = k;
                while (stack.Any())
                {
                    var p = stack.Peek();
                    while (iter[p] < rg[p].Count && used[rg[p][iter[p]].to]) iter[p]++;
                    if (iter[p] < rg[p].Count)
                    {
                        var to = rg[p][iter[p]].to;
                        used[to] = true;
                        group[to] = k;
                        stack.Push(to);
                    }
                    else stack.Pop();
                }
                k++;
            }
            return k;
        }


    }
    public void Distinct()
    {
        for (int i = 0; i < G.Length; i++)
        {
            G[i] = G[i].Distinct().ToList();
            L[i] = L[i].Distinct().ToList();
        }

    }
    public void Build()
    {
        var k = Decomposite();
        G = new List<Edge>[k];
        L = new List<Edge>[k];
        S = new List<int>[k];
        for (int i = 0; i < k; i++)
        {
            G[i] = new List<Edge>();
            L[i] = new List<Edge>();
            S[i] = new List<int>();
        }
        for (int i = 0; i < g.Length; i++)
        {
            var u = group[i];
            S[u].Add(i);
            foreach (var e in g[i])
            {
                var v = group[e.to];
                if (u == v)
                    L[u].Add(new Edge(u, v, e.cost));
                else G[u].Add(new Edge(u, v, e.cost));
            }
        }
    }
    public bool IsSameGroup(int u, int v)
    {
        return group[u] == group[v];
    }

}
#endregion
#region Edge
public struct Edge : IComparable<Edge>
{
    public int from, to, id;
    public long cost;
    public Edge(int f, int t) : this() { from = f; to = t; cost = 0; id = -1; }
    public Edge(int f, int t, long v) : this() { from = f; to = t; cost = v; id = -1; }
    public Edge(int f, int t, long v, int idx) : this() { from = f; to = t; cost = v; id = idx; }
    public override string ToString() { return string.Format("{0}->{1}:{2} id:{3}", from, to, cost, id); }
    public int CompareTo(Edge other)
    {
        var cmp = cost.CompareTo(other.cost);
        if (cmp != 0) return cmp;
        cmp = to.CompareTo(other.to);
        if (cmp != 0) return cmp;
        cmp = from.CompareTo(other.from);
        return id.CompareTo(other.id);
    }
}
#endregion