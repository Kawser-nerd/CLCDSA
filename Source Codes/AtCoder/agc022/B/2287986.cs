using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            //for (int n = 3; n <= 20000; n++)
            {

                var mod = Enumerate(6, x => new List<int>());
                for (int i = 2; i <= 30000; i++)
                    mod[i % 6].Add(i);
                var a = new List<int>();
                if (n == 3)
                {
                    a = new List<int>() { 2, 5, 63 };
                }
                else if (n <= 5000)
                {
                    a.Add(2);
                    a.Add(4);
                    a.Add(3);
                    a.Add(9);
                    for (int i = 0; i < n - 4; i++)
                        a.Add(mod[0][i]);
                }
                else
                {
                    foreach (var x in mod[3]) a.Add(x);
                    var m = (n - 5000) / 3;
                    for (int i = 0; i < m; i++)
                    {
                        a.Add(mod[2][i]);
                        a.Add(mod[4][i]);
                        a.Add(mod[0][i]);
                    }
                    if ((n - 5000) % 3 == 1) a.Add(mod[0][m]);
                    else if ((n - 5000) % 3 == 2) { a.Add(mod[2][m]); a.Add(mod[4][m]); }
                }
                Console.WriteLine(a.AsJoinedString());
                var sum = a.Sum();
                for (int i = 0; i < n; i++)
                {
                    if (MathEx.GCD(a[i], sum - a[i]) == 1)
                    {
                        Console.WriteLine(n);
                        Console.WriteLine(-1);
                        return;
                    }
                }
            }
        }
        const long INF = 1L << 60;
        //static int[] dx = { -1, 0, 1, 0 };
        //static int[] dy = { 0, 1, 0, -1 };

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

#region gcd,lcm
static public partial class MathEx {
    static public int GCD(int n, int m) { return (int)GCD((long)n, m); }
    static public long GCD(long n, long m) {
        n = Math.Abs(n); m = Math.Abs(m);
        while (n != 0)
        {
            m %= n;
            if (m == 0) return n;
            n %= m;
        }
        return m;
    }
    static public long LCM(long n, long m) { return (n / GCD(n, m)) * m; }
    static public long GCD(params long[] a) {
        var gcd = a[0];
        foreach (var x in a)
            gcd = GCD(gcd, x);
        return gcd;
    }

}
#endregion