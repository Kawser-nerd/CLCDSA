using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program
{
    //otaku ha saiko~
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var s = sc.Scan();
            var hash = new Hashing(s);
            var id = Enumerate(n, x => x);
            Array.Sort(id, (l, r) =>
             {
                 return hash.CompConcat(l, n, r, n);
             });
            foreach (var x in id)
                IO.Printer.Out.WriteLine(x + 1);
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
#region Suffix Array
public class Hashing
{
    int n;
    string s;
    Random rand = new Random();
    const ulong band = 100007;
    const ulong MOD = (ulong)1e9 + 7;
    ulong[] pow, phash;
    public Hashing(string str)
    {
        s = str;
        n = s.Length;
        pow = new ulong[n + 1];
        phash = new ulong[n + 1];
        pow[0] = 1;
        for (int i = 0; i < n; i++)
        {
            phash[i + 1] = (s[i] + phash[i] * band);
            pow[i + 1] = (pow[i] * band);
        }
    }
    public ulong Hash(int l, int r)
    {
        return phash[r] - (phash[l] * pow[r - l]);
    }
    //s[il,ir)?s[jl,jr)?concat???????????????
    //weak strict order??????
    public int CompConcat(int i, int ir, int j, int jr)
    {
        var ls = Hash(i, ir) * pow[jr - j] + Hash(j, jr);
        var rs = Hash(j, jr) * pow[ir - i] + Hash(i, ir);
        if (ls == rs) return 0;

        var l = 0; var r = ir - i + jr - j + 1;
        while (l + 1 < r)
        {
            var m = (l + r) / 2;
            var lhash = i + m <= ir ? Hash(i, i + m) : Hash(i, ir) * pow[m - (ir - i)] + Hash(j, j + m - (ir - i));
            var rhash = j + m <= jr ? Hash(j, j + m) : Hash(j, jr) * pow[m - (jr - j)] + Hash(i, i + m - (jr - j));
            if (lhash == rhash) l = m;
            else r = m;
        }
        var lc = (i + l) < ir ? s[i + l] : s[j + l - (ir - i)];
        var rc = (j + l) < jr ? s[j + l] : s[i + l - (jr - j)];
        return lc.CompareTo(rc);
    }
    //s[il,ir]?s[jl,jr]???
    public int Comp(int il, int ir, int jl, int jr)
    {
        var lcp = LCP(il, jl);
        var min = Math.Min(ir - il, jr - jl);
        if (lcp >= min)
        {
            return (ir - il).CompareTo(jr - jl);
        }
        else
        {
            return s[il + min].CompareTo(s[jl + min]);
        }
    }
    public int LCP(int i, int j)
    {
        var l = 0; var r = Math.Min(n - i, n - j) + 1;
        while (l + 1 < r)
        {
            var m = (l + r) / 2;
            if (Hash(i, i + m) == Hash(j, j + m)) l = m;
            else r = m;
        }
        return l;
    }
    public int[] BuildSA()
    {
        var a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = i;
        Array.Sort(a, (l, r) =>
        {
            var lcp = LCP(l, r);
            return l + lcp >= n ? -1 : r + lcp >= n ? 1 : s[l + lcp].CompareTo(s[r + lcp]);
        });
        return a;
    }
}
#endregion