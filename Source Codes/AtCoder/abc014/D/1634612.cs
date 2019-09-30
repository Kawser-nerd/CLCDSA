using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = ri;
            var G = new HLTree(n);
            for (int i = 0; i < n - 1; i++)
                G.AddEdge(ri - 1, ri - 1);
            G.Build();
            var q = ri;
            for (int i = 0; i < q; i++)
            {
                var u = ri - 1;
                var v = ri - 1;
                var lca = G.GetLCA(u, v);
                Debug.WriteLine(lca);
                Console.WriteLine(G.d[u] + G.d[v] - 2 * G.d[lca] + 1);
            }
        }
        const long INF = 1L << 60;
        //int[] dx = { -1, 0, 1, 0 };
        //int[] dy = { 0, 1, 0, -1 };
        //*
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        //*/

        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex
{
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ")
    {
        return string.Join(st, ie.Select(x => x.ToString()).ToArray());
        //return string.Join(st, ie);
    }
    static public void Main()
    {
        Console.SetOut(new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
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
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
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
            for (var b = Char(); b != '\n' && b != 0; b = (char)read())
                if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}
#endregion
public class HLTree
{
    int n;
    List<int>[] G;
    int[] subtreeSize;
    int[] maxsize;
    int[] par;
    public int[] d;

    Chain[] go;
    int[] pos;
    List<Chain> chains;
    public HLTree(int N)
    {
        n = N;
        G = new List<int>[n];
        chains = new List<Chain>();
        for (int i = 0; i < n; i++)
            G[i] = new List<int>();
        subtreeSize = new int[n];
        maxsize = new int[n];
        par = new int[n];
        d = new int[n];
        go = new Chain[n];
        pos = new int[n];
    }
    public void AddEdge(int u, int v)
    {
        G[u].Add(v); G[v].Add(u);
    }
    public void Build(int root = 0)
    {
        computeSubtreeSize(root);
        Decomposite(-1, root, 0);

    }
    void computeSubtreeSize(int r)
    {
        var stack = new Stack<int>();
        stack.Push(r);
        var iter = new int[n];
        par[r] = -1;
        //dfs
        while (stack.Count > 0)
        {
            var cur = stack.Peek();
            if (iter[cur] == G[cur].Count)
            {
                stack.Pop();
                subtreeSize[cur]++;
                if (par[cur] != -1)
                {
                    subtreeSize[par[cur]] += subtreeSize[cur];
                    maxsize[par[cur]] = Math.Max(maxsize[par[cur]], subtreeSize[cur]);
                }
                continue;
            }
            var next = G[cur][iter[cur]++];
            if (next == par[cur]) continue;
            par[next] = cur;
            d[next] = d[cur] + 1;
            stack.Push(next);
        }

    }
    void Decomposite(int from, int cur, int lv)
    {
        var chain = new Chain(from, lv);
        chains.Add(chain);
        chain.Add(cur);
        while (cur != from)
        {
            var next = cur;
            go[cur] = chain;
            pos[cur] = chain.Count;
            foreach (var to in G[cur])
            {
                if (to == from) continue;
                if (maxsize[cur] == subtreeSize[to])
                {
                    maxsize[cur] = -1;
                    next = to;
                    chain.Add(to);
                }
                else Decomposite(cur, to, lv + 1);
            }

            from = cur;
            cur = next;

        }
        chain.Init();

    }
    public int GetLCA(int u, int v)
    {
        while (go[u] != go[v])
        {
            if (go[u].Level < go[v].Level) v = go[v].From;
            else u = go[u].From;
        }
        if (d[u] <= d[v]) return u;
        else return v;
    }


}
public class Chain
{
    const bool DEBUG = true;
    public int From { get; set; }
    public int Level { get; set; }
    public int Count { get; private set; }
    List<int> heavy;
    public Chain(int from, int lv)
    {
        From = from;
        Level = lv;
        heavy = new List<int>();
    }
    public void Add(int v)
    {
        if (DEBUG)
            heavy.Add(v);
        Count++;
    }
    public void Init()
    {

    }
}