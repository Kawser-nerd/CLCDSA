using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using static System.Math;
using Number = System.Int32;
namespace Program {
    public class Solver {
        Random rnd = new Random();
        public void Solve() {
            var n = ri;
            var G = Enumerate(n, x => new List<int>());
            for (int i = 0; i < n - 1; i++)
            {
                var f = ri - 1; var t = ri - 1;
                G[f].Add(t); G[t].Add(f);
            }
            var sz = new int[n];
            var M = 1;
            while (M < n) M *= 2;
            var a = new int[2 * M];

            Func<int, int, int> dfs = null;
            dfs = (prev, cur) =>
            {
                sz[cur]++;
                foreach (var to in G[cur]) if (to != prev)
                    {
                        var x = dfs(cur, to);
                        a[x]++; a[n - x]++;
                        sz[cur] += x;
                    }
                return sz[cur];
            }; dfs(-1, 0);
            Debug.WriteLine(a.AsJoinedString());
            const long MOD = ModFFT.MOD;
            var b = new int[2 * M];
            var fact = new long[2 * M];
            var ifact = new long[2 * M];
            fact[0] = ifact[0] = 1;
            for (int i = 1; i < 2 * M; i++)
            {
                fact[i] = fact[i - 1] * i % MOD;
                ifact[i] = ModFFT.ModPow(fact[i], (int)(MOD - 2));
            }
            for (int i = 0; i < n; i++)
            {
                a[i] = (int)(a[i] * fact[i] % MOD);
                b[M - i] = (int)(ifact[i]);
            }
            var res = ModFFT.Convolute(a, b);
            for (int i = 0; i < M; i++)
                res[i + M] = (int)(res[i + M] * ifact[i] % MOD);
            for (int i = 1; i <= n; i++)
            {
                long ans = 0;
                ans = (fact[n] * ifact[n - i] % MOD) * ifact[i] % MOD;
                ans = n * ans % MOD;
                ans = (ans + MOD - res[i + M]) % MOD;
                Console.WriteLine(ans);
            }

        }

        const long INF = 5L << 60;
        static int[] dx = { -1, 0, 1, 0 };
        static int[] dy = { 0, 1, 0, -1 };
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


#region ModFFT
static class ModFFT {
    public const int MOD = 924844033;
    static readonly int[] roots;
    static ModFFT() {
        for (int i = 2; i * i <= MOD; i++) if (MOD % i == 0) throw new Exception();
        int t, p2;
        for (t = MOD - 1, p2 = 0; t % 2 == 0; t /= 2, p2++) ;
        if (p2 == 0) throw new Exception();
        roots = new int[p2 + 1];
        int s;
        for (s = 2; ; s++) if (ModPow(s, (MOD - 1) / 2) != 1) break;
        var pw = MOD - 1;
        for (int i = 0; i < p2; i++, pw /= 2)
            roots[i] = ModPow(s, pw);
    }
    static public int ModPow(long a, int k) {
        long ret = 1;
        for (; k > 0; a = (a * a) % MOD, k /= 2)
            if (k % 2 == 1) ret = (ret * a) % MOD;
        return (int)ret;
    }
    static int rev(int x, int n) {
        int ret = 0;
        int rev = n >> 1;
        for (int p2 = 1; p2 < n; p2 <<= 1, rev >>= 1)
            if ((x & p2) != 0)
                ret |= rev;
        return ret;
    }
    static void fft(int[] a, bool inv) {
        var n = a.Length;
        for (int i = 0, j = 1; j < n - 1; ++j)
        {
            for (int k = n >> 1; k > (i ^= k); k >>= 1) ;
            if (j < i) { var tmp = a[i]; a[i] = a[j]; a[j] = tmp; }
        }
        for (int p2 = 1, pow2 = 1; p2 < n; p2 *= 2, pow2++)
        {
            var w = roots[pow2];
            if (inv) w = ModPow(w, MOD - 2);
            for (int big = 0; big < n; big += 2 * p2)
            {
                int cur = 1;
                for (int small = big; small < big + p2; ++small)
                {
                    int i = small;
                    int j = small + p2;
                    int u = a[i];
                    int o = a[j];
                    int v = (int)(o * (long)cur % MOD);
                    a[i] = u + v;
                    if (a[i] >= MOD) a[i] -= MOD;
                    a[j] = u - v;
                    if (a[j] < 0) a[j] += MOD;
                    cur = (int)(cur * (long)w % MOD);
                }
            }

        }
    }
    static public int[] Convolute(int[] a, int[] b) {
        var k = 1;
        while (k < a.Length + b.Length - 1) k *= 2;
        var aa = new int[k]; Array.Copy(a, aa, a.Length);
        var bb = new int[k]; Array.Copy(b, bb, b.Length);
        fft(aa, false);
        fft(bb, false);
        var c = new int[k];
        for (int i = 0; i < k; i++)
            c[i] = (int)(Math.BigMul(aa[i], bb[i]) % MOD);
        fft(c, true);
        var inv = ModPow(k, MOD - 2);
        for (int i = 0; i < k; i++)
            c[i] = (int)(Math.BigMul(c[i], inv) % MOD);
        return c;
    }
}
#endregion