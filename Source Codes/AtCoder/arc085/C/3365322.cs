using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Point = System.Numerics.Complex;
using Number = System.Int64;
using C = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var a = Enumerate(n, x => rl);
            var mf = new MaxFlow(2 * n + 2);
            var src = 2 * n;
            var sink = src + 1;
            var ans = 0L;
            for (int i = 1; i <= n; i++)
            {
                var v = a[i - 1];
                if (v < 0)
                {
                    //???????
                    mf.AddDirectedEdge(n + i - 1, sink, -v);
                }
                else
                {
                    ans += v;
                    //?????
                    mf.AddDirectedEdge(src, i - 1, v);
                }
                mf.AddDirectedEdge(i - 1, i + n - 1, INF);
                for (int j = 2 * i; j <= n; j += i)
                {
                    // j ??????i ?????????
                    mf.AddDirectedEdge(j - 1, i - 1 + n, INF);
                }
            }
            var val = mf.Execute(src, sink);
            Debug.WriteLine(val);
            Console.WriteLine(ans - val);
        }

        const long INF = 1L << 60;
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex {
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
        return string.Join(st, ie);
    }
    static public void Main() {
        Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer: StreamWriter {
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }

        private byte read() {
            if (isEof) return 0;
            if (ptr >= len)
            {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0)
                {
                    isEof = true;
                    return 0;
                }
            }
            return buf[ptr++];
        }

        public char Char() {
            byte b = 0;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan() {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine() {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}

#endregion

#region Max Flow
/// <summary>
/// ???????????????????????????
/// </summary>
public class MaxFlow {
    readonly List<Edge>[] G;
    readonly int[] lv, iter;
    /// <summary>
    /// ??? <paramref name="V"/> ??????????????????
    /// </summary>
    /// <param name="V">????</param>
    /// <remarks>????? O(<paramref name="V"/>) ????????</remarks>
    public MaxFlow(int V) {
        G = new List<Edge>[V];
        lv = new int[V];
        iter = new int[V];
        for (int i = 0; i < G.Length; i++)
            G[i] = new List<Edge>();
    }

    /// <summary>
    /// ?? <paramref name="from"/> ???? <paramref name="to"/> ???? <paramref name="cap"/> ???????????
    /// </summary>
    /// <param name="from">???????? 0-indexed ????</param>
    /// <param name="to">???????? 0-indexed ????</param>
    /// <param name="cap">????</param>
    /// <remarks>????? O(1) ????????</remarks>
    public void AddDirectedEdge(int from, int to, C cap) {
        addEdge(from, to, cap, 0);
    }

    /// <summary>
    /// ?? <paramref name="from"/> ???? <paramref name="to"/> ???? <paramref name="cap"/> ???????????
    /// </summary>
    /// <param name="from">???????? 0-indexed ????</param>
    /// <param name="to">???????? 0-indexed ????</param>
    /// <param name="cap">????</param>
    /// <remarks>????? O(1) ????????</remarks>
    public void AddUndirectedEdge(int from, int to, C cap) {
        addEdge(from, to, cap, cap);
    }
    void addEdge(int f, int t, C c1, C c2) {
        var a = new Edge(t, c1);
        var b = new Edge(f, c2);
        Edge.Link(a, b);
        G[f].Add(a);
        G[t].Add(b);
    }


    /// <summary>
    /// ?? <paramref name="src"/> ???? <paramref name="sink"/> ?????? <paramref name="f"/> ???????????
    /// </summary>
    /// <param name="src">????????? 0-indexed ????</param>
    /// <param name="sink">????????? 0-indexed ????</param>
    /// <param name="f">??????????????????-1????????????????</param>
    /// <remarks>?????Dinic??????????? O(EV^2) ????????V??????E??????????</remarks>
    public C Execute(int src, int sink, C f = -1) {
        C flow = 0;
        if (f < 0) f = C.MaxValue;
        while (f > 0)
        {
            bfs(src);
            if (lv[sink] == 0) return flow;
            Array.Clear(iter, 0, iter.Length);
            C df;
            while ((df = dfs(src, sink, f)) > 0) { flow += df; f -= df; }
        }
        return flow;
    }

    void bfs(int s) {
        Array.Clear(lv, 0, lv.Length);
        var q = new Queue<int>();
        lv[s] = 1;
        q.Enqueue(s);
        while (q.Count > 0)
        {
            var v = q.Dequeue();
            foreach (var e in G[v])
                if (e.Cap > 0 && lv[e.To] == 0)
                {
                    lv[e.To] = lv[v] + 1;
                    q.Enqueue(e.To);
                }
        }

    }
    C dfs(int v, int t, C f) {
        if (v == t) return f;
        C ret = 0;
        for (; iter[v] < G[v].Count; iter[v]++)
        {
            var e = G[v][iter[v]];
            if (e.Cap <= 0 || lv[v] >= lv[e.To]) continue;
            C df = dfs(e.To, t, Math.Min(f, e.Cap));
            if (df <= 0) continue;
            e.Cap -= df;
            e.Rev.Cap += df;
            ret += df; f -= df;
            if (f == 0) break;
        }
        return ret;

    }
    class Edge {
        public static void Link(Edge e1, Edge e2) {
            e1.Rev = e2; e2.Rev = e1;
        }
        public int To { get; private set; }
        public Edge Rev { get; private set; }
        public C Cap { get; set; }
        public Edge(int t, C c) {
            To = t;
            Cap = c;
        }
        public override string ToString() {
            return string.Format("to: {0}, cap: {1}", To, Cap);
        }
    }


}
#endregion