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
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = ri;
            var a = Enumerate(n, x => ri - 1);
            var pos = new int[n];
            for (int i = 0; i < n; i++)
                pos[a[i]] = i;
            var s = Enumerate(2, x => new SortedSet<int>());
            var bit = new FenwickTree(n + 1);
            var seg = Enumerate(2, x => new RmQ(n + 5));

            for (int i = 0; i < n; i++)
            {
                s[i % 2].Add(a[i]);
                seg[i % 2].Update(i, a[i]);
            }

            var G = Enumerate(n, x => new List<int>());
            var next = new int[n];
            for (int i = 0; i < n; i++)
                next[i] = -1;
            Action<int, int, int> rec = null;
            rec = (l, r, u) =>
              {
                  if (r <= l) return;
                  var k = l % 2;
                  var min = (int)seg[k].Query(l, r);
                  var p = pos[min];
                  var mi = (int)seg[k ^ 1].Query(p + 1, r);
                  var q = pos[mi];

                  seg[k].Update(p, 1000000000);
                  seg[k ^ 1].Update(q, 1000000000);
                  if (u != -1)
                      G[u].Add(min);
                  next[min] = mi;
                  rec(l, p, min); rec(p + 1, q, min); rec(q + 1, r, min);
              };
            rec(0, n, -1);
            var ord = Graph.TopologicalSort(G, true);
            var ans = new List<int>();
            foreach (var x in ord)
            {
                if (next[x] == -1) continue;
                ans.Add(x + 1);
                ans.Add(next[x] + 1);
            }
            IO.Printer.Out.WriteLine(ans.AsJoinedString());
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
#region FenwickTree
public class FenwickTree
{
    int n;
    Number[] bit;
    int max = 1;
    public FenwickTree(int size)
    {
        n = size; bit = new Number[n + 1];
        while ((max << 1) <= n) max <<= 1;
    }
    /// <summary>sum[a,b]</summary>
    public Number this[int i, int j] { get { return this[j] - this[i - 1]; } }
    /// <summary>sum[0,i]</summary>
    public Number this[int i] { get { Number s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; } }
    public int LowerBound(Number w)
    {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = max; k > 0; k >>= 1)
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        return x + 1;
    }
    /// <summary>add v to bit[i]</summary>
    public void Add(int i, Number v)
    {
        if (i == 0) System.Diagnostics.Debug.Fail("BIT is 1 indexed");
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    public Number[] Items
    {
        get
        {
            var ret = new Number[n + 1];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = this[i, i];
            return ret;
        }
    }
}
#endregion


#region RmQ
public class RmQ: SegmentTree<long, MinData>
{
    public RmQ(int size) : base(size) { }
}
public struct MinData: IData<long>
{
    public long Identity { get { return long.MaxValue; } }
    public long Merge(long l, long r) { return Math.Min(l, r); }
}
#endregion

#region Segment Tree Node
public interface IData<T>
{
    T Merge(T l, T r);
    T Identity { get; }
}
#endregion
#region Segment Tree

public class SegmentTree<T, U>
   where U : struct, IData<T>
{
    int sz;
    int n;
    T[] data;
    U op;
    public SegmentTree(int size)
    {
        sz = size;
        n = 1;
        while (n < size) n *= 2;
        data = new T[n * 2];
        for (int i = 0; i < data.Length; i++)
            data[i] = op.Identity;
    }
    public SegmentTree(T[] a)
    {
        sz = a.Length;
        n = 1;
        while (n < sz) n *= 2;
        data = new T[n * 2];
        for (int i = 0; i < a.Length; i++)
            data[i + n] = a[i];
        for (int i = n - 1; i >= 0; i--)
            data[i] = op.Merge(data[i * 2], data[i * 2 + 1]);
    }
    public void Update(int k, T v)
    {
        k += n;
        data[k] = v;
        for (k = k / 2; k > 0; k /= 2)
        {
            data[k] = op.Merge(data[k * 2], data[k * 2 + 1]);
        }

    }
    public T Query(int a, int b) { return query(a, b, 1, 0, n); }
    private T query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return op.Identity;
        if (a <= l && r <= b)
            return data[k];
        else
        {
            var vl = query(a, b, k * 2, l, (l + r) / 2);
            var vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
            return op.Merge(vl, vr);
        }
    }
    public T[] Items
    {
        get
        {
            var ret = new T[sz];
            for (int i = 0; i < sz; i++)
                ret[i] = data[i + n];
            return ret;
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

#region TopologicalSort
static partial class Graph
{
    //???????????Queue?????
    //???????????count????????-1??????
    static public int[] TopologicalSort(List<int>[] G, bool isdirected, int[] count = null)
    {
        int Capacity = isdirected ? 0 : 1;//?????0?????1
        var n = G.Length;
        if (count == null)
        {
            count = new int[n];
            foreach (var l in G)
                foreach (var x in l) count[x]++;
        }
        var ret = new List<int>();
        var q = new PriorityQueue<int>();
        for (int i = 0; i < n; i++)
            if (count[i] == Capacity) q.Enqueue(i);
        while (q.Count > 0)
        {
            var p = q.Dequeue();
            ret.Add(p);
            foreach (var x in G[p])
                if (--count[x] == Capacity) q.Enqueue(x);
        }
        return ret.ToArray();
    }

}
#endregion