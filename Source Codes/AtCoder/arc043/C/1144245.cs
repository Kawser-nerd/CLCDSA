#define A
using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int32;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var a = sc.Integer(n);
            var b = sc.Integer(n);
            var ord = new int[n];
            var rev = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i]--;
                b[i]--;
                ord[a[i]] = i;
                rev[i] = a[i];
            }
            for (int i = 0; i < n; i++)
                b[i] = ord[b[i]];
            var inversion = getinversion(b);
            Debug.WriteLine(inversion);
            if (inversion % 2 == 1)
            {
                IO.Printer.Out.WriteLine(-1);
                return;
            }
            var ans = get(b, inversion / 2);
            Debug.WriteLine(getinversion(ans));
            for (int i = 0; i < n; i++)
                ans[i] = rev[ans[i]] + 1;
            IO.Printer.Out.WriteLine(ans.AsJoinedString());
        }
        long getinversion(int[] a)
        {
            var n = a.Length;
            long ret = 0;
            var fenwick = new FenwickTree(n);
            for (int i = 1; i <= n; i++)
                fenwick.Add(i, 1);
            foreach (var x in a)
            {
                var y = x + 1;
                fenwick.Add(y, -1);
                ret += fenwick[y];
            }
            return ret;
        }
        int[] get(int[] a, long inv)
        {
            var n = a.Length;
            var pos = new int[n];
            for (int i = 0; i < n; i++)
                pos[a[i]] = i;
            var fenwick = new FenwickTree(n);
            for (int i = 1; i <= n; i++)
                fenwick.Add(i, 1);
            var ret = new int[n];
            var ptr = n - 1;
            var used = new bool[n];
            for (int i = n - 1; i >= 0; i--)
            {
                var p = pos[i];
                fenwick.Add(p + 1, -1);
                var v = fenwick[p + 1, n];
                if (inv >= v)
                {
                    inv -= v;
                    used[p] = true;
                    ret[ptr--] = i;
                }
                else break;
            }
            ptr = 0;
            for (int i = 0; i < n; i++)
            {
                if (used[i]) continue;
                ret[ptr++] = a[i];
            }
            for (int i = 0; i + 1 < n && inv > 0; i++)
            {
                if (ret[i] > ret[i + 1]) { Swap(ref ret[i], ref ret[i + 1]); inv--; }
            }
            return ret;
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
#region FenwickTree
public class FenwickTree
{
    int n;
    Number[] bit;
    int max = 1;
    public FenwickTree(int size)
    {
        n = size; bit = new Number[n + 1];
        while ((max << 1) <= n) max <<= 1;
    }
    /// <summary>sum[a,b]</summary>
    public Number this[int i, int j] { get { return this[j] - this[i - 1]; } }
    /// <summary>sum[0,i]</summary>
    public Number this[int i] { get { Number s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; } }
    public int LowerBound(Number w)
    {
        if (w <= 0) return 0;
        int x = 0;
        for (int k = max; k > 0; k >>= 1)
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        return x + 1;
    }
    /// <summary>add v to bit[i]</summary>
    public void Add(int i, Number v)
    {
        if (i == 0) System.Diagnostics.Debug.Fail("BIT is 1 indexed");
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    public Number[] Items
    {
        get
        {
            var ret = new Number[n + 1];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = this[i, i];
            return ret;
        }
    }
}
#endregion