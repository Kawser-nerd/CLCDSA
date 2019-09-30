using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Int64;
using System.Numerics;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var s = sc.Scan().Select(x => x == 'A' ? 1 : 2).ToArray();
            var t = sc.Scan().Select(x => x == 'A' ? 1 : 2).ToArray();
            var S = new RMQSegmentTree(s.Length);
            var T = new RMQSegmentTree(t.Length);
            for (int i = 0; i < s.Length; i++)
                S.Update(i, s[i]);
            for (int i = 0; i < t.Length; i++)
                T.Update(i, t[i]);
            var q = sc.Integer();
            for (int i = 0; i < q; i++)
            {
                var l = sc.Integer() - 1;
                var r = sc.Integer();

                var L = sc.Integer() - 1;
                var R = sc.Integer();

                if (S.Query(l, r) == T.Query(L, R))
                    IO.Printer.Out.WriteLine("YES");
                else IO.Printer.Out.WriteLine("NO");

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

#region RMQ Segment Tree
public class RMQSegmentTree
{
    int n;
    Number[] data;
    public RMQSegmentTree(int size)
    {
        n = 1;
        while (n < size)
            n <<= 1;
        data = new Number[n << 1];
        for (int i = 0; i < data.Length; i++)
            data[i] = 0;
    }
    public void Update(int k, Number v)
    {
        k += n;
        data[k] = v;
        k >>= 1;
        while (k > 0)
        {
            data[k] = merge(data[k << 1], data[(k << 1) + 1]);
            k >>= 1;
        }

    }
    public Number Query(int a, int b) { return query(a, b, 1, 0, n); }
    private Number query(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return data[k];
        else
        {
            var vl = query(a, b, k << 1, l, (l + r) >> 1);
            var vr = query(a, b, (k << 1) + 1, (l + r) >> 1, r);
            return merge(vl, vr);
        }
    }
    Number merge(Number l, Number r)
    {
        if (l == 0) return r;
        if (r == 0) return l;
        if (l != r) return 0;
        return l ^ 3;
    }
    public Number[] Items
    {
        get
        {
            var ret = new Number[n];
            for (int i = 0; i < n; i++)
                ret[i] = data[i + n];
            return ret;
        }
    }

}
#endregion