using System;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random();
        public void Solve() {
            var a = ri; var b = ri;
            var mat = Enumerate(a, x => new int[b]);
            for (int i = 0; i < a; i++)
                for (int j = 0; j < b; j++)
                    mat[i][j] = ri;

            var N = 300;
            var g = Enumerate(N, x => new int[N]);
            for (int i = 0; i < N; i++)
                for (int j = i + 1; j < N; j++)
                    g[i][j] = g[j][i] = 1000000;
            var src = N - 2;
            var sink = src + 1;
            g[src][0] = 0;
            g[src][150] = 0;
            g[100][sink] = 0;
            g[250][sink] = 0;
            for (int i = 0; i < 100; i++)
            {
                g[i][i + 1] = -1;
                g[i + 150][i + 151] = -2;
            }
            var ok = Enumerate(a, x => new bool[b]);
            for (int i = 0; i <= 100; i++)
                for (int j = 0; j <= 100; j++)
                {
                    var max = 0;
                    for (int x = 1; x <= a; x++)
                        for (int y = 1; y <= b; y++)
                            max = Math.Max(max, mat[x - 1][y - 1] - i * x - j * y);
                    g[i][250 - j] = max;
                    for (int x = 1; x <= a; x++)
                        for (int y = 1; y <= b; y++)
                            if (max == mat[x - 1][y - 1] - i * x - j * y) ok[x - 1][y - 1] = true;
                }
            if (ok.SelectMany(x => x).All(x => x))
            {
                Console.WriteLine("Possible");
                var E = new List<int[]>();
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                    {
                        if (i == j) continue;
                        if (g[i][j] == 1000000) continue;
                        E.Add(new int[] { i + 1, j + 1, g[i][j] });
                    }
                Console.WriteLine($"{N} {E.Count}");
                foreach (var x in E)
                {
                    var label = x[2].ToString();
                    if (x[2] == -1) label = "X";
                    if (x[2] == -2) label = "Y";
                    Console.WriteLine($"{x[0]} {x[1]} {label}");
                }
                Console.WriteLine($"{src + 1} {sink + 1}");
            }
            else { Console.WriteLine("Impossible"); }
        }
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