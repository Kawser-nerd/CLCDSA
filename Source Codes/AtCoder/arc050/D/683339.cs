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
            var sa = hash.BuildSA();
            foreach (var x in sa)
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
#region gcd,lcm
static public partial class MathEx
{

    static public BigInteger GCD(BigInteger x, BigInteger y)
    {
        byte i = 0;
        while (x != 0 && y != 0)
        {
            if (i == 0)
                y %= x;
            else x %= y;
            i ^= 1;
        }
        return x == 0 ? y : x;
    }
    static public BigInteger LCM(BigInteger x, BigInteger y)
    {
        return (x / GCD(x, y)) * y;
    }

}
#endregion
#region ModNumber
public partial struct ModInteger
{
    public const long Mod = (long)1e9 + 7;
    public long num;
    public ModInteger(long n) : this() { num = n % Mod; if (num < 0) num += Mod; }
    public override string ToString() { return num.ToString(); }
    public static ModInteger operator +(ModInteger l, ModInteger r) { var n = l.num + r.num; if (n >= Mod) n -= Mod; return new ModInteger() { num = n }; }
    public static ModInteger operator -(ModInteger l, ModInteger r) { var n = l.num + Mod - r.num; if (n >= Mod) n -= Mod; return new ModInteger() { num = n }; }
    public static ModInteger operator *(ModInteger l, ModInteger r) { return new ModInteger(l.num * r.num); }
    public static ModInteger operator ^(ModInteger l, long r) { return ModInteger.Pow(l, r); }
    public static implicit operator ModInteger(long n) { return new ModInteger(n); }
    public static ModInteger Pow(ModInteger v, long k)
    {
        ModInteger ret = 1;
        var n = k;
        for (; n > 0; n >>= 1, v *= v)
        {
            if ((n & 1) == 1)
                ret = ret * v;
        }
        return ret;
    }
}
#endregion

#region Suffix Array
public class Hashing
{
    int n;
    string s;
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
    public int comp(int i, int j)
    {
        var ls = Hash(i, n) * pow[n - j] + Hash(j, n);
        var rs = Hash(j, n) * pow[n - i] + Hash(i, n);
        if (ls == rs) return 0;

        var l = 0; var r = n - i + n - j + 1;
        while (l + 1 < r)
        {
            var m = (l + r) / 2;
            var lhash = i + m <= n ? Hash(i, i + m) : Hash(i, n) * pow[m - (n - i)] + Hash(j, j + m - (n - i));
            var rhash = j + m <= n ? Hash(j, j + m) : Hash(j, n) * pow[m - (n - j)] + Hash(i, i + m - (n - j));
            if (lhash == rhash) l = m;
            else r = m;
        }
        var lc = (i + l) < n ? s[i + l] : s[j + l - (n - i)];
        var rc = (j + l) < n ? s[j + l] : s[i + l - (n - j)];
        return lc.CompareTo(rc);
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
            return comp(l, r);
        });
        return a;
    }
}
#endregion