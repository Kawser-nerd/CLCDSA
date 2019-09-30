using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using Number = ModInt;
//using System.Numerics;
//using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            //?? x ??? v ???????????
            //?? v ??????? x ?????????????????
            //?? v ???????? x ????????????????
            //?????x-v ??????????????????
            //???????????? (x',v') ????? (p,q) ??? (p>x,q<v')
            //???????????? (x',v') ????? (p,q) ??? (p<x,q>v')
            //????? [l,r] ?????????
            //(??? l ??? x ?????????? min,r ??? x ?????????? max)


            var n = ri;
            var X = new int[n];
            var V = new int[n];
            for (int i = 0; i < n; i++)
            {
                X[i] = ri; V[i] = ri;
            }
            var xs = X.ToList(); xs.Sort();
            var vs = V.ToList(); vs.Sort();
            for (int i = 0; i < n; i++)
            {
                X[i] = xs.BinarySearch(X[i]);
                V[i] = vs.BinarySearch(V[i]) + 1;
            }
            Array.Sort(X, V);
            var L = new int[n];
            var R = new int[n];
            for (int i = 0; i < n; i++)
            {
                R[i] = V[i];
                if (i > 0) R[i] = Math.Max(R[i], R[i - 1]);
            }
            for (int i = n - 1; i >= 0; i--)
            {
                L[i] = V[i];
                if (i + 1 < n) L[i] = Math.Min(L[i], L[i + 1]);
            }

            var dp = new FenwickTree(n + 50);
            for (int i = 0; i < n; i++)
            {
                if (L[i] == 1) { dp.Add(R[i], 1 + dp[1, R[i]]); }
                else dp.Add(R[i], dp[L[i] - 1, R[i]]);
            }
            Console.WriteLine(dp[n, n]);
        }
        const long INF = 1L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
        const string URDL = "URDL";
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

#region Fenwick
public class FenwickTree {
    int n;
    Number[] bit;
    int max = 1;
    public FenwickTree(int size) {
        n = size; bit = new Number[n + 1];
        while ((max << 1) <= n) max <<= 1;
    }
    public Number this[int i, int j] { get { return this[j] - this[i - 1]; } }
    public Number this[int i] { get { Number s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; } }

    public void Add(int i, Number v) {
        if (i == 0) System.Diagnostics.Debug.Fail("BIT is 1 indexed");
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    public Number[] Items {
        get {
            var ret = new Number[n + 1];
            for (int i = 0; i < ret.Length; i++)
                ret[i] = this[i, i];
            return ret;
        }
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