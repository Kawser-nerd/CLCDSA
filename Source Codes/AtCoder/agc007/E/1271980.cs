using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Int64;
using static System.Math;
using P = Pair<long, long>;
namespace Program
{
    public class Solver
    {
        const int B = 32;
        const long M = (1L << 32) - 1;
        const long U = ~M;
        public void Solve()
        {

            var n = ri;
            var G = Enumerate(n, x => new List<KeyValuePair<int, int>>());
            for (int i = 0; i < n - 1; i++)
            {
                var a = ri - 1;
                var b = i + 1;
                var w = ri;
                G[a].Add(new KeyValuePair<int, int>(b, w));
            }
            Func<List<P>, List<P>, List<P>> g = (a, b) =>
            {
                var ret = new List<P>();
                var min = 1000000000000000;
                int i = 0, j = 0;
                while (i < a.Count && j < b.Count)
                {
                    var l = a[i];
                    var r = b[j];
                    if (min <= l.y) { i++; continue; }
                    if (min <= r.y) { j++; continue; }
                    if (l.CompareTo(r) <= 0) { i++; min = l.y; ret.Add(l); }
                    else { j++; min = r.y; ret.Add(r); }
                }
                while (i < a.Count)
                {
                    if (min <= a[i].y) i++;
                    else { min = a[i].y; ret.Add(a[i++]); }
                }
                while (j < b.Count)
                {
                    if (min <= b[j].y) j++;
                    else { min = b[j].y; ret.Add(b[j++]); }
                }

                return ret;
            };

                var s = Enumerate(n, x => new List<P>());
            Func<long, bool> f = null;
            f = x =>
            {
                for (int cur = n - 1; cur >= 0; cur--)
                {
                    if (G[cur].Count == 0) { s[cur] = new List<P>() { new P(0, 0) }; continue; }
                    var l = s[G[cur][0].Key];
                    var r = s[G[cur][1].Key];
                    if (l.Count == 0) return false;
                    if (r.Count == 0) return false;
                    var u = G[cur][0].Value;
                    var v = G[cur][1].Value;
                    var a = new List<P>();
                    var b = new List<P>();

                    if (l.Count > r.Count) { Swap(ref l, ref r); Swap(ref u, ref v); }
                    var i = 0; var j = 0; var k = 0;
                    while (i < l.Count)
                    {
                        while (j < r.Count && l[i].x + r[j].y + u + v > x) j++;
                        while (k + 1 < r.Count && l[i].y + r[k + 1].x + u + v <= x) k++;
                        if (k < r.Count && l[i].y + r[k].x + u + v <= x) a.Add(new P(l[i].x + u, r[k].y + v));
                        if (j < r.Count) b.Add(new P(r[j].x + v, l[i].y + u));
                        i++;
                    }

                    s[cur] = g(a, b);
                }
                //Debug.WriteLine($"[{cur}], {ret.AsJoinedString()}");
                return s[0].Count > 0;
            };

            {
                long l = -1, r = 100000000;
                while (r - l > 1)
                {
                    var m = (l + r) / 2;
                    if (f(m)) r = m;
                    else l = m;
                }
                IO.Printer.Out.WriteLine(r);
            }
        }
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();


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
#region Compair
static public class Pair
{
    static public Pair<FT, ST> Create<FT, ST>(FT f, ST s) where FT : IComparable<FT> where ST : IComparable<ST>
    {
        return new Pair<FT, ST>(f, s);
    }
    static public Pair<FT, ST> Min<FT, ST>(Pair<FT, ST> p, Pair<FT, ST> q) where FT : IComparable<FT> where ST : IComparable<ST>
    {
        return (p.CompareTo(q) <= 0) ? p : q;
    }
    static public Pair<FT, ST> Max<FT, ST>(Pair<FT, ST> p, Pair<FT, ST> q) where FT : IComparable<FT> where ST : IComparable<ST>
    {
        return (p.CompareTo(q) >= 0) ? p : q;
    }
}
public struct Pair<FT, ST>: IComparable<Pair<FT, ST>> where FT : IComparable<FT> where ST : IComparable<ST>
{
    public FT x;
    public ST y;
    public Pair(FT f, ST s) : this() { x = f; y = s; }

    public int CompareTo(Pair<FT, ST> other)
    {
        var cmp = x.CompareTo(other.x);
        return cmp != 0 ? cmp : y.CompareTo(other.y);
    }
    public override string ToString() { return string.Format("[{0} {1}]", x, y); }
}
#endregion