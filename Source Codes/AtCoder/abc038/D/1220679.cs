using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var a = new int[n];
            var b = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = sc.Integer();
                b[i] = sc.Integer();
            }
            var id = Enumerate(n, x => x);
            Array.Sort(id, (l, r) =>
             {
                 var cmp = a[l].CompareTo(a[r]);
                 if (cmp != 0) return cmp;
                 return b[r].CompareTo(b[l]);
             });
            var lis = Enumerate(n + 5, x => 1000000000);
            foreach (var x in id)
            {
                Debug.WriteLine(lis.AsJoinedString());
                var y = b[x];
                var ub = Algorithm.LowerBound(lis, y);
                lis[ub] = y;
            }
            Debug.WriteLine(lis.AsJoinedString());
            IO.Printer.Out.WriteLine(Algorithm.LowerBound(lis, 1000000000));

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



#region BinarySearch
/*
static public partial class Algorithm
{
    static int binarySearch<T, V>(this T a, V v, IComparer<V> cmp, bool islb)
        where T : IList<V>
    {
        var l = 0;
        var r = a.Count;
        while (l <= r)
        {
            var m = (l + r) / 2;
            var res = cmp.Compare(a[m], v);
            if (res < 0 || (res == 0 && !islb)) l = m + 1;
            else r = m - 1;
        }
        return l;
    }

    static public int LowerBound<T, V>(this T a, V v, IComparer<V> cmp) where T : IList<V> { return binarySearch(a, v, cmp, true); }
    static public int LowerBound<T, V>(this T a, V v, Comparison<V> cmp) where T : IList<V> { return binarySearch(a, v, Comparer<V>.Create(cmp), true); }
    static public int LowerBound<T, V>(this T a, V v) where T : IList<V> where V : IComparable<V> { return binarySearch(a, v, Comparer<V>.Default, true); }
    static public int UpperBound<T, V>(this T a, V v, IComparer<V> cmp) where T : IList<V> { return binarySearch(a, v, cmp, false); }
    static public int UpperBound<T, V>(this T a, V v, Comparison<V> cmp) where T : IList<V> { return binarySearch(a, v, Comparer<V>.Create(cmp), false); }
    static public int UpperBound<T, V>(this T a, V v) where T : IList<V> where V : IComparable<V> { return binarySearch(a, v, Comparer<V>.Default, false); }

}
*/
#endregion
#region BinarySearch for List
static public partial class Algorithm
{

    static private int binarySearch<T>(this IList<T> a, int idx, int len, T v, Comparison<T> cmp, bool islb)
    {
        var l = 0;
        var r = a.Count;
        while (l <= r)
        {
            var m = (l + r) / 2;
            var res = cmp(a[m], v);
            if (res < 0 || (res == 0 && !islb)) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
    static public int UpperBound<T>(this IList<T> a, int idx, int len, T v, Comparison<T> cmp) { return binarySearch(a, idx, len, v, cmp, false); }
    static public int UpperBound<T>(this IList<T> a, int idx, int len, T v) where T : IComparable<T> { return UpperBound(a, idx, len, v, Comparer<T>.Default.Compare); }
    static public int UpperBound<T>(this IList<T> a, T v) where T : IComparable<T> { return UpperBound(a, 0, a.Count, v, Comparer<T>.Default.Compare); }
    static public int UpperBound<T>(this IList<T> a, T v, IComparer<T> cmp) { return UpperBound(a, 0, a.Count, v, cmp.Compare); }
    static public int UpperBound<T>(this IList<T> a, T v, Comparison<T> cmp) { return UpperBound(a, 0, a.Count, v, cmp); }

    static public int LowerBound<T>(this IList<T> a, int idx, int len, T value, Comparison<T> cmp) { return binarySearch(a, idx, len, value, cmp, true); }
    static public int LowerBound<T>(this IList<T> a, int idx, int len, T value) where T : IComparable<T> { return LowerBound(a, idx, len, value, Comparer<T>.Default.Compare); }
    static public int LowerBound<T>(this IList<T> a, T val) where T : IComparable<T> { return LowerBound(a, 0, a.Count, val, Comparer<T>.Default.Compare); }
    static public int LowerBound<T>(this IList<T> a, T val, IComparer<T> cmp) { return LowerBound(a, 0, a.Count, val, cmp.Compare); }
    static public int LowerBound<T>(this IList<T> a, T v, Comparison<T> cmp) { return LowerBound(a, 0, a.Count, v, cmp); }
}
#endregion