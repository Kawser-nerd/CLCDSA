using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Boolean;
namespace Program
{
    public class Solver
    {

        public void Solve()
        {
            var n = sc.Integer();
            var k = sc.Integer();
            var a = sc.Integer(n);
            Array.Sort(a);

            var ans = 0;
            var seg = new SegmentTree(n, k, a);
            for (int i = 0; i < n; i++)
            {
                var ret = seg.data[i + seg.n];
                var ok = false;
                for (int j = 0; j < k; j++)
                {
                    if (ret[j] && j + a[i] >= k)
                        ok = true;
                }
                if (!ok)
                {
                    Debug.WriteLine(i);
                    ans++;
                }
            }
            IO.Printer.Out.WriteLine(ans);
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
#region KnapsackSegmentTere
[System.Diagnostics.DebuggerDisplay("Data={ToString()}")]
public class SegmentTree
{
    public int n;
    public Number[][] data;
    int[] L, R;
    static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }


    public SegmentTree(int size, int m, int[] a)
    {
        n = 1;
        while (n < size)
            n <<= 1;
        data = new Number[n << 1][];
        data[1] = new Number[m + 1];
        data[1][0] = true;
        L = new int[n << 1];
        L[1] = 0;
        R = new int[n << 1];
        R[1] = n;
        for (int _ = 1; _ < n; _++)
        {
            {
                L[_ << 1] = L[_];
                R[(_ << 1)] = L[(_ << 1) + 1] = (L[_] + R[_]) >> 1;
                R[(_ << 1) + 1] = R[_];
            }

            {
                var l = L[(_ << 1) + 1]; var r = Math.Min(size, R[(_ << 1) + 1]);
                var ret = data[_].ToArray();
                for (int k = l; k < r; k++)
                {
                    var v = a[k];
                    for (int j = m - v; j >= 0; j--)
                    {
                        if (!ret[j]) continue;
                        ret[j + v] |= ret[j];
                    }
                }
                data[_ << 1] = ret;
            }
            {
                var l = L[(_ << 1)]; var r = Math.Min(size, R[(_ << 1)]);
                var ret = data[_];
                for (int k = l; k < r; k++)
                {
                    var v = a[k];
                    for (int j = m - v; j >= 0; j--)
                    {
                        if (!ret[j]) continue;
                        ret[j + v] |= ret[j];
                    }
                }
                data[(_ << 1) + 1] = ret;
            }

        }
    }
}
#endregion