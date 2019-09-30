using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Number = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var P = Enumerate(n, x => new int[] { ri, ri });
            const long M = 998244353;
            var ans = (long)BigInteger.ModPow(2, n, M);
            ans = (ans + M - n - 1) % M;
            var comb = new long[250, 250];
            comb[0, 0] = 1;
            foreach (var i in Rep(220))
                foreach (var j in Rep(220)) {
                    comb[i, j] %= M;
                    comb[i + 1, j] += comb[i, j];
                    comb[i + 1, j + 1] += comb[i, j];
                }
            Debug.WriteLine(ans);
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) {
                    var dx = P[j][0] - P[i][0];
                    var dy = P[j][1] - P[i][1];
                    Debug.WriteLine($"{i} {j} {dx} {dy}");
                    var cnt = 2;
                    var s = new List<int>() { i, j };
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        var ex = P[k][0] - P[i][0];
                        var ey = P[k][1] - P[i][1];
                        if (eq(dx, dy, ex, ey)) { cnt++; s.Add(k); }
                    }
                    s.Sort();
                    var add = (long)(BigInteger.ModPow(2, cnt, M) + M - cnt - 1) % M;
                    add = (long)(add * BigInteger.ModPow(comb[cnt, 2], M - 2, M) % M);
                    Debug.WriteLine(add);
                    Debug.WriteLine(s.AsJoinedString());
                    ans = (ans + M - add) % M;
                }
            Console.WriteLine(ans);
        }
        bool eq(int dx, int dy, int ex, int ey) {
            if (dx == 0) return ex == 0;
            if (dy == 0) return ey == 0;
            return ex * dy == ey * dx;
        }


        const long INF = 1L << 60;
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static IEnumerable<int> Rep(int n) => Enumerable.Range(0, n);
        static IEnumerable<int> RRep(int n) => Enumerable.Range(0, n).Reverse();
        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < a.Length; ++i) a[i] = f(i);
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

    public class Printer : StreamWriter {
        public override IFormatProvider FormatProvider => CultureInfo.InvariantCulture;
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;

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