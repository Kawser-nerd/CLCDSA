using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using Number = System.Int64;
using C = System.Int32;
//using static System.Math;
//using static MathEx;
//using P = System.Collections.Generic.KeyValuePair<int, int>;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var g = sc.Integer();
            var E = sc.Integer();
            var p = sc.Integer(g);
            var G = Enumerate(n + 1, x => new List<Edge>());
            for (int i = 0; i < E; i++)
            {
                var a = sc.Integer();
                var b = sc.Integer();
                G.AddUndirectedEdge(a, b, 1);

            }
            foreach (var q in p)
                G.AddDirectedEdge(q, n, 1);

            var cost = Flow.GetMaxFlow(G, 0, n);
            IO.Printer.Out.WriteLine(cost);
        }

        //*
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        char rc => sc.Char();

        [System.Diagnostics.Conditional("DEBUG")]
        void put(params object[] a) => Debug.WriteLine(string.Join(" ", a));

        //*/
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static void Swap<T>(ref T a, ref T b)
        {
            var tmp = a;
            a = b;
            b = tmp;
        }
    }
}

#region main

static class Ex
{
    public static string AsString(this IEnumerable<char> ie)
    {
        return new string(ie.ToArray());
    }

    public static string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ")
    {
        return string.Join(st, ie);
    }

    public static void Main()
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
        static Printer()
        {
            Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false };
        }

        public static Printer Out { get; set; }

        public override IFormatProvider FormatProvider
        {
            get { return CultureInfo.InvariantCulture; }
        }

        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true))
        {
        }

        public Printer(Stream stream, Encoding encoding) : base(stream, encoding)
        {
        }

        public void Write<T>(string format, T[] source)
        {
            base.Write(format, source.OfType<object>().ToArray());
        }

        public void WriteLine<T>(string format, T[] source)
        {
            base.WriteLine(format, source.OfType<object>().ToArray());
        }
    }

    public class StreamScanner
    {
        public StreamScanner(Stream stream)
        {
            str = stream;
        }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof;

        public bool IsEndOfStream
        {
            get { return isEof; }
        }

        private byte read()
        {
            if (isEof) return 0;
            if (ptr < len) return buf[ptr++];
            ptr = 0;
            if ((len = str.Read(buf, 0, 1024)) > 0) return buf[ptr++];
            isEof = true;
            return 0;
        }

        public char Char()
        {
            byte b;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }

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
            long ret = 0;
            byte b;
            var ng = false;
            do b = read(); while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-')
            {
                ng = true;
                b = read();
            }
            for (; ; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                ret = ret * 10 + b - '0';
            }
        }

        public int Integer()
        {
            return (isEof) ? int.MinValue : (int)Long();
        }

        public double Double()
        {
            var s = Scan();
            return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN;
        }

        static T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n)
        {
            return enumerate(n, Char);
        }

        public string[] Scan(int n)
        {
            return enumerate(n, Scan);
        }

        public double[] Double(int n)
        {
            return enumerate(n, Double);
        }

        public int[] Integer(int n)
        {
            return enumerate(n, Integer);
        }

        public long[] Long(int n)
        {
            return enumerate(n, Long);
        }
    }
}

#endregion
#region Edge
public class Edge
{
    public int to, rev;
    public C cap;
    public Edge(int t, int r, C _cap) { to = t; rev = r; cap = _cap; }
    public override string ToString() { return string.Format("{0}: Capacity {1}", to, cap); }
}
#endregion
#region AddEdge
static public partial class Flow
{
    static public void AddDirectedEdge(this List<Edge>[] G, int from, int to, C cap)
    {
        G[from].Add(new Edge(to, G[to].Count, cap));
        G[to].Add(new Edge(from, G[from].Count - 1, 0));
    }
    static public void AddUndirectedEdge(this List<Edge>[] G, int from, int to, int cap)
    {
        G[from].Add(new Edge(to, G[to].Count, cap));
        G[to].Add(new Edge(from, G[from].Count - 1, cap));
    }
}
#endregion


#region Dinic
static public partial class Flow
{
    static public C GetMaxFlow(List<Edge>[] G, int s, int t, C INF = -1)
    {
        var n = G.Length;
        var level = new int[n];
        var iter = new int[n];


        Action<int> bfs = otaku =>
        {
            Array.Clear(level, 0, n);
            var q = new Queue<int>();
            level[s] = 1;
            q.Enqueue(s);
            while (q.Count > 0)
            {
                var v = q.Dequeue();
                foreach (var e in G[v])
                    if (e.cap > 0 && level[e.to] == 0)
                    {
                        level[e.to] = level[v] + 1;
                        q.Enqueue(e.to);
                    }
            }
        };


        Func<int, int, C, C> dfs = null;
        dfs = (v, u, f) =>
        {
            if (v == t) return f;
            var ret = 0;
            for (; iter[v] < G[v].Count; iter[v]++)
            {
                var e = G[v][iter[v]];
                if (e.cap <= 0 || level[v] >= level[e.to]) continue;
                var d = dfs(e.to, u, Math.Min(f, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                ret += d; f -= d;
                if (f == 0) break;
            }
            return ret;
        };


        C flow = 0;
        if (INF == -1) INF = C.MaxValue;
        while (INF > 0)
        {
            bfs(s);
            if (level[t] == 0) return flow;
            Array.Clear(iter, 0, iter.Length);
            C f;
            while ((f = dfs(s, t, INF)) > 0) { flow += f; }
        }
        return flow;

    }
}
#endregion