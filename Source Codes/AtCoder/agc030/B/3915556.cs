using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Point = System.Numerics.Complex;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var L = rl;
            var n = ri;
            var A = Enumerate(n, x => rl);
            var B = Enumerate(n, x => L - A[x]);
            Array.Reverse(B);
            var ans = solve(n, A, B);
            ans = Max(ans, solve(n, B, A));
            Console.WriteLine(ans);
        }
        long solve(int n, long[] A, long[] B) {
            Debug.WriteLine("----------------");
            Debug.WriteLine(A.AsJoinedString());
            Debug.WriteLine(B.AsJoinedString());
            var ret = 0L;
            var cumA = new long[n + 1];
            var cumB = new long[n + 1];
            for (int i = 0; i < n; i++) {
                cumA[i + 1] = cumA[i] + A[i];
                cumB[i + 1] = cumB[i] + B[i];
            }
            // ...LLLLLL|RLRL
            //RRLRL
            for (int i = 1; i <= n; i++) {
                var j = n - i;
                var min = Min(i, j);
                var u = 0L;
                u += 2 * (cumA[i] - cumA[i - min]);
                u += 2 * (cumB[j] - cumB[j - min]);
                u -= A[i - 1];
                if (i > j) u += 2 * A[i - min - 1];

                ret = Max(ret, u);
                Debug.WriteLine($"{i} {j} {min} {u}");
            }

            return ret;
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
            if (ptr >= len) {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0) {
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