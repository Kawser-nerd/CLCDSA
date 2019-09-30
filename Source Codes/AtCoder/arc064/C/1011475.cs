using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int64;
using C = System.Int32;
using V = System.Int32;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var pp = new Point(sc.Integer(), sc.Integer());
            var qq = new Point(sc.Integer(), sc.Integer());
            var n = sc.Integer();
            var P = new Point[n + 2];
            P[n] = pp; P[n + 1] = qq;
            var R = new int[n + 2];
            for (int i = 0; i < n; i++)
            {
                P[i] = new Point(sc.Integer(), sc.Integer());
                R[i] = sc.Integer();
            }
            var dist = new double[n + 2];
            for (int i = 0; i < n + 2; i++)
                dist[i] = 1e18;
            dist[n] = 0;
            var pq = new BinaryHeapPriorityQueue<KeyValuePair<int, double>>((l, r) => l.Value.CompareTo(r.Value));
            pq.Enqueue(new KeyValuePair<C, double>(n, 0));
            var used = new bool[n + 2];
            foreach(var x in P)
                Debug.WriteLine(x);
            foreach(var x in R)
                Debug.WriteLine(x);
            while (pq.Count > 0)
            {
                var p = pq.Dequeue();
                if (used[p.Key]) continue;
                Debug.WriteLine(p);
                used[p.Key] = true;
                for (int i = 0; i < n + 2; i++)
                {
                    if (used[i]) continue;
                    var cost = get(P[i], P[p.Key], R[i] + R[p.Key]);
                    if (dist[i] > p.Value + cost)
                    {
                        dist[i] = p.Value + cost;
                        pq.Enqueue(new KeyValuePair<C, double>(i, dist[i]));
                    }
                }

            }

            IO.Printer.Out.WriteLine(dist[n + 1]);
        }
        double get(Point p, Point q, double dd)
        {
            return Math.Max(0, (p - q).Magnitude - dd);
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
#region PriorityQueue by BinaryHeap
public class BinaryHeapPriorityQueue<T>
{
    private readonly List<T> heap;
    private readonly Comparison<T> compare;
    private int size;
    public BinaryHeapPriorityQueue() : this(Comparer<T>.Default) { }
    public BinaryHeapPriorityQueue(IComparer<T> comparer) : this(16, comparer.Compare) { }
    public BinaryHeapPriorityQueue(Comparison<T> comparison) : this(16, comparison) { }
    public BinaryHeapPriorityQueue(int capacity, Comparison<T> comparison)
    {
        heap = new List<T>(capacity);
        compare = comparison;
    }
    public void Enqueue(T item)
    {

        heap.Add(item);
        var i = size++;
        while (i > 0)
        {
            var p = (i - 1) >> 1;
            if (compare(heap[p], item) <= 0)
                break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = item;

    }
    public T Dequeue()
    {
        var ret = heap[0];
        var x = heap[--size];
        var i = 0;
        while ((i << 1) + 1 < size)
        {
            var a = (i << 1) + 1;
            var b = (i << 1) + 2;
            if (b < size && compare(heap[b], heap[a]) < 0) a = b;
            if (compare(heap[a], x) >= 0)
                break;
            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        heap.RemoveAt(size);
        return ret;

    }
    public T Peek() { return heap[0]; }
    public int Count { get { return size; } }
    public bool Any() { return size > 0; }
}
#endregion