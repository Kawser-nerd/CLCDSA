using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = System.Int64;
using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var s = rs;
            //s = new string('?', 300000);
            var dp = new ModInt[4, 5];
            //prefix ? '1' ? i ??suffix ? '0' ? j ?
            dp[0, 0] = 1;
            foreach (var x in s)
            {
                var next = new ModInt[4, 5];
                if (x == '0' || x == '?')
                {
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 3; j++)
                        {
                            var nj = j + 1;
                            if (nj == 3) nj = 1;
                            next[i, nj] += dp[i, j];

                        }
                }
                if (x == '1' || x == '?')
                {
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 3; j++)
                        {
                            var ni = i;
                            var nj = j;
                            if (j == 0) { ni = Min(3, i + 1); }
                            else { nj--; }
                            next[ni, nj] += dp[i, j];
                        }
                }
                dp = next;
            }
            ModInt ans = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                    if (i > j) ans += dp[i, j];
            Console.WriteLine(ans);
        }
        const long INF = 1L << 60;
        //static int[] dx = { -1, 0, 1, 0 };
        //static int[] dy = { 0, 1, 0, -1 };

        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex {
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
        return string.Join(st, ie);
    }
    static public void Main() {
        Console.SetOut(new Program.IO.Printer(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        try
        {
            solver.Solve();
            Console.Out.Flush();
        }
        catch { }
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer: StreamWriter {
        public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public bool IsEndOfStream { get { return isEof; } }

        private byte read() {
            if (isEof) return 0;
            if (ptr >= len)
            {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0)
                {
                    isEof = true;
                    return 0;
                }
            }
            return buf[ptr++];
        }

        public char Char() {
            byte b = 0;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan() {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read()) sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine() {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n' && b != 0; b = (char)read()) if (b != '\r') sb.Append(b);
            return sb.ToString();
        }
        public long Long() { return isEof ? long.MinValue : long.Parse(Scan()); }
        public int Integer() { return isEof ? int.MinValue : int.Parse(Scan()); }
        public double Double() { return isEof ? double.NaN : double.Parse(Scan(), CultureInfo.InvariantCulture); }
    }
}

#endregion
#region ModInt
public struct ModInt {
    public const long Mod = (int)1e9 + 7;

    public long num;
    public ModInt(long n) { num = n; }
    public override string ToString() { return num.ToString(); }
    public static ModInt operator +(ModInt l, ModInt r) { l.num += r.num; if (l.num >= Mod) l.num -= Mod; return l; }
    public static ModInt operator -(ModInt l, ModInt r) { l.num -= r.num; if (l.num < 0) l.num += Mod; return l; }
    public static ModInt operator *(ModInt l, ModInt r) { return new ModInt(l.num * r.num % Mod); }
    public static implicit operator ModInt(long n) { n %= Mod; if (n < 0) n += Mod; return new ModInt(n); }

    public static ModInt Pow(ModInt v, long k) { return Pow(v.num, k); }

    public static ModInt Pow(long v, long k) {
        long ret = 1;
        for (k %= Mod - 1; k > 0; k >>= 1, v = v * v % Mod)
            if ((k & 1) == 1) ret = ret * v % Mod;
        return new ModInt(ret);
    }
    public static ModInt Inverse(ModInt v) { return Pow(v, Mod - 2); }
}
#endregion
#region Binomial Coefficient
public class BinomialCoefficient {
    public ModInt[] fact, ifact;
    public BinomialCoefficient(int n) {
        fact = new ModInt[n + 1];
        ifact = new ModInt[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i;
        ifact[n] = ModInt.Inverse(fact[n]);
        for (int i = n - 1; i >= 0; i--)
            ifact[i] = ifact[i + 1] * (i + 1);
        ifact[0] = ifact[1];
    }
    public ModInt this[int n, int r] {
        get {
            if (n < 0 || n >= fact.Length || r < 0 || r > n) return 0;
            return fact[n] * ifact[n - r] * ifact[r];
        }
    }
    public ModInt RepeatedCombination(int n, int k) {
        if (k == 0) return 1;
        return this[n + k - 1, k];
    }
}
#endregion