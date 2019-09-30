using System;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
namespace Program
{
    public class Solver
    {
        int[] N;
        int[] B;
        long[][] M;
        public void Solve()
        {

            var T = sc.Integer();
            N = new int[T];
            B = new int[T];
            M = new long[T][];
            for (int _ = 0; _ < T; _++)
            {
                B[_] = sc.Integer();
                N[_] = sc.Integer();
                M[_] = sc.Long(B[_]);
            }
            for (int i = 0; i < T; i++)
                func(i);
        }
        public void func(int _)
        {
            long l = 0, r = (long)1e14;
            int num = 0;
            var n = N[_];
            var k = B[_];
            var a = M[_];
            while (l < r && num < 100)
            {
                var m = (l + r) >> 1;
                long cnt = 0;
                for (int i = 0; i < k; i++)
                    cnt += (m + a[i] - 1) / a[i];
                if (cnt < n)
                    l = m;
                else r = m;
                num++;
            }
            Debug.WriteLine("{0} {1}", l, r);
            {
                long cnt = 0;
                for (int i = 0; i < k; i++)
                    cnt += (l + a[i] - 1) / a[i];
                for (int i = 0; i < k; i++)
                {
                    if (l % a[i] == 0) cnt++;
                    if (cnt == n)
                    {
                        IO.Printer.Out.WriteLine("Case #{0}: {1}", _ + 1, i + 1);
                        return;
                    }
                }
                throw new Exception();
            }
            //IO.Printer.Out.WriteLine("Case #{0}: {1} {2}", _ + 1, );
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
