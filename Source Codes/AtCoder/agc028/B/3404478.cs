using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Point = System.Numerics.Complex;
using Number = System.Int64;
using C = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var a = Enumerate(n, x => rl);
            var ans = 0L;
            const long M = (long)1e9 + 7;
            var frac = new long[n + 1];
            for (int i = 1; i <= n; i++)
                frac[i] = (long)BigInteger.ModPow(i, M - 2, M);
            for (int i = 1; i <= n; i++)
                frac[i] = (frac[i] + frac[i - 1]) % M;
            for (int i = 0; i < n; i++)
            {
                var l = i;
                var r = n - i - 1;
                ans += (frac[l + 1] + frac[r + 1] - 1) * a[i];
                Debug.WriteLine((frac[l + 1] + frac[r + 1] - 1) * a[i]);
                ans %= M;
            }
            for (int i = 1; i <= n; i++) ans = (ans * i) % M;
            Console.WriteLine(ans);
            //solve(n);
        }
        void solve(int n) {
            double ans = 0.0;
            for (int i = 0; i < n; i++)
            {
                var add = 0.0;
                for (int j = 0; j < n; j++)
                    add += 1.0 / (Abs(i - j) + 1);
                Debug.WriteLine(add);
                ans += add;
            }
            for (int i = 1; i <= n; i++)
                ans *= i;
            Console.WriteLine(ans);
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