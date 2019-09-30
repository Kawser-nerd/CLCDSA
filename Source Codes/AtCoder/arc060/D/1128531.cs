using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Number = System.Int64;

namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var s = sc.Scan();
            var n = s.Length;
            if (n == 1)
            {
                IO.Printer.Out.WriteLine(1);
                IO.Printer.Out.WriteLine(1);
            }
            else
            {
                var t = 1;
                for (; t < n; t++)
                {
                    if (n % t != 0) continue;
                    var ok = true;
                    for (int i = 0; i + t < n; i++)
                        if (s[i] != s[i + t]) { ok = false; break; }

                    if (ok) break;
                }
                var per = Enumerate(2, x => new bool[n + 1]);
                for (int i = 0; i < 2; i++)
                {
                    var a = StringEx.ZAlgorithm(s);
                    for (int d = 1; d <= n; d++)
                    {
                        for (int p = d; p < n; p += d)
                        {
                            if (a[p] < d) break;
                            if (p + d <= n)
                                per[i][p + d] = true;
                        }
                    }
                    s = s.Reverse().AsString();
                }
                Array.Reverse(per[1]);
                if (t == n)
                {
                    IO.Printer.Out.WriteLine(1);
                    IO.Printer.Out.WriteLine(1);

                }
                else if (t == 1)
                {
                    IO.Printer.Out.WriteLine(n);
                    IO.Printer.Out.WriteLine(1);
                }
                else
                {
                    var ans = 0;
                    IO.Printer.Out.WriteLine(2);
                    for (int i = 0; i <= n; i++)
                        if (!per[0][i] && !per[1][i]) ans++;
                    IO.Printer.Out.WriteLine(ans);
                }
            }


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
#region Z Algorithm
static public partial class StringEx
{
    /// <summary>???????????????????????????????O(|S|)</summary>
    static public int[] ZAlgorithm(string s)
    {
        var a = new int[s.Length + 1];
        a[0] = s.Length;
        int i = 1, j = 0;
        while (i < s.Length)
        {
            while (i + j < s.Length && s[j] == s[i + j]) ++j;
            a[i] = j;
            if (j == 0) { ++i; continue; }
            int k = 1;
            while (i + k < s.Length && k + a[k] < j) { a[i + k] = a[k]; ++k; }
            i += k; j -= k;
        }
        return a;
    }
    /// <summary>s??????????????t?????????????????????O(|S|)</summary>
    /// <returns>ret[i]=i??????????????t???????????????</returns>
    static public int[] ZAlgorithm(string s, string t)
    {
        var ns = t + s;
        /*
        var ns = new int[t.Length + s.Length];
        for (int i = 0; i < t.Length; i++)
            ns[i] = t[i];
        for (int i = 0; i < s.Length; i++)
            ns[i + t.Length] = s[i];
        //*/
        var res = ZAlgorithm(ns);
        var ret = new int[s.Length + 1];
        for (int i = t.Length; i < res.Length; i++)
            ret[i - t.Length] = res[i];
        return ret;


    }
}
#endregion