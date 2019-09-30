using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
//using System.Numerics;
using static System.Math;
//using static MathEx;
using P = System.Collections.Generic.KeyValuePair<int, int>;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = ri;
            var G = Enumerate(n, x => new List<int>());
            for (int i = 0; i < n - 1; i++)
            {
                var f = ri - 1;
                var t = ri - 1;
                G[f].Add(t);
                G[t].Add(f);
            }
            var s = rs;
            long ans = f(n, G, s);
            Debug.WriteLine("go");
            for (int i = 0; i < n; i++)
            {
                ans += Max(0, dp[i].secd - dp[i].minx + 1);
                //Debug.WriteLine("{0} {1} {2}", i, dp[i].minx, dp[i].secd);
            }
            IO.Printer.Out.WriteLine(ans);
        }
        DP[] dp;
        int f(int n, List<int>[] G, string s)
        {
            dp = new DP[n];
            DP.New = () =>
            {
                var ret = new DP();
                ret.maxd = ret.secd = -100000;
                ret.minx = 1000000000;
                return ret;
            };
            DP.Merge = (l, r, rst) =>
            {
                var ret = new DP();
                ret.maxd = l.maxd;
                ret.secd = l.secd;
                ret.minx = l.minx;
                if (ret.maxd < r.maxd) { ret.secd = ret.maxd; ret.maxd = r.maxd; }
                else if (ret.secd < r.maxd) ret.secd = r.maxd;
                if (r.maxd >= 0 && r.minx < 1000000000)
                    ret.minx = Min(l.minx, r.maxd);
                return ret;
            };
            DP.Root = val =>
            {
                var ret = new DP();
                ret.maxd = Max(0, val.maxd + 1);
                ret.secd = Max(0, val.secd + 1);
                ret.minx = val.minx + 1;
                return ret;
            };
            Func<int, int, DP> dfs = null;
            dfs = (prev, cur) =>
            {
                var ret = DP.New();
                foreach (var to in G[cur])
                    if (prev != to) ret += dfs(cur, to);
                dp[cur] = !ret;
                if (s[cur] == '1') dp[cur].minx = 0;
                return dp[cur];
            };
            dfs(-1, 0);
            var ans = 0;
            var rdp = Enumerate(n, x => new DP[G[x].Count + 1]);
            dfs = (prev, cur) =>
            {

                var ret = DP.New();
                var k = G[cur].Count;
                rdp[cur][k] = DP.New();
                for (int i = k - 1; i >= 0; i--)
                    rdp[cur][i] = rdp[cur][i + 1] + dp[G[cur][i]];
                for (int i = 0; i < k; i++)
                {
                    var to = G[cur][i];
                    var pre = dp[to];
                    dp[cur] = !(ret * rdp[cur][i + 1]);
                    if (s[cur] == '1') dp[cur].minx = 0;
                    ret += dp[to];
                    if (prev != to)
                    {
                        var min = Min(dp[cur].maxd, dp[to].maxd);
                        var ok = false;
                        if (dp[cur].maxd == min && dp[cur].minx < min + 1) ok = true;
                        if (dp[to].maxd == min && dp[to].minx < min + 1) ok = true;
                        if (ok)
                        {
                            //Debug.WriteLine("{0} {1}", cur, to);
                            ans++;
                        }
                        dfs(cur, to);
                    }
                }
                dp[cur] = !ret;
                if (s[cur] == '1') dp[cur].minx = 0;
                return dp[cur];
            };
            dfs(-1, 0);
            return ans;
        }
        //*
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        char rc => sc.Char();

        [System.Diagnostics.Conditional("DEBUG")]
        void put(params object[] a) => Debug.WriteLine(string.Join(" ", a));
        //*/
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex
{
    static public string AsString(this IEnumerable<char> ie) { return new string(System.Linq.Enumerable.ToArray(ie)); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") { return string.Join(st, ie); }
    static public void Main()
    {
        var solver = new Program.Solver();
        solver.Solve();
        Program.IO.Printer.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO
{
    using System.IO;
    using System.Text;
    using System.Globalization;
    public class Printer: StreamWriter
    {
        static Printer() { Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false }; }
        public static Printer Out { get; set; }
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(System.IO.Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
        public Printer(System.IO.Stream stream, Encoding encoding) : base(stream, encoding) { }
        public void Write<T>(string format, T[] source) { base.Write(format, source.OfType<object>().ToArray()); }
        public void WriteLine<T>(string format, T[] source) { base.WriteLine(format, source.OfType<object>().ToArray()); }
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
            if (ptr >= len) { ptr = 0; if ((len = str.Read(buf, 0, 1024)) <= 0) { isEof = true; return 0; } }
            return buf[ptr++];
        }
        public char Char() { byte b = 0; do b = read(); while ((b < 33 || 126 < b) && !isEof); return (char)b; }

        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n'; b = (char)read())
                if (b == 0) break;
                else if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { var s = Scan(); return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN; }
        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n) { return enumerate(n, Char); }
        public string[] Scan(int n) { return enumerate(n, Scan); }
        public double[] Double(int n) { return enumerate(n, Double); }
        public int[] Integer(int n) { return enumerate(n, Integer); }
        public long[] Long(int n) { return enumerate(n, Long); }
    }
}
#endregion

public struct DP
{
    public int maxd;
    public int secd;
    public int minx;
    //???????
    public static Func<DP> New;
    /// <summary>
    /// 2??????????true???????
    /// </summary>
    public static Func<DP, DP, bool, DP> Merge;
    /// <summary>
    /// ?????
    /// </summary>
    public static Func<DP, DP> Root;

    public static DP operator +(DP l, DP r) { return Merge(l, r, true); }
    public static DP operator *(DP l, DP r) { return Merge(l, r, false); }
    public static DP operator !(DP x) { return Root(x); }
}