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
            const long M = (long)1e9 + 7;
            var n = ri * 2; var k = ri;
            var a = Enumerate(k, x => new int[] { ri - 1, ri - 1 });

            long[][] dp = Enumerate(n, x => new long[n]);
            long[][] ep = Enumerate(n, x => new long[n]);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i][j] = ep[i][j] = -1;
            long[] f = new long[n + 5];
            f[0] = 1;
            for (int i = 2; i <= n; i += 2)
                f[i] = f[i - 2] * (i - 1) % M;
            Func<int, int, long> efs = null;
            efs = (l, r) =>
            {
                if (ep[l][r] != -1) return ep[l][r];
                var cnt = 0;
                foreach (var v in a)
                {
                    if (l <= v[0] && v[0] <= r) cnt++;
                    if (l <= v[1] && v[1] <= r) cnt++;
                    if (cnt % 2 == 1) return dp[l][r] = 0;
                }
                return ep[l][r] = f[r - l + 1 - cnt];
            };
            Func<int, int, long> dfs = null;
            dfs = (l, r) =>
            {
                if (dp[l][r] != -1) return dp[l][r];
                var ret = efs(l, r);
                for (int i = l + 1; i < r; i += 2)
                    ret = (ret + M - dfs(l, i) * efs(i + 1, r) % M) % M;
                return dp[l][r] = ret;
            };
            long ans = 0;
            for (int l = 0; l < n; l++)
                for (int r = l + 1; r < n; r++)
                {
                    var add = dfs(l, r);
                    if (add == 0) continue;
                    var cnt = 0;
                    foreach (var v in a)
                    {
                        if (l <= v[0] && v[0] <= r) cnt++;
                        if (l <= v[1] && v[1] <= r) cnt++;
                    }
                    var rem = n - (r - l + 1);
                    rem -= 2 * k - cnt;
                    add = add * f[rem] % M;
                    Debug.WriteLine($"{l + 1} {r + 1} {add}");
                    ans = (ans + add) % M;
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