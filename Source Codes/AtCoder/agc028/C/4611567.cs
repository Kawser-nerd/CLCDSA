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
            //type A:   i-> ????
            //type B: ->i   ????
            //type C: ->i-> ???
            //type D:   i   ???
            // type C ? type D ??????????????
            //CAAAAAADBBBBBCDCD ??????
            //0???????????
            var AB = Enumerate(n, x => new long[] { rl, rl });
            var ans = Min(AB.Select(x => x[0]).Sum(), AB.Select(x => x[1]).Sum());
            //??????? N ??????????
            //
            //type A ? type B ????????type C ????????
            //1?????????????????????????
            // ????1: a[n-1]???????a[n] ????(a[n]!=a[n+1]??ok)
            // ????2: a[n-1] ???????a[n+1] ????
            // ????3: a[n-2] ???????a[n] ????
            var a = new List<long>();
            foreach (var i in Rep(n)) {
                a.Add(AB[i][0] * 1000000 + i);
                a.Add(AB[i][1] * 1000000 + i);
            }
            a.Sort();
            var v = 0L;
            var used = new int[n];
            for (int i = 0; i < n; i++) {
                v += a[i] / 1000000;
                var u = a[i] % 1000000;
                used[u]++;
            }
            if (used.Max() == 2) ans = Min(ans, v);
            else {
                Debug.WriteLine("po");
                if (a[n - 1] % 1000000 != a[n] % 1000000) ans = Min(ans, v - a[n - 1] / 1000000 + a[n] / 1000000);
                else {
                    ans = Min(ans, v - a[n - 1] / 1000000 + a[n + 1] / 1000000);
                    ans = Min(ans, v - a[n - 2] / 1000000 + a[n] / 1000000);
                }
            }
            Console.WriteLine(ans);
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