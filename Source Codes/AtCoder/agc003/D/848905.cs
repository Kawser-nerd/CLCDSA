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
            var n = sc.Integer();
            var a = sc.Long(n);
            const long INF = 10000000001;
            var primes = MathEx.Sieve(220000);
            var pp = MathEx.SieveList(2200);
            foreach (long p in pp)
                for (int i = 0; i < n; i++)
                    while (a[i] % (p * p * p) == 0) { a[i] /= p * p * p; }
            Debug.WriteLine(a.AsJoinedString());

            var xs = a.Distinct().ToList(); xs.Sort();
            var m = xs.Count;
            var cnt = new int[m];
            var used = new bool[m];
            for (int i = 0; i < n; i++)
                cnt[xs.BinarySearch(a[i])]++;

            var ans = 0;
            for (int i = 0; i < m; i++)
            {
                if (xs[i] == 1) { ans++; used[i] = true; }
                if (used[i]) continue;
                used[i] = true;

                var x = xs[i];
                var y = 1L;
                foreach (long p in pp)
                {
                    if (x % (p * p) == 0) { x /= (p * p); y = Math.Min(INF, y * p); }
                    else if (x % p == 0) { x /= p; y = Math.Min(INF, y * p); y = Math.Min(INF, y * p); }
                }
                if (x != 1)
                {
                    if (x < 200000 && primes[x]) { y = Math.Min(INF, y * x); y = Math.Min(INF, y * x); }
                    else y = INF;
                }
                var pos = xs.BinarySearch(y);
                if (pos < 0) ans += cnt[i];
                else { ans += Math.Max(cnt[i], cnt[pos]); used[pos] = true; }
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
#region sieve
static public partial class MathEx
{
    static public bool[] Sieve(int p)
    {
        var isPrime = new bool[p + 1];
        for (int i = 2; i <= p; i++) isPrime[i] = true;
        for (int i = 2; i * i <= p; i++)
            if (!isPrime[i]) continue;
            else
                for (int j = i * i; j <= p; j += i)
                    isPrime[j] = false;
        return isPrime;
    }
}
#endregion
#region sieve list
static public partial class MathEx
{
    static public List<int> SieveList(int p)
    {
        var isPrime = new bool[p + 1];
        for (int i = 2; i <= p; i++)
            isPrime[i] = true;
        for (int i = 2; i * i <= p; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j <= p; j += i)
                isPrime[j] = false;
        }
        var ret = new List<int>();
        for (int i = 0; i <= p; i++) if (isPrime[i]) ret.Add(i);
        return ret;
    }
}
#endregion