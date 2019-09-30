using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using Number = System.Int64;
using static System.Math;
//using static MathEx;
//using P = System.Collections.Generic.KeyValuePair<int, int>;

using C = System.Int32;
using V = System.Int32;

namespace Program
{
    public class Solver
    {


        public void Solve()
        {
            var rand = new Random(0);
            for (int _ = 0; _ < 1; _++)
            {

                var n = ri;
                var m = ri;
                //var n = rand.Next(50, 100);
                //var m = rand.Next(50, 100);
                var A = Enumerate(m + 5, x => new List<int>());
                var stary = new StarySkyTree(m);
                stary.Push(0, m, 500000);
                for (int i = 0; i < m; i++)
                    stary.Push(i, m, -1);
                var L = new int[n];
                var R = new int[n];
                for (int i = 0; i < n; i++)
                {
                    var l = ri;
                    var r = ri;
                    //var l = rand.Next(0, 40);
                    //var r = rand.Next(m - 40, m + 2);
                    L[i] = l;
                    R[i] = r;
                }
                for (int i = 0; i < n; i++)
                {

                    var l = L[i];
                    var r = R[i];
                    A[l].Add(r);
                    stary.Push(m - r, m, 1);
                }
                var cnt = 0;
                var pqL = new PriorityQueue<int>();
                long min = 1000000000;
                var dame = 0;
                for (int i = 0; i <= m; i++, cnt++)
                {
                    //Debug.WriteLine(stary.Items.Select(x => x - 500000).AsJoinedString());
                    foreach (var x in A[i])
                    {
                        pqL.Enqueue(x);
                        stary.Push(m - x, m, -1);
                    }
                    while (pqL.Count > cnt)
                    {
                        var p = pqL.Dequeue();
                        if (p == m + 1)
                            dame++;
                        else stary.Push(m - p, m, 1);
                    }
                    var max = Max(0, stary.Query(0, m) - 500000) + dame;
                    min = Min(min, max);

                }
                if (min < n - m) min = n - m;
                IO.Printer.Out.WriteLine(min);
                //var res = debug(L, R, m);
                //Debug.WriteLine(res);
                //if (min != res)
                {

                }
            }
        }
        public int debug(int[] L, int[] R, int m)
        {
            var n = L.Length;
            var src = n + m + 8;
            var sink = n + m + 9;
            var G = new MinCostFlow(n + m + 10);
            for (int i = 1; i <= m; i++)
                G.AddDirectedEdge(n + i, sink, 1, 0);
            for (int i = 0; i < n; i++)
            {
                G.AddDirectedEdge(src, i, 1, 0);
                for (int j = 1; j <= L[i]; j++)
                    G.AddDirectedEdge(i, n + j, 1, 0);
                for (int j = R[i]; j <= m; j++)
                    G.AddDirectedEdge(i, n + j, 1, 0);
                G.AddDirectedEdge(i, sink, 1, 1);

            }
            var cost = G.Execute(src, sink);

            return cost.Value;
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



#region BinaryHeap
public class PriorityQueue<T>
{
    readonly List<T> heap = new List<T>();
    readonly IComparer<T> cmp;
    public PriorityQueue() { cmp = Comparer<T>.Default; }
    public PriorityQueue(Comparison<T> f) { cmp = Comparer<T>.Create(f); }
    public PriorityQueue(IComparer<T> c) { cmp = c; }
    public void Enqueue(T item)
    {

        var i = heap.Count;
        heap.Add(item);
        while (i > 0)
        {
            var p = (i - 1) / 2;
            if (cmp.Compare(heap[p], item) <= 0)
                break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = item;

    }
    public T Dequeue()
    {
        var ret = heap[0];
        var i = 0;
        var x = heap[heap.Count - 1];

        while ((i * 2) + 1 < heap.Count - 1)
        {
            var a = i * 2 + 1;
            var b = i * 2 + 2;
            if (b < heap.Count - 1 && cmp.Compare(heap[b], heap[a]) < 0) a = b;
            if (cmp.Compare(heap[a], x) >= 0)
                break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        heap.RemoveAt(heap.Count - 1);
        return ret;

    }
    public T Peek() { return heap[0]; }
    public int Count { get { return heap.Count; } }
    public bool Any() { return heap.Count > 0; }
    public T[] Items
    {
        get
        {
            var ret = heap.ToArray();
            Array.Sort(ret, cmp);
            return ret;
        }
    }
}
#endregion
#region Lazy Propagation
public interface ILazyData<T1, T2>
{
    T1 Merge(T1 l, T1 r);
    T1 Identity { get; }
    T1 Apply(int l, int r, T1 val, T2 x);
    T2 Push(T2 val, T2 x);
    T2 Zero { get; }
}
#endregion
#region LazyPropagation Segment Tree
public class LazyPropagationSegmentTree<T1, T2, U>
    where U : struct, ILazyData<T1, T2>
{
    int sz;
    int n;
    T1[] data;
    T2[] lazy;
    bool[] flag;
    U op;
    public LazyPropagationSegmentTree(int size)
    {
        sz = size;
        n = 1;
        while (n < sz)
            n <<= 1;
        data = new T1[n * 2];
        lazy = new T2[n * 2];
        flag = new bool[n * 2];
        for (int i = 1; i < n * 2; i++)
        {
            data[i] = op.Identity;
            lazy[i] = op.Zero;
        }
    }
    public LazyPropagationSegmentTree(T1[] a)
    {

        sz = a.Length;
        n = 1;
        while (n < sz)
            n <<= 1;
        data = new T1[n * 2];
        lazy = new T2[n * 2];
        flag = new bool[n * 2];
        for (int i = 0; i < n; i++)
        {
            if (i < sz)
                data[i + n] = a[i];
            else data[i + n] = op.Identity;
            lazy[i + n] = op.Zero;
        }
        for (int i = n - 1; i >= 1; i--)
        {
            data[i] = op.Merge(data[i * 2], data[i * 2 + 1]);
            lazy[i] = op.Zero;

        }
    }
    private void lazyEval(int k, int a, int b)
    {
        if (!flag[k])
            return;
        push(a, (a + b) / 2, lazy[k], k * 2, a, (a + b) / 2);
        push((a + b) / 2, b, lazy[k], k * 2 + 1, (a + b) / 2, b);
        lazy[k] = op.Zero;
        flag[k] = false;
    }
    private void eval(int k)
    {
        data[k] = op.Merge(data[k * 2], data[k * 2 + 1]);
    }

    public void Push(int a, int b, T2 v)
    {
        push(a, b, v, 1, 0, n);
    }
    private void push(int a, int b, T2 x, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return;
        else if (a <= l && r <= b)
        {
            flag[k] = true;
            lazy[k] = op.Push(lazy[k], x);
            data[k] = op.Apply(l, r, data[k], x);
        }
        else
        {
            lazyEval(k, l, r);
            push(a, b, x, k << 1, l, (l + r) >> 1);
            push(a, b, x, (k << 1) + 1, (l + r) >> 1, r);
            eval(k);
        }
    }
    public T1 Query(int a, int b) { return query(a, b, 1, 0, n); }
    private T1 query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return op.Identity;
        if (a <= l && r <= b)
            return data[k];
        else
        {
            lazyEval(k, l, r);
            var vl = query(a, b, k << 1, l, (l + r) >> 1);
            var vr = query(a, b, (k << 1) + 1, (l + r) >> 1, r);
            eval(k);
            return op.Merge(vl, vr);
        }
    }
    public T1[] Items
    {
        get
        {
            var ret = new T1[sz];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = Query(i, i + 1);
            return ret;
        }
    }
}
#endregion

#region StarySkyTree
public class StarySkyTree: LazyPropagationSegmentTree<long, long, StarySky>
{
    public StarySkyTree(int size) : base(size) { }
}
public struct StarySky: ILazyData<long, long>
{
    public long Identity { get { return 0; } }
    public long Zero { get { return 0; } }
    public long Apply(int l, int r, long val, long x) { return val + x; }
    public long Merge(long l, long r) { return Math.Max(l, r); }
    public long Push(long val, long x) { return val + x; }
}
#endregion

/// <summary>
/// ?????????????????????????????
/// </summary>
public class MinCostFlow
{
    bool hasng;
    readonly List<Edge>[] G;
    /// <summary>
    /// ??? <paramref name="V"/> ??????????????????
    /// </summary>
    /// <param name="V">????</param>
    /// <remarks>????? O(<paramref name="V"/>) ????????</remarks>
    public MinCostFlow(int V)
    {
        G = new List<Edge>[V];
        for (int i = 0; i < V; i++)
            G[i] = new List<Edge>();

    }
    /// <summary>
    /// ?? <paramref name="from"/> ???? <paramref name="to"/> ???? <paramref name="cap"/> ???? <paramref name="cost"/> ???????????
    /// </summary>
    /// <param name="from">???????? 0-indexed ????</param>
    /// <param name="to">???????? 0-indexed ????</param>
    /// <param name="cap">????</param>
    /// <param name="cost">?????</param>
    /// <remarks>????? O(1) ????????</remarks>
    public void AddDirectedEdge(int from, int to, C cap, V cost)
    {
        addEdge(from, to, cap, 0, cost);
    }

    /// <summary>
    /// ?? <paramref name="src"/> ???? <paramref name="sink"/> ?????? <paramref name="f"/> ???????????????
    /// </summary>
    /// <param name="src">????????? 0-indexed ????</param>
    /// <param name="sink">????????? 0-indexed ????</param>
    /// <param name="f">??????????????????-1????????????????????</param>
    /// <param name="inf">?????????????????</param>
    /// <remarks>?????Primal Dual??????????? O(VE + FE log V) ????????V??????E?????F?????????</remarks>
    public KeyValuePair<C, V> Execute(int src, int sink, C f = C.MaxValue, V inf = 1000)
    {
        var n = G.Length;
        var dist = new V[n];
        var prev = new int[n];
        var prevEdge = new Edge[n];
        var potential = new V[n];


        C flow = 0;
        V cost = 0;
        var first = hasng;
        while (f > 0)
        {
            for (int i = 0; i < G.Length; i++)
                dist[i] = inf;

            //shortest path
            if (first)//spfa
            {
                var q = new Queue<int>();
                q.Enqueue(src); dist[src] = 0;
                var inQ = new bool[n];
                while (q.Count > 0)
                {
                    var p = q.Dequeue();
                    inQ[p] = false;
                    foreach (var e in G[p])
                    {
                        var t = e.To;
                        var d = dist[p] + e.Cost;
                        if (e.Cap > 0 && d < dist[t])
                        {
                            if (!inQ[t])
                            {
                                inQ[t] = true;
                                q.Enqueue(t);
                            }
                            dist[t] = d; prev[t] = p; prevEdge[t] = e;
                        }
                    }
                }
                first = false;
            }
            else//dijkstra
            {
                var vis = new bool[n];
                var pq = new PriorityQueue<KeyValuePair<int, V>>((l, r) => l.Value.CompareTo(r.Value));
                pq.Enqueue(new KeyValuePair<int, V>(src, 0));
                dist[src] = 0;
                while (pq.Count > 0)
                {
                    var p = pq.Dequeue().Key;
                    if (vis[p]) continue;
                    vis[p] = true;
                    foreach (var e in G[p])
                    {
                        if (e.Cap <= 0) continue;
                        var t = e.To;
                        if (vis[t]) continue;
                        var d = dist[p] + e.Cost + potential[p] - potential[t];
                        if (dist[t] > d)
                        {
                            dist[t] = d; prev[t] = p; prevEdge[t] = e;
                            pq.Enqueue(new KeyValuePair<int, V>(t, d));
                        }
                    }
                }


            }


            //update
            {
                if (dist[sink] == inf) break;
                for (int i = 0; i < n; i++)
                    potential[i] += dist[i];
                C df = f;
                V d = 0;
                for (var v = sink; v != src; v = prev[v])
                {
                    var e = prevEdge[v];
                    df = Math.Min(df, e.Cap); d += e.Cost;
                }
                f -= df; cost += df * d; flow += df;
                for (var v = sink; v != src; v = prev[v])
                {
                    var e = prevEdge[v];
                    e.Cap -= df; e.Rev.Cap += df;
                }
            }

        }
        return new KeyValuePair<C, V>(flow, cost);
    }
    void addEdge(int f, int t, C c1, C c2, V e)
    {
        if (e < 0) hasng = true;
        var a = new Edge(t, c1, e);
        var b = new Edge(f, c2, -e);
        Edge.Link(a, b);
        G[f].Add(a);
        G[t].Add(b);
    }
    class Edge
    {
        public static void Link(Edge e1, Edge e2)
        {
            e1.Rev = e2; e2.Rev = e1;
        }
        public int To { get; private set; }
        public Edge Rev { get; private set; }
        public V Cost { get; private set; }
        public C Cap { get; set; }
        public Edge(int t, C c, V e)
        {
            To = t;
            Cap = c;
            Cost = e;
        }
        public override string ToString()
        {
            return string.Format("to: {0}, cap: {1}", To, Cap);
        }
    }
}