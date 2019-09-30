using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using Number = ModInt;
//using System.Numerics;
//using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var a = rs;
            var b = rs;
            if (a == b) { Console.WriteLine(0); }
            else if (b == new string('0', a.Length)) { Console.WriteLine(-1); }
            else
            {
                var ret = solve(a, b);
                a = a.Reverse().AsString(); b = b.Reverse().AsString();
                ret = Math.Min(ret, solve(a, b));
                Console.WriteLine(ret);
            }

        }
        int solve(string s, string t) {
            var ret = 1 << 30;
            var n = s.Length;
            var L = new int[n];
            var R = new int[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    if (t[(i - j + n) % n] == '1') { L[i] = j; break; }
                for (int j = 0; j < n; j++)
                    if (t[(i + j) % n] == '1') { R[i] = j; break; }
            }
            var erase = Enumerate(n + 5, x => new List<int>());
            //?????? i ?????????????
            var set = new int[n + 5];
            set[0]++;
            for (int i = 0; i < n; i++)
            {
                var diff = 0;
                for (int j = 0; j < n; j++)
                {
                    if (s[(i + j) % n] == t[j]) continue;
                    erase[L[j]].Add(R[j]);
                    set[R[j]]++;
                    diff++;
                }
                var ptr = 0;
                for (int j = n - 1; j >= 0; j--)
                    if (set[j] > 0) { ptr = j; break; }
                //?? a ????????
                for (int a = 0; a < n; a++)
                {
                    foreach (var x in erase[a]) set[x]--;
                    erase[a].Clear();
                    while (set[ptr] == 0) ptr--;
                    var b = ptr;
                    //l->r
                    ret = Math.Min(ret, diff + 2 * a + b + calc(n, b, i));
                    //r->l
                    ret = Math.Min(ret, diff + 2 * b + a + calc(n, (n - a) % n, i));
                }
            }

            return ret;
        }
        int calc(int n, int s, int t) {
            var d = Math.Abs(t - s);
            return Math.Min(d, n - d);
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