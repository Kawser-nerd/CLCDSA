using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;

using Point = System.Numerics.Complex;
namespace Program
{
    public class Solver
    {
        int[] N;
        int[][] A;
        int[][] B;
        public void Solve()
        {

            var T = sc.Integer();
            N = new int[T];
            A = new int[T][];
            B = new int[T][];
            for (int _ = 0; _ < T; _++)
            {
                N[_] = sc.Integer();
                A[_] = new int[N[_]];
                B[_] = new int[N[_]];
                for (int i = 0; i < N[_]; i++)
                {
                    A[_][i] = sc.Integer();
                    B[_][i] = sc.Integer();
                }
            }
            for (int i = 0; i < T; i++)
                func(i);
        }
        public void func(int _)
        {
            var n = N[_];
            var ans = new int[n];
            for (int i = 0; i < n; i++)
                ans[i] = 1 << 20;
            var P = new Point[n];
            var dic = new Dictionary<Point, int>();
            for (int i = 0; i < n; i++)
            {
                P[i] = new Point(A[_][i], B[_][i]);
                dic[P[i]] = i;
            }
            for (int i = 1; i < 1 << n; i++)
            {
                var cnt = 0;
                var Q = new List<Point>();
                for (int j = 0; j < n; j++)
                    if ((i >> j & 1) == 1)
                    {
                        Q.Add(new Point(A[_][j], B[_][j]));
                        cnt++;
                    }
                var conv = Geometry.ConvexHull(Q.ToArray());
                for (int j = 0; j < conv.Length; j++)
                    ans[dic[conv[j]]] = Math.Min(ans[dic[conv[j]]], n - cnt);
            }
            IO.Printer.Out.WriteLine("Case #{0}:", _ + 1);
            for (int i = 0; i < n; i++)
                IO.Printer.Out.WriteLine(ans[i]);
        }

        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
    }
}

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
        public void Write<T>(string format, IEnumerable<T> source) { base.Write(format, source.OfType<object>().ToArray()); }
        public void WriteLine<T>(string format, IEnumerable<T> source) { base.WriteLine(format, source.OfType<object>().ToArray()); }
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
        public char Char() { byte b = 0; do b = read(); while (b < 33 || 126 < b); return (char)b; }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != '-' && (b < '0' || '9' < b));
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { return double.Parse(Scan(), CultureInfo.InvariantCulture); }
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


#region Functions
static public partial class Geometry
{
    public const double EPS = 1e-8;
    static public double Cross(Point a, Point b)
    {
        return (Point.Conjugate(a) * b).Imaginary;
    }
    static public double Dot(Point a, Point b)
    {
        return (Point.Conjugate(a) * b).Real;
    }
    static public int CCW(Point a, Point b, Point c)
    {
        b -= a; c -= a;
        if (Cross(b, c) > 0) return 1;
        if (Cross(b, c) < 0) return -1;
        if (Dot(b, c) < 0) return 2;
        if (b.Magnitude < c.Magnitude) return -2;
        return 0;
    }
    static public int Compare(Point a, Point b)
    {
        if (a.Real != b.Real)
            return (a.Real > b.Real) ? 1 : -1;
        else if (a.Imaginary != b.Imaginary)
            return a.Imaginary > b.Imaginary ? 1 : -1;
        return 0;
    }
}
#endregion

#region ConvexHull
static public partial class Geometry
{
    static public Point[] ConvexHull(Point[] ps)
    {
        var n = ps.Length;
        Array.Sort(ps, (l, r) =>
        {
            var cmp = l.Real.CompareTo(r.Real);
            return cmp != 0 ? cmp : l.Imaginary.CompareTo(r.Imaginary);
        });
        var ch = new Point[2 * n];
        var k = 0;
        for (int i = 0; i < n; ch[k++] = ps[i++])
            while (k >= 2 && Geometry.CCW(ch[k - 2], ch[k - 1], ps[i]) <= 0 && Geometry.CCW(ch[k - 2], ch[k - 1], ps[i]) > -2) --k;
        for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
            while (k >= t && Geometry.CCW(ch[k - 2], ch[k - 1], ps[i]) <= 0 && Geometry.CCW(ch[k - 2], ch[k - 1], ps[i]) > -2) --k;
        var ret = new Point[k - 1];
        for (int i = 0; i < k - 1; i++)
            ret[i] = ch[i];
        return ret;
    }
}
#endregion