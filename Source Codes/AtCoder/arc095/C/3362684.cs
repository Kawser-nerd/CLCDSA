using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var h = ri;
            var w = ri;
            var s = Enumerate(h, x => rs);
            try
            {
                var ok = new bool[w, w];
                Action<int[]> update = hmat =>
                {
                    for (int i = 0; i < w; i++)
                        for (int j = 0; j < w; j++)
                        {
                            ok[i, j] = true;
                            for (int p = 0; p < h; p++)
                                ok[i, j] &= s[p][i] == s[hmat[p]][j] && s[p][j] == s[hmat[p]][i];
                        }
                   // Debug.WriteLine(hmat.AsJoinedString());
                };

                Action<int[], int, int[], int, bool, bool> dfs = null;
                dfs = (hmat, remh, wmat, remw, p, q) =>
                {
                    if (remh > 0)
                    {
                        for (int i = 0; i < h; i++)
                        {
                            if (hmat[i] != -1) continue;
                            else
                            {
                                if (!p)
                                {
                                    hmat[i] = i;
                                    if (remh == 1) update(hmat);
                                    dfs(hmat, remh - 1, wmat, remw, true, q);
                                    hmat[i] = -1;
                                }
                                for (int j = i + 1; j < h; j++)
                                    if (hmat[j] == -1)
                                    {
                                        hmat[i] = j;
                                        hmat[j] = i;
                                        if (remh == 2)
                                            update(hmat);
                                        dfs(hmat, remh - 2, wmat, remw, p, q);
                                        hmat[i] = -1;
                                        hmat[j] = -1;
                                    }
                            }
                            return;
                        }
                    }
                    else if (remw > 0)
                    {

                        for (int i = 0; i < w; i++)
                        {
                            if (wmat[i] != -1) continue;
                            else
                            {
                                if (!q && ok[i, i])
                                {
                                    wmat[i] = i;
                                    dfs(hmat, remh, wmat, remw - 1, p, true);
                                    wmat[i] = -1;
                                }
                                for (int j = i + 1; j < w; j++)
                                    if (wmat[j] == -1)
                                    {
                                        if (ok[i, j])
                                        {
                                            wmat[i] = j;
                                            wmat[j] = i;
                                            dfs(hmat, remh, wmat, remw - 2, p, q);
                                            wmat[i] = -1;
                                            wmat[j] = -1;
                                        }
                                    }
                            }
                            return;
                        }


                    }
                    else
                    {
                        Console.WriteLine("YES");
                        throw new Exception();
                    }
                };
                var m1 = Enumerate(h, x => -1);
                var m2 = Enumerate(w, x => -1);

                dfs(m1, h, m2, w, h % 2 == 0, w % 2 == 0);
            }
            catch { return; }
            Console.WriteLine("NO");
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