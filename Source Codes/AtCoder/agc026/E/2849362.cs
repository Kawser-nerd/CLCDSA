using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random();
        public void Solve() {
            var n = ri;
            var s = rs;
            var ptr = new int[2 * n];
            var a = new List<int>();
            var b = new List<int>();
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == 'a') { ptr[i] = a.Count; a.Add(i); }
                else { ptr[i] = b.Count + n; b.Add(i); }
            }
            var dp = new string[2 * n + 1];
            dp[2 * n] = "";
            for (int i = s.Length - 1; i >= 0; i--)
            {
                dp[i] = dp[i + 1];
                var p = ptr[i] % n;
                if (Min(a[p], b[p]) != i) continue;
                //a->b
                if (ptr[i] < n)
                {
                    var t = "ab" + dp[b[p] + 1];
                    if (string.CompareOrdinal(dp[i], t) < 0) dp[i] = t;
                }
                else
                {
                    var used = new bool[2 * n];
                    var r = a[p];
                    for (int j = p; j < n; j++)
                        if (b[j] < r)
                        {
                            used[b[j]] = used[a[j]] = true;
                            r = a[j];
                        }
                    var sb = new SB();
                    for (int j = 0; j < 2 * n; j++)
                        if (used[j]) sb.Append(s[j]);
                    sb.Append(dp[r + 1]);
                    var t = sb.ToString();
                    if (string.CompareOrdinal(dp[i], t) < 0) dp[i] = t;

                }
            }
            Console.WriteLine(dp[0]);
        }
        const long INF = 1L << 60;
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex {
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
        return string.Join(st, ie);
    }
    static public void Main() {
        Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer: StreamWriter {
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }

        private byte read() {
            if (isEof) return 0;
            if (ptr >= len)
            {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0)
                {
                    isEof = true;
                    return 0;
                }
            }
            return buf[ptr++];
        }

        public char Char() {
            byte b = 0;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan() {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine() {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}

#endregion