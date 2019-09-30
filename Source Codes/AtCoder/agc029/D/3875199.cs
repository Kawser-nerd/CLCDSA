using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        Random rnd = new Random();
        public void Solve()
        {
            var h = ri;
            var w = ri;
            var n = ri;
            var P = Enumerate(w + 1, x => new List<int>());
            for (int i = 0; i < n; i++)
            {
                var u = ri - 1;
                var v = ri - 1;
                P[v].Add(u);
            }
            for (int i = 0; i <= w; i++) { P[i].Add(h); P[i].Sort(); }

            var ans = long.MaxValue;

            for (int u = 0, v = 0; ;)
            {
                //taro
                if (P[v].BinarySearch(u + 1) >= 0)
                {
                    ans = Min(ans, u + 1);
                    break;
                }
                u++;
                //jiro
                var pos = P[v].BinarySearch(u);
                if (pos < 0) pos = ~pos;
                ans = Min(ans, P[v][pos]);
                //Debug.WriteLine($"{u} {P[v][pos]}");
                if (v + 1 < w && P[v + 1].BinarySearch(u) < 0) v++;

            }
            Console.WriteLine(ans);
        }

        const long INF = 1L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex
{
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ")
    {
        return string.Join(st, ie);
    }
    static public void Main()
    {
        //Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer : StreamWriter
    {
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner
    {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }

        private byte read()
        {
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

        public char Char()
        {
            byte b = 0;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine()
        {
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