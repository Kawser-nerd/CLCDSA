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
            var n = ri;
            var a = Enumerate(n, x => ri);
            var l = 0; var r = 500000;
            while (r - l > 1)
            {
                var m = (l + r) / 2;
                if (ok(a, m)) r = m;
                else l = m;
            }
            Console.WriteLine(r);
        }
        bool ok(int[] s, int k)
        {
            Debug.WriteLine($"start {k}");
            var a = new Stack<int[]>();
            a.Push(new int[] { 0, s[0] });
            for (int i = 1; i < s.Length; i++)
            {
                //Debug.WriteLine(a.Reverse().Select(x => $"[{x[0]} {x[1]}]").AsJoinedString());
                if (s[i] > s[i - 1])
                {
                    if (a.Peek()[0] != 0) a.Push(new int[] { 0, s[i] - s[i - 1] });
                    else a.Peek()[1] += s[i] - s[i - 1];
                }
                else
                {
                    var v = s[i - 1] - s[i];
                    while (v > 0)
                    {
                        if (a.Count == 0) return false;
                        if (a.Peek()[1] <= v) { v -= a.Pop()[1]; }
                        else
                        {
                            a.Peek()[1] -= v;
                            break;
                        }
                    }
                    if (!increment(a, k)) return false;
                }
            }
            //Debug.WriteLine(a.Reverse().Select(x => $"[{x[0]} {x[1]}]").AsJoinedString());
            return true;
        }
        bool increment(Stack<int[]> a, int k)
        {
            if (a.Count == 0) return false;
            if (a.Peek()[0] != k - 1)
            {
                if (a.Peek()[1] == 1) a.Peek()[0]++;
                else
                {
                    a.Peek()[1]--; a.Push(new int[] { a.Peek()[0] + 1, 1 });
                }
                return true;
            }
            else
            {
                var u = a.Pop(); u[0] = 0;
                var res = increment(a, k);
                a.Push(u);
                return res;
            }
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