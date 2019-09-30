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
            var A = new int[n];
            var B = new int[n];
            const int ADD = 2100;
            var dp = Enumerate(4200, x => new ModInteger[4200]);
            for (int i = 0; i < n; i++)
            {
                A[i] = sc.Integer();
                B[i] = sc.Integer();
                dp[ADD - A[i]][ADD - B[i]] += 1;
            }
            for (int i = 1; i < 4200; i++)
                for (int j = 1; j < 4200; j++)
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            ModInteger sum = 0;
            for (int i = 0; i < n; i++)
                sum += dp[ADD + A[i]][ADD + B[i]];


            var fact = new ModInteger[8200];
            var inv = new ModInteger[8200];
            fact[0] = inv[0] = 1;
            for (int i = 1; i < 8200; i++)
            {
                fact[i] = fact[i - 1] * i;
                inv[i] = ModInteger.Inverse(fact[i]);
            }
            for (int i = 0; i < n; i++)
                sum -= fact[2 * A[i] + 2 * B[i]] * inv[2 * A[i]] * inv[2 * B[i]];


            sum *= ModInteger.Inverse(2);
            IO.Printer.Out.WriteLine(sum);


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
#region Inverse
public partial struct ModInteger
{
    static public ModInteger Inverse(ModInteger v)
    {
        long p, q;
        ExGCD(v.num, Mod, out p, out q);
        return new ModInteger(p % Mod + Mod);
    }
    static public long ExGCD(long a, long b, out long x, out long y)
    {
        var u = new long[] { a, 1, 0 };
        var v = new long[] { b, 0, 1 };
        while (v[0] != 0)
        {
            var t = u[0] / v[0];
            for (int i = 0; i < 3; i++)
            {
                var tmp = u[i] - t * v[i];
                u[i] = v[i];
                v[i] = tmp;
            }
        }
        x = u[1];
        y = u[2];
        if (u[0] > 0)
            return u[0];
        for (int i = 0; i < 3; i++)
            u[i] = -u[i];
        return u[0];

    }
}
#endregion
#region ModTable
public class ModTable
{
    public ModInteger[] perm, inv;
    public ModTable(int n)
    {
        perm = new ModInteger[n + 1];
        inv = new ModInteger[n + 1];
        perm[0] = 1;
        for (int i = 1; i <= n; i++)
            perm[i] = perm[i - 1] * i;
        inv[n] = ModInteger.Inverse(perm[n]);
        for (int i = n - 1; i >= 0; i--)
            inv[i] = inv[i + 1] * (i + 1);
        inv[0] = inv[1];
    }
    public ModInteger Inverse(int k) { return inv[k]; }
    public ModInteger Permutation(int n, int k)
    {
        if (n < 0 || n >= perm.Length)
            return 0;
        if (k < 0 || k >= n)
            return 0;
        return perm[n] * inv[n - k];
    }
    public ModInteger Combination(int n, int r)
    {
        if (n < 0 || n >= perm.Length || r < 0 || r > n) return 0;
        return perm[n] * inv[n - r] * inv[r];
    }
    public ModInteger RepeatedCombination(int n, int k)
    {
        if (k == 0) return 1;
        return Combination(n + k - 1, k);
    }
}
#endregion