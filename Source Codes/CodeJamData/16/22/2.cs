using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Double;
using _ANSWER = Triplet<long, string, string>;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var T = sc.Integer();
            var ans = new _ANSWER[T];
            var f = new Func<_ANSWER>[T];
            for (int _ = 0; _ < T; _++)
            {
                var s = sc.Scan();
                var t = sc.Scan();
                f[_] = () => solve(s, t);
                ans[_] = f[_]();
            }
            //System.Threading.Tasks.Parallel.For(0, T, i => ans[i] = f[i]());
            for (int i = 0; i < T; i++)
            {
                IO.Printer.Out.WriteLine($"Case #{i + 1}: {ans[i].J} {ans[i].K}");
            }
        }
        private _ANSWER solve(string s, string t)
        {
            var ans = new Triplet<long, long, long>(long.MaxValue, long.MaxValue, long.MaxValue);

            //0: s>t
            //1: s=t
            //1: t<s
            var dp = Enumerate(3, x => new Triplet<long, long, long>(long.MaxValue, 0, 0));
            dp[1].I = 0;
            for (int i = 0; i < s.Length; i++)
            {
                var next = Enumerate(3, x => new Triplet<long, long, long>(long.MaxValue, 0, 0));

                for (int u = 0; u < 10; u++)
                {
                    if (s[i] != u + '0' && s[i] != '?') continue;
                    for (int v = 0; v < 10; v++)
                    {
                        if (t[i] != v + '0' && t[i] != '?') continue;
                        if (u < v)
                        {
                            for (int k = 0; k < 3; k++)
                            {
                                long d;
                                int to;
                                Triplet<long, long, long> neq;
                                if (k == 0)
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = dp[k].I * 10 - Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 0;
                                }
                                else if (k == 1)
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 2;
                                }
                                else
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = dp[k].I * 10 + Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 2;
                                }
                                next[to] = Triplet.Min(next[to], neq);
                            }


                        }
                        else if (u == v)
                        {
                            for (int k = 0; k < 3; k++)
                            {
                                long d;
                                int to;
                                Triplet<long, long, long> neq;
                                if (k == 0)
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = dp[k].I * 10 - Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 0;
                                }
                                else if (k == 1)
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 1;
                                }
                                else
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = dp[k].I * 10 + Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 2;
                                }
                                next[to] = Triplet.Min(next[to], neq);
                            }

                        }
                        else
                        {
                            for (int k = 0; k < 3; k++)
                            {
                                long d;
                                int to;
                                Triplet<long, long, long> neq;
                                if (k == 0)
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = dp[k].I * 10 + Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 0;
                                }
                                else if (k == 1)
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 0;
                                }
                                else
                                {
                                    if (dp[k].I == long.MaxValue) continue;
                                    d = dp[k].I * 10 - Math.Abs(v - u);
                                    neq = new Triplet<long, long, long>(d, dp[k].J * 10 + u, dp[k].K * 10 + v);
                                    to = 2;
                                }
                                next[to] = Triplet.Min(next[to], neq);
                            }

                        }
                    }
                }
                dp = next;
            }
            for (int i = 0; i < 3; i++)
                ans = Triplet.Min(ans, dp[i]);
            var a = new List<long>();
            var b = new List<long>();
            for (int i = 0; i < s.Length; i++)
            {
                a.Add(ans.J % 10);
                b.Add(ans.K % 10);
                ans.J /= 10;
                ans.K /= 10;
            }
            a.Reverse();b.Reverse();
            return new _ANSWER(ans.I, a.AsJoinedString(""), b.AsJoinedString(""));
        }
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
    public class Printer : StreamWriter
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
#region Triplet<ST,FT,TT>
static public class Triplet
{
    static public Triplet<FT, ST, TT> Create<FT, ST, TT>(FT f, ST s, TT t)
        where FT : IComparable<FT>
        where ST : IComparable<ST>
        where TT : IComparable<TT>
    { return new Triplet<FT, ST, TT>(f, s, t); }

    static public Triplet<FT, ST, TT> Max<FT, ST, TT>(Triplet<FT, ST, TT> p, Triplet<FT, ST, TT> q)
        where FT : IComparable<FT>
        where ST : IComparable<ST>
        where TT : IComparable<TT>
    {
        return p.CompareTo(q) >= 0 ? p : q;
    }
    static public Triplet<FT, ST, TT> Min<FT, ST, TT>(Triplet<FT, ST, TT> p, Triplet<FT, ST, TT> q)
        where FT : IComparable<FT>
        where ST : IComparable<ST>
        where TT : IComparable<TT>
    {
        return p.CompareTo(q) <= 0 ? p : q;
    }
}
public struct Triplet<FT, ST, TT> : IComparable<Triplet<FT, ST, TT>>
    where FT : IComparable<FT>
    where ST : IComparable<ST>
    where TT : IComparable<TT>
{
    public FT I;
    public ST J;
    public TT K;
    public Triplet(FT i, ST j, TT k) : this() { I = i; J = j; K = k; }
    public int CompareTo(Triplet<FT, ST, TT> other)
    {
        var cmp = I.CompareTo(other.I);
        if (cmp != 0) return cmp;
        cmp = J.CompareTo(other.J);
        if (cmp != 0) return cmp;
        return K.CompareTo(other.K);
    }
    public override string ToString() { return string.Format("{0} {1} {2}", I, J, K); }
}
#endregion