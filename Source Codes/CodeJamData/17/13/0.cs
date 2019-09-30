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
                var hp = sc.Integer();
                var atk = sc.Integer();
                var ep = sc.Integer();
                var eat = sc.Integer();
                var b = sc.Integer();
                var d = sc.Integer();
                var ans = f(hp, atk, ep, eat, b, d);
                var otaku = ans.ToString();
                if (ans == -1) otaku = "IMPOSSIBLE";
                IO.Printer.Out.WriteLine($"Case #{_testcase + 1}: {otaku}");
            }
        }
        long f(int hp, int atk, int ep, int eat, int buf, int def)
        {
            var dp = new int[110, 110, 110, 110];
            for (int i = 0; i < 110; i++)
                for (int j = 0; j < 110; j++)
                    for (int k = 0; k < 110; k++)
                        for (int l = 0; l < 110; l++)
                            dp[i, j, k, l] = 1000000000;
            var q = new Queue<long>();
            q.Enqueue(enc(hp, atk, ep, eat));
            dp[hp, atk, ep, eat] = 0;
            while (q.Count > 0)
            {
                var p = q.Dequeue();
                int h, a, i, b;
                dec(p, out h, out a, out i, out b);
                if (a >= i)
                    return dp[h, a, i, b] + 1;

                //atk
                {
                    var nh = h - b;
                    if (nh > 0)
                    {
                        if (dp[nh, a, i - a, b] > dp[h, a, i, b] + 1)
                        {
                            dp[nh, a, i - a, b] = dp[h, a, i, b] + 1;
                            q.Enqueue(enc(nh, a, i - a, b));
                        }
                    }
                }
                //buf
                {
                    var nh = h - b;
                    if (nh > 0)
                    {
                        if (dp[nh, a + buf, i, b] > dp[h, a, i, b] + 1)
                        {
                            dp[nh, a + buf, i, b] = dp[h, a, i, b] + 1;
                            q.Enqueue(enc(nh, a + buf, i, b));
                        }
                    }

                }
                //cure
                {
                    var nh = hp - b;
                    if (nh > 0)
                    {
                        if (dp[nh, a, i, b] > dp[h, a, i, b] + 1)
                        {
                            dp[nh, a, i, b] = dp[h, a, i, b] + 1;
                            q.Enqueue(enc(nh, a, i, b));
                        }
                    }
                }
                //debuf
                {
                    var nb = Math.Max(0, b - def);
                    var nh = h - nb;
                    if (nh > 0)
                    {
                        if (dp[nh, a, i, nb] > dp[h, a, i, b] + 1)
                        {
                            dp[nh, a, i, nb] = dp[h, a, i, b] + 1;
                            q.Enqueue(enc(nh, a, i, nb));
                        }
                    }

                }
            }
            return -1;
        }
        long enc(int h, int a, int i, int b)
        {
            var x = 0L;
            x = x * 200 + h;
            x = x * 200 + a;
            x = x * 200 + i;
            x = x * 200 + b;
            return x;
        }
        void dec(long x, out int h, out int a, out int i, out int b)
        {
            b = (int)(x % 200); x /= 200;
            i = (int)(x % 200); x /= 200;
            a = (int)(x % 200); x /= 200;
            h = (int)(x % 200); x /= 200;
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

