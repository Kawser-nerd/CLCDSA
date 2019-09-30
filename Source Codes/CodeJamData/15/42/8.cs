using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
//using System.Threading.Tasks;
namespace Program
{

    public class Solver
    {
        public void Solve()
        {
            var __ = sc.Integer();
            for (int _ = 1; _ <= __; _++)
            {
                var n = sc.Integer();
                var V = sc.Double();
                var X = sc.Double();
                var r = new double[n];
                var c = new double[n];
                for (int i = 0; i < n; i++)
                {
                    r[i] = sc.Double();
                    c[i] = sc.Double();
                }
                if (n == 1)
                {
                    if (c[0] == X)
                        IO.Printer.Out.WriteLine("Case #{0}: {1:0.000000000000}", _, V / r[0]);
                    else IO.Printer.Out.WriteLine("Case #{0}: IMPOSSIBLE", _);

                }
                else if (n == 2)
                {
                    if (c.All(x => x > X) || c.All(x => x < X))
                    {
                        IO.Printer.Out.WriteLine("Case #{0}: IMPOSSIBLE", _);
                    }
                    else if (c[0] == X && c[1] == X)
                    {
                        var ans = V / (r[0] + r[1]);
                        IO.Printer.Out.WriteLine("Case #{0}: {1:0.000000000000}", _, ans);
                    }
                    else if (c[0] == X)
                    {
                        var ans = V / (r[0]);
                        IO.Printer.Out.WriteLine("Case #{0}: {1:0.000000000000}", _, ans);
                    }
                    else if (c[1] == X)
                    {
                        var ans = V / (r[1]);
                        IO.Printer.Out.WriteLine("Case #{0}: {1:0.000000000000}", _, ans);
                    }
                    else
                    {
                        var v0 = Math.Abs(V * (X - c[1]) / (c[1] - c[0]));
                        var v1 = V - v0;
                        var ans = Math.Max(v0 / r[0], v1 / r[1]);
                        IO.Printer.Out.WriteLine("Case #{0}: {1:0.000000000000}", _, ans);
                    }
                }
                else IO.Printer.Out.WriteLine("Case #{0}: OTAKU", _);


                //IO.Printer.Out.WriteLine("Case #{0}: {1}", _);
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
#endregion
