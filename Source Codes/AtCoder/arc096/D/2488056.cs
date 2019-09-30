using System;
using System.Collections.Generic;
using System.Linq;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
using System.Numerics;
using static System.Math;
namespace Program
{
    public class Solver
    {
        Random rnd = new Random();
        public void Solve()
        {

            var n = ri;
            var X = rl;
            var d = rl;
            var val = new long[n];
            var sz = Enumerate(n, x => 1);
            var par = new int[n];
            val[0] = rl;
            par[0] = -1;
            for (int i = 1; i < n; i++)
            {
                val[i] = rl;
                par[i] = ri - 1;
            }
            for (int i = n - 1; i >= 0; i--)
                for (int j = i + 1; j < n; j++)
                    if (par[j] == i)
                    {
                        sz[i] += sz[j];
                        val[i] += val[j];
                    }
            var id = Enumerate(n, x => x);
            Array.Sort(id, (l, r) => (val[r] * sz[l]).CompareTo(val[l] * sz[r]));
            Array.Reverse(id);

            var dp = Enumerate(55 * 55 * 55, x => INF);
            dp[0] = 0;
            foreach (var i in id)
            {

                var s = sz[i];
                var v = val[i];
                var cnt = Math.Min(i == 0 ? INF : d, 55);
                var a = new List<long>();
                for (long u = 1; u <= cnt; u *= 2)
                {
                    a.Add(u); cnt -= u;
                }
                if (cnt > 0) a.Add(cnt);
                //Console.Error.WriteLine(a.AsJoinedString());
                foreach (var x in a)
                {
                    for (int j = dp.Length - 1; j >= 0; j--)
                        if (j + s * x < dp.Length) dp[j + s * x] = Min(dp[j + s * x], dp[j] + v * x);
                }
            }
            //Console.Error.WriteLine(val.AsJoinedString());
            //Console.Error.WriteLine(sz.AsJoinedString());
            //Console.Error.WriteLine(Enumerate(n, x => val[x] * 1.0 / sz[x]).AsJoinedString());

            var ans = 0L;
            for (int u = 0; u < dp.Length; u++)
            {
                if (dp[u] > X) continue;
                var rem = X - dp[u];
                long res = u;
                foreach (var i in id)
                {
                    var s = sz[i];
                    var v = val[i];
                    var cnt = (i == 0 ? INF : d) - Math.Min(i == 0 ? INF : d, 55);
                    cnt = Min(cnt, rem / v);
                    res += cnt * s;
                    rem -= cnt * v;
                }
                ans = Max(ans, res);
            }
            Console.WriteLine(ans);



        }

        const long INF = 1L << 60;
        //static int[] dx = { -1, 0, 1, 0 };
        //static int[] dy = { 0, 1, 0, -1 };

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
        Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = true });
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
namespace Program.IO
{
    using System.Globalization;
    using System.IO;
    using System.Text;

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
            for (var b = Char(); b != '\n' && b != 0; b = (char)read())
                if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}
#endregion