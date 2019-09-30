using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Double;
using _ANSWER = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var T = sc.Integer();
            var ans = new _ANSWER[T];
            var f = new Func<_ANSWER>[T];
            for (int _ = 0; _ < T; _++)
            {
                var n = sc.Integer();
                var s = new string[n];
                var t = new string[n];
                for (int i = 0; i < n; i++)
                {
                    s[i] = sc.Scan();
                    t[i] = sc.Scan();
                }
                f[_] = () => solve(n, s, t);
                ans[_] = f[_]();
            }
            //System.Threading.Tasks.Parallel.For(0, T, i => ans[i] = f[i]());
            for (int i = 0; i < T; i++)
            {
                IO.Printer.Out.WriteLine($"Case #{i + 1}: {ans[i]}");
            }
        }
        private _ANSWER solve(int n, string[] s, string[] t)
        {
            var F = s.Distinct().ToList();
            var T = t.Distinct().ToList();
            F.Sort(); T.Sort();
            var from = new int[n];
            var to = new int[n];
            for (int i = 0; i < n; i++)
            {
                from[i] = F.BinarySearch(s[i]);
                to[i] = T.BinarySearch(t[i]);
            }
            var a = F.Count;
            var b = T.Count;
            var l = a;
            var r = n + 1000;
            var G = Enumerate(a + b + 2, x => new List<Edge<int, int>>());
            for (int i = 0; i < n; i++)
            {
                G.AddDirectedEdge(from[i], to[i] + a, 100000, 0);
            }
            var start = a + b;
            var goal = a + b + 1;
            for (int i = 0; i < a; i++)
            {
                G.AddDirectedEdge(start, i, 1, 0);
                G.AddDirectedEdge(start, i, 100000, 100000);
            }
            for (int i = 0; i < b; i++)
            {
                G.AddDirectedEdge(a + i, goal, 1, 0);
                G.AddDirectedEdge(a + i, goal, 100000, 100000);
            }
            var f = Flow.PrimalDual(G, start, goal, 100000);
            return n - f.y;
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
#region CostEdge
static public class Edge
{
    static public Edge<C, V> Create<C, V>(int t, int r, C _cap, V _cost) { return new Edge<C, V>(t, r, _cap, _cost); }
}
public class Edge<C, V>
{
    public int to, rev;
    public C cap;
    public V cost;
    public Edge(int t, int r, C _cap, V _cost) { to = t; rev = r; cap = _cap; cost = _cost; }
    public override string ToString() { return string.Format("{0}: Capacity {1}, Cost{2}", to, cap, cost); }
}
#endregion

#region AddCostEdge
static public partial class Flow
{
    static public void AddDirectedEdge(this List<Edge<int, int>>[] G, int from, int to, int cap, int cost)
    {
        G[from].Add(Edge.Create(to, G[to].Count, cap, cost));
        G[to].Add(Edge.Create(from, G[from].Count - 1, 0, -cost));
    }
    static public void AddDirectedEdge(this List<Edge<int, double>>[] G, int from, int to, int cap, double cost)
    {
        G[from].Add(Edge.Create(to, G[to].Count, cap, cost));
        G[to].Add(Edge.Create(from, G[from].Count - 1, 0, -cost));
    }

}
#endregion
#region Integer MinCostFlow
static public partial class Flow
{
    /// <summary>
    /// 最小費用流をprimal-dual法でやる
    /// </summary>
    /// <param name="G">グラフ</param>
    /// <param name="s">始点</param>
    /// <param name="t">終点</param>
    /// <param name="f">流す最大流量</param>
    /// <param name="INF">適当な最大値</param>
    /// <returns></returns>
    static public Pair<int, int> PrimalDual(List<Edge<int, int>>[] G, int s, int t, int f, int INF = 1 << 20)
    {
        var n = G.Length;
        var dist = new int[n];
        var prev = new int[n];
        var prevEdge = new int[n];
        var total = new Pair<int, int>(0, 0);
        var potential = new int[n];
        while (f > 0)
        {
            for (int i = 0; i < n; i++)
                dist[i] = INF;
            //shortest path
            if (total.y == 0)
            {
                var q = new Queue<int>();
                q.Enqueue(s); dist[s] = 0;
                var inQ = new bool[n];
                while (q.Any())
                {
                    var p = q.Dequeue();
                    inQ[p] = false;
                    for (int i = 0; i < G[p].Count; i++)
                    {
                        var e = G[p][i];
                        var j = e.to;
                        var d = dist[p] + e.cost;
                        if (e.cap > 0 && d < dist[j])
                        {
                            if (!inQ[j])
                            {
                                inQ[j] = true;
                                q.Enqueue(j);
                            }
                            dist[j] = d; prev[j] = p; prevEdge[j] = i;
                        }
                    }
                }
            }
            else
            {
                var vis = new bool[n];
                var pq = new PriorityQueue<Pair<int, int>>();
                pq.Enqueue(new Pair<int, int>(0, s));
                dist[s] = 0;
                while (pq.Any())
                {
                    var p = pq.Dequeue().y;
                    if (vis[p]) continue;
                    vis[p] = true;
                    for (int i = 0; i < G[p].Count; i++)
                    {
                        var e = G[p][i];
                        if (e.cap <= 0) continue;
                        var j = e.to;
                        var d = dist[p] + e.cost + potential[p] - potential[j];
                        if (dist[j] > d)
                        {
                            dist[j] = d; prev[j] = p; prevEdge[j] = i;
                            pq.Enqueue(new Pair<int, int>(d, j));
                        }
                    }
                }


            }


            //update
            {
                if (dist[t] == INF) break;
                for (int i = 0; i < n; i++)
                    potential[i] += dist[i];
                var d = f; var distt = 0;
                for (var v = t; v != s;)
                {
                    var u = prev[v]; var e = G[u][prevEdge[v]];
                    d = Math.Min(d, e.cap); distt += e.cost; v = u;
                }
                if (distt == 200000) return total;
                f -= d; total.x += d * distt; total.y += d;
                for (var v = t; v != s; v = prev[v])
                {
                    var e = G[prev[v]][prevEdge[v]];
                    e.cap -= d; G[e.to][e.rev].cap += d;
                }
            }

        }
        return total;
    }
}
#endregion
#region Compair
static public class Pair
{
    static public Pair<FT, ST> Create<FT, ST>(FT f, ST s)
        where FT : IComparable<FT>
        where ST : IComparable<ST>
    { return new Pair<FT, ST>(f, s); }
    static public Pair<FT, ST> Min<FT, ST>(Pair<FT, ST> p, Pair<FT, ST> q)
        where FT : IComparable<FT>
        where ST : IComparable<ST>
    { return (p.CompareTo(q) <= 0) ? p : q; }
    static public Pair<FT, ST> Max<FT, ST>(Pair<FT, ST> p, Pair<FT, ST> q)
        where FT : IComparable<FT>
        where ST : IComparable<ST>
    { return (p.CompareTo(q) >= 0) ? p : q; }
}
public struct Pair<FT, ST> : IComparable<Pair<FT, ST>>
    where FT : IComparable<FT>
    where ST : IComparable<ST>
{
    public FT x;
    public ST y;
    public Pair(FT f, ST s) : this() { x = f; y = s; }

    public int CompareTo(Pair<FT, ST> other)
    {
        var cmp = x.CompareTo(other.x);
        return cmp != 0 ? cmp : y.CompareTo(other.y);
    }
    public override string ToString() { return string.Format("{0} {1}", x, y); }
}
#endregion
#region PriorityQueue and PairingHeap
public class PriorityQueue<T>
{
    PairingHeap<T> top;
    Comparison<T> compare;
    int size;
    public int Count { get { return size; } }
    public PriorityQueue() : this(Comparer<T>.Default) { }
    public PriorityQueue(Comparison<T> comparison) { compare = comparison; }
    public PriorityQueue(IComparer<T> comparer) { compare = comparer.Compare; }
    public void Enqueue(T item)
    {
        var heap = new PairingHeap<T>(item);
        top = PairingHeap<T>.Merge(top, heap, compare);
        size++;
    }
    public T Dequeue()
    {
        var ret = top.Key;
        size--;
        top = PairingHeap<T>.Pop(top, compare);
        return ret;
    }
    public bool Any() { return size > 0; }
    public T Peek() { return top.Key; }
}

#region PairingHeap
public class PairingHeap<T>
{
    public PairingHeap(T k) { key = k; }
    private readonly T key;
    public T Key { get { return key; } }
    private PairingHeap<T> head;
    private PairingHeap<T> next;
    static public PairingHeap<T> Pop(PairingHeap<T> s, Comparison<T> compare)
    {
        return MergeLst(s.head, compare);
    }
    static public PairingHeap<T> Merge(PairingHeap<T> l, PairingHeap<T> r, Comparison<T> compare)
    {
        if (l == null || r == null) return l == null ? r : l;
        if (compare(l.key, r.key) > 0) Swap(ref l, ref r);
        r.next = l.head;
        l.head = r;
        return l;
    }
    static public PairingHeap<T> MergeLst(PairingHeap<T> s, Comparison<T> compare)
    {
        var n = new PairingHeap<T>(default(T));
        while (s != null)
        {
            PairingHeap<T> a = s, b = null;
            s = s.next; a.next = null;
            if (s != null) { b = s; s = s.next; b.next = null; }
            a = Merge(a, b, compare); a.next = n.next;
            n.next = a;
        }
        while (n.next != null)
        {
            var j = n.next;
            n.next = n.next.next;
            s = Merge(j, s, compare);
        }
        return s;
    }
    static void Swap(ref PairingHeap<T> l, ref PairingHeap<T> r) { var t = l; l = r; r = t; }
}
#endregion
#endregion