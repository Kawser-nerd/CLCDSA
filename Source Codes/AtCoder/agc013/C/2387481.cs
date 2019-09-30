using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
//using System.Numerics;
//using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var L = rl * 100L;
            var T = rl * 100L;
            var a = new long[n];
            var d = new int[n];
            var pos = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = rl * 100L;
                d[i] = ri == 1 ? 1 : -1;
                pos[i] = (a[i] + d[i] * (T - 1)) % L;
                if (pos[i] < 0) pos[i] += L;
            }
            var cnt = 0L;
            for (int i = 0; i < n; i++)
            {
                if (d[0] == d[i]) continue;
                cnt += 2 * (T / L);
                var dx = a[i] - a[0];
                if (d[0] != 1) dx = L - dx;
                var t = T % L;
                if (2 * t > dx) cnt++;
                if (2 * t > dx + L) cnt++;
            }
            Debug.WriteLine(cnt);
            cnt %= n;
            var p = pos[0];
            var ans = new long[n];
            Array.Sort(pos);
            if (d[0] == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (pos[i] == p)
                    {
                        for (int j = 0; j < n; j++)
                            ans[(j + cnt) % n] = pos[(i + j) % n];
                        break;
                    }

                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (pos[i] == p)
                    {
                        for (int j = 0; j < n; j++)
                            ans[(j - cnt + n) % n] = pos[(i + j) % n];
                        break;
                    }
                }

            }
            for (int i = 0; i < n; i++)
                Console.WriteLine((ans[i] + 2) / 100);



        }

        const long INF = 1L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
        const string URDL = "URDL";
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
        try
        {
            solver.Solve();
            Console.Out.Flush();
        }
        catch { }
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