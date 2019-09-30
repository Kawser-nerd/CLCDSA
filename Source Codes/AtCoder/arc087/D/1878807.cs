using System;
using System.Collections.Generic;
using System.Linq;
using Debug = System.Diagnostics.Debug;
using System.Numerics;
using static System.Math;
using Number = System.Int64;
namespace Program {
    public class Solver {

        public void Solve() {
            var n = ri;
            var par = new int[n];
            var G = Enumerate(n, x => new List<int>());
            for (int i = 0; i < n - 1; i++) {
                var f = ri - 1;
                var t = ri - 1;
                G[f].Add(t); G[t].Add(f);
            }
            var comb = new Comb(n + 50);
            var size = new int[n];
            Func<int, int, int> dfs = null;
            dfs = (prev, cur) => {
                var ret = 1;
                par[cur] = prev;
                foreach (var t in G[cur])
                    if (t != prev) ret += dfs(cur, t);

                return size[cur] = ret;
            };
            dfs(-1, 0);
            var id = -1;
            var ma = 1000000000;
            for (int i = 0; i < n; i++) {
                if (size[i] * 2 == n) {
                    Console.WriteLine(comb.fact[n / 2] * comb.fact[n / 2]);
                    return;
                }
                var max = n - size[i];
                foreach (var t in G[i])
                    if (t != par[i]) max = Max(max, size[t]);
                if (max < ma) { ma = max; id = i; }
            }
            Debug.WriteLine(id);
            var dp = new ModInt[n + 1];
            dp[0] = 1;
            var cnt = 0;
            foreach (var t in G[id]) {
                var sz = t == par[id] ? n - size[id] : size[t];
                var next = new ModInt[n + 1];
                for (int i = 0; i <= cnt; i++)
                    if (dp[i].num != 0) {
                        for (int j = 0; j <= sz; j++)
                            next[i + j] += dp[i] * comb[sz, j] * comb.fact[sz] * comb.ifact[sz - j];
                    }
                Debug.WriteLine(sz);
                cnt += sz;
                dp = next;
                Debug.WriteLine(dp.AsJoinedString());
            }
            for (int i = 0; i < n; i++)
                dp[i] *= comb.fact[n - 1 - i];

            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    dp[i] -= dp[j] * comb[j, i];
                }
            }
            Console.WriteLine(dp[0] * n + dp[1]);

        }
        const long INF = 1L << 60;
        int[] dx = { 1, 0, -1, 0 };
        int[] dy = { 0, 1, 0, -1 };
        //*
        int ri { get { return sc.Integer(); } }
        long rl { get { return sc.Long(); } }
        double rd { get { return sc.Double(); } }
        string rs { get { return sc.Scan(); } }
        //*/

        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());
        static T[] Enumerate<T>(int n, Func<int, T> f) { var a = new T[n]; for (int i = 0; i < n; ++i) a[i] = f(i); return a; }
        static public void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }
    }
}

#region main
static class Ex {
    static public string AsString(this IEnumerable<char> ie) { return new string(ie.ToArray()); }
    static public string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ") {
        return string.Join(st, ie.Select(x => x.ToString()).ToArray());
        //return string.Join(st, ie);
    }
    static public void Main() {
        Console.SetOut(new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        var solver = new Program.Solver();
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.Globalization;
    using System.IO;
    using System.Text;
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
            if (ptr >= len) { ptr = 0; if ((len = str.Read(buf, 0, 1024)) <= 0) { isEof = true; return 0; } }
            return buf[ptr++];
        }
        public char Char() { byte b = 0; do b = read(); while ((b < 33 || 126 < b) && !isEof); return (char)b; }

        public string Scan() {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
                sb.Append(b);
            return sb.ToString();
        }
        public string ScanLine() {
            var sb = new StringBuilder();
            for (var b = Char(); b != '\n' && b != 0; b = (char)read())
                if (b != '\r') sb.Append(b);
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
    public const long Mod = (long)1e9 + 7;
    public long num;
    public ModInt(long n) { num = n; }
    public override string ToString() { return num.ToString(); }
    public static ModInt operator +(ModInt l, ModInt r) { l.num += r.num; if (l.num >= Mod) l.num -= Mod; return l; }
    public static ModInt operator -(ModInt l, ModInt r) { l.num -= r.num; if (l.num < 0) l.num += Mod; return l; }
    public static ModInt operator *(ModInt l, ModInt r) { return new ModInt((int)(l.num * r.num % Mod)); }
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

#region Comb
public class Comb {
    public ModInt[] fact, ifact;
    public Comb(int n) {
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