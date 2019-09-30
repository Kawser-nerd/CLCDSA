using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
using static System.Math;
using C = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri - 1;
            var m = ri;
            var k = ri;
            var dp = new int[1 << n];
            var next = new int[1 << n];
            dp[0] = 1;
            var query = new int[m, n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    query[i, j] = -1;
            for (int i = 0; i < k; i++)
                query[ri - 1, ri - 1] = ri;

            var go = new int[1 << n, n];
            for (int i = 0; i < 1 << n; i++)
                for (int j = 0; j < n; j++)
                {
                    if ((i >> j & 1) == 1) continue;
                    var ni = i ^ (1 << j);
                    for (int jj = j + 1; jj < n; jj++)
                        if ((ni >> jj & 1) == 1) { ni ^= (1 << jj); break; }
                    go[i, j] = ni;
                }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Array.Clear(next, 0, next.Length);
                    for (int mask = 0; mask < 1 << n; mask++)
                    {
                        if (query[i, j] == -1 || query[i, j] == 0)
                        {
                            if ((mask >> j & 1) == 0) add(ref next[mask], dp[mask]);
                        }
                        if (query[i, j] == -1 || query[i, j] == 1)
                        {
                            if ((mask >> j & 1) == 1) add(ref next[mask], dp[mask]);
                            else add(ref next[go[mask, j]], dp[mask]);
                        }
                    }
                    Swap(ref dp, ref next);
                }
            }
            int ans = 0;
            for (int i = 0; i < 1 << n; i++)
                add(ref ans, dp[i]);
            Console.WriteLine(ans);
        }
        void add(ref int x, int y) {
            x += y;
            if (x >= MOD) x -= MOD;
        }
        const int MOD = (int)1e9 + 7;
        void add(ref long x, long y) { x += y; x %= MOD; }
        const long INF = 1L << 60;
        //int[] dx = { -1, 0, 1, 0 };
        //int[] dy = { 0, 1, 0, -1 };

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
        return string.Join(st, ie.Select(x => x.ToString()).ToArray());
        //return string.Join(st, ie);
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