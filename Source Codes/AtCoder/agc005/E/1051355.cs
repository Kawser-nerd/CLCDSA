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
            var a = sc.Integer() - 1;
            var b = sc.Integer() - 1;
            var F = new int[n - 1];
            var T = new int[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                F[i] = sc.Integer() - 1;
                T[i] = sc.Integer() - 1;
            }
            var H = new HLTreeGraph(n);
            for (int i = 0; i < n - 1; i++)
                H.AddEdge(sc.Integer() - 1, sc.Integer() - 1);
            H.Build(b);
            var G = Enumerate(n, x => new List<int>());
            var win = new bool[n];
            for (int i = 0; i < n - 1; i++)
            {
                var f = F[i];
                var t = T[i];
                var d = H.Query(f, t);
                if (d >= 3) win[f] = win[t] = true;
                //else
                {
                    G[f].Add(t);
                    G[t].Add(f);
                }
            }
            var D = Enumerate(n, x => H.Query(b, x) * 2);
            var E = Enumerate(n, x => 1000000000);
            E[a] = 0;
            var q = new Queue<int>();
            q.Enqueue(a);
            while (q.Count > 0)
            {
                var p = q.Dequeue();
                if (win[p])
                {
                    IO.Printer.Out.WriteLine(-1);
                    return;
                }
                foreach (var to in G[p])
                {
                    var d = E[p] + 2;
                    if (D[to] > d && E[to] > d)
                    {
                        E[to] = d;
                        q.Enqueue(to);
                    }
                }
            }
            Debug.WriteLine(D.AsJoinedString());
            Debug.WriteLine(E.AsJoinedString());
            var max = 0L;
            for (int i = 0; i < n; i++)
                if (E[i] < 1000000) max = Math.Max(max, D[i]);
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
    public class Printer: StreamWriter
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
#region Edge
public struct Edge
{
    public int from, to;
    public Edge(int f, int t) : this() { from = f; to = t; }
}
#endregion

#region Stack<T>
public class FastStack<T>
{
    T[] data;
    int ptr;
    public FastStack(int size) { data = new T[size]; }
    public void Push(T item) { data[ptr++] = item; }
    public T Pop() { return data[--ptr]; }
    public T Peek() { return data[ptr - 1]; }
    public bool Any() { return ptr != 0; }
    public T Last { get { return data[ptr - 1]; } set { data[ptr - 1] = value; } }
    public int Count { get { return ptr; } }
}
#endregion
#region HLTreeGraph

public class HLTreeGraph
{
    /// <summary>
    /// ????????
    /// </summary>
    int N;
    /// <summary>
    /// ????????
    /// </summary>
    int M;
    /// <summary>
    /// ???????
    /// </summary>
    List<Edge>[] G;
    /// <summary>
    /// ???????
    /// </summary>
    List<Chain> H = new List<Chain>();

    int[] subTreeSize;
    int[] par;
    int[] pos;

    /// <summary>
    /// ???????
    /// </summary>
    public int[] d;


    /// <summary>
    ///u????????
    /// </summary>
    Chain[] go;
    public HLTreeGraph(int n)
    {
        N = n;
        G = Enumerate(n, x => new List<Edge>());
        subTreeSize = new int[n];
        pos = new int[n];
        d = new int[n];
        par = new int[n];
        go = new Chain[n];
    }
    public void AddEdge(int f, int t)
    {
        G[f].Add(new Edge(f, t));
        G[t].Add(new Edge(t, f));
    }
    #region impl
    public void Build(int root)
    {
        ComputeSubTreeSize(root);
        Decomposite(new Edge(-1, root), -1, 0);
        M = H.Count;
    }
    public void ComputeSubTreeSize(int root)
    {
        const long X = 1000000000;
        var stack = new FastStack<long>(N + 1);
        stack.Push(root * X);
        par[root] = -1;
        d[root] = 0;

        while (stack.Any())
        {
            var val = stack.Peek();
            var u = (int)(val / X);
            var it = (int)(val % X);

            if (it == G[u].Count)
            {
                stack.Pop();
                subTreeSize[u]++;
                if (par[u] >= 0) subTreeSize[par[u]] += subTreeSize[u];
            }
            else
            {
                var to = G[u][it].to;
                stack.Last++;
                if (to == par[u]) continue;

                par[to] = u;
                d[to] = d[u] + 1;
                stack.Push(to * X);
            }
        }

    }
    public void Decomposite(Edge light, int prevId, int lv)
    {
        var chain = new Chain() { light = light, id = H.Count, parId = prevId, level = lv };
        H.Add(chain);
        var prev = light.from;
        var cur = light.to;
        while (cur != prev)
        {
            var next = cur;
            var max = 0;
            go[cur] = chain;
            pos[cur] = chain.heavy.Count;
            foreach (var to in G[cur])
            {
                var t = to.to;
                if (t != prev) max = Math.Max(max, subTreeSize[t]);
            }
            foreach (var to in G[cur])
            {
                var t = to.to;
                if (t == prev) continue;
                if (max == subTreeSize[t])
                {
                    //Debug.WriteLine("{0}->{1}", cur, t);
                    max = 1 << 30;
                    next = t;
                    chain.heavy.Add(to);
                }
                else Decomposite(to, chain.id, lv + 1);
            }
            prev = cur;
            cur = next;
        }
        chain.init(this);

    }
    #endregion



    /// <summary>
    /// (u,v)????????????
    /// </summary>
    public long Query(int u, int v)
    {
        long ans = 0;
        ans += d[u];
        ans += d[v];
        while (go[u].id != go[v].id)
        {
            if (go[u].level > go[v].level)
                u = go[u].light.from;
            else
                v = go[v].light.from;
        }
        if (pos[u] < pos[v])
            ans += -2 * d[u];
        else ans += -2 * d[v];

        return ans;
    }

    static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }

}
public class Chain
{
    /// <summary>
    /// light edge
    /// </summary>
    public Edge light;
    /// <summary>
    /// heavy edge???
    /// </summary>
    public List<Edge> heavy = new List<Edge>();
    /// <summary>
    /// ?????????
    /// </summary>
    public int parId;
    /// <summary>
    /// ?????????
    /// </summary>
    public int level;
    public int id;
    //public RangeAddFenwickTree seg;
    public void init(HLTreeGraph G)
    {
        //seg = new RangeAddFenwickTree(heavy.Count + 2);
    }
    public override string ToString()
    {
        var s = new List<int>();
        s.Add(light.from);
        s.Add(light.to);
        foreach (var e in heavy)
            s.Add(e.to);
        return string.Join("->", s);
    }
}
#endregion