using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var T = sc.Integer();
            for (int _testcase = 0; _testcase < T; _testcase++)
            {
                var n = sc.Integer();
                var m = sc.Integer();
                var a = sc.Integer(n);
                var b = Enumerate(n, x => sc.Integer(m));
                var p = new Triplet<long, long, int>[n * m];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        p[i * m + j] = f(a[i], b[i][j], i);
                Array.Sort(p);
                var ans = 0;
                var used = new bool[n * m];
                for (int i = 0; i < n * m; i++)
                {
                    if (used[i]) continue;
                    var x = p[i];
                    if (x.I < x.J) continue;
                    //Debug.WriteLine("{0} {1} {2}", x.J, x.I, x.K);
                    var y = Enumerate(n, t => -1);
                    y[x.K] = i;
                    for (int j = i + 1; j < n * m; j++)
                    {
                        if (used[j]) continue;
                        if (y[p[j].K] != -1) continue;
                        if (p[j].I < p[j].J) continue;
                        if (x.I < p[j].J) continue;
                        y[p[j].K] = j;
                    }
                    if (y.Any(t => t == -1)) continue;
                    for (int j = 0; j < n; j++)
                        used[y[j]] = true;
                    ans++;
                }
                IO.Printer.Out.WriteLine($"Case #{_testcase + 1}: {ans}");
            }
        }
        Triplet<long, long, int> f(int x, int y, int k)
        {
            var max = 10 * y / (9 * x);
            var min = (10 * y + 11 * x - 1) / (11 * x);
            return new Triplet<long, long, int>(max, min, k);
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

#region Triplet<ST,FT,TT>
static public class Triplet
{
    static public Triplet<FT, ST, TT> Create<FT, ST, TT>(FT f, ST s, TT t) where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
    {
        return new Triplet<FT, ST, TT>(f, s, t);
    }

    static public Triplet<FT, ST, TT> Max<FT, ST, TT>(Triplet<FT, ST, TT> p, Triplet<FT, ST, TT> q) where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
    {
        return p.CompareTo(q) >= 0 ? p : q;
    }
    static public Triplet<FT, ST, TT> Min<FT, ST, TT>(Triplet<FT, ST, TT> p, Triplet<FT, ST, TT> q) where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
    {
        return p.CompareTo(q) <= 0 ? p : q;
    }
}
public struct Triplet<FT, ST, TT>: IComparable<Triplet<FT, ST, TT>> where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
{
    public FT I;
    public ST J;
    public TT K;
    public Triplet(FT i, ST j, TT k) : this() { I = i; J = j; K = k; }
    public int CompareTo(Triplet<FT, ST, TT> other)
    {
        var cmp = I.CompareTo(other.I);
        if (cmp != 0) return cmp;
        cmp = J.CompareTo(other.J);
        if (cmp != 0) return cmp;
        return K.CompareTo(other.K);
    }
    public override string ToString() { return string.Format("{0} {1} {2}", I, J, K); }
}
#endregion