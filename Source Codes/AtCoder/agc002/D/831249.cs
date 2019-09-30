using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {

            var n = sc.Integer();
            var m = sc.Integer();
            var set = new LimitedPersistentDisjointSet(n);
            for (int i = 0; i < m; i++)
            {
                set.Unite(sc.Integer() - 1, sc.Integer() - 1);
            }
            var q = sc.Integer();
            for (int i = 0; i < q; i++)
            {
                var u = sc.Integer() - 1;
                var v = sc.Integer() - 1;
                var c = sc.Integer();
                var l = 0; var r = m;
                while (l + 1 < r)
                {
                    var lr = (l + r) / 2;
                    var a = 0;
                    var x = set.Get(lr, u);
                    var y = set.Get(lr, v);
                    if (x.Key == y.Key)
                        a += x.Value;
                    else
                    {
                        a += x.Value;
                        a += y.Value;
                    }
                    if (a >= c) r = lr;
                    else l = lr;
                }
                IO.Printer.Out.WriteLine(r);
            }
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

#region Limited Persistent data structure
/// <summary>
/// ???????????disjoint set
/// </summary>
public class LimitedPersistentDisjointSet
{
    int n;
    FastList<pair>[] history;
    byte[] rank;
    int[] par;
    int last = 0;
    public LimitedPersistentDisjointSet(int N)
    {
        n = N;
        history = new FastList<pair>[n];
        rank = new byte[n];
        par = new int[n];
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            history[i] = new FastList<pair>(); history[i].Add(new pair(0, -1));
        }
    }
    /// <summary>
    /// (u,size(u))???
    /// </summary>
    public KeyValuePair<int, int> Get(int time, int x)
    {
        var l = 0;
        int r = history[x].Count;
        if (history[x].data[r - 1].v >= 0 && history[x].data[r - 1].t <= time) return Get(time, history[x].data[r - 1].v);
        while (l + 1 < r)
        {
            var m = (l + r) / 2;
            if (history[x].data[m].t <= time) l = m;
            else r = m;
        }

        if (history[x].data[l].v < 0) return new KeyValuePair<int, int>(x, -history[x].data[l].v);
        else return Get(time, history[x].data[l].v);
    }

    int _get(int x)
    {
        if (par[x] < 0) return x;
        else return par[x] = _get(par[x]);
    }
    public bool Unite(int x, int y)
    {
        x = _get(x);
        y = _get(y);
        last++;
        if (x == y) return false;
        if (rank[x] < rank[y])
        {
            par[y] += par[x];
            par[x] = y;

        }
        else
        {
            par[x] += par[y];
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        history[x].Add(new pair(last, par[x]));
        history[y].Add(new pair(last, par[y]));
        return true;

    }
    public bool IsUnited(int time, int x, int y)
    {
        return Get(time, x).Key == Get(time, y).Key;
    }
    struct pair
    {
        public int t, v;
        public pair(int time, int value)
        {
            t = time; v = value;
        }
    }
    public class FastList<T>
    {
        const int SIZE = 8;
        public T[] data;
        public int Count { get { return size; } }
        int size;
        public FastList() { data = new T[SIZE]; }
        public void Resize()
        {
            var ndata = new T[data.Length << 1];
            Array.Copy(data, ndata, size);
            data = ndata;
        }
        public void Add(T item)
        {
            if (size == data.Length) Resize();
            data[size++] = item;
        }
    }
}

#endregion