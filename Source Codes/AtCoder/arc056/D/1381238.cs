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
            var w = Enumerate(n, x => rl);
            const int T = 500050;
            var seg = new StarySkyTree(T);
            var Q = Enumerate(T, x => new List<int>());
            for (int i = 0; i < n; i++)
            {
                var m = ri;
                foreach (var x in sc.Integer(m))
                    Q[x / 2].Add(i);
            }
            //seg.Push(0, 1, w.Sum());
            const long X = 1000000000000000;
            seg.Push(0, 1, X);
            var max = 0L;
            var prev = Enumerate(n, x => -1);

            for (int t = 1; t < T; t++)
            {
                var ma = seg.Query(0, t) - X;
                max = Max(max, ma);
                seg.Push(t, t + 1, ma + X);
                //Debug.WriteLine(seg.Items.Take(t + 1).Select(x => x - X).AsJoinedString());
                foreach (var i in Q[t])
                {
                    var pre = prev[i];
                    seg.Push(pre + 1, t + 1, w[i]);
                    prev[i] = t;
                }
            }
            IO.Printer.Out.WriteLine(max);

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