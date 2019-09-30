using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            var n = ri;
            var m = ri;
            var X = rl;
            var f = new int[m];
            var t = new int[m];
            var w = new int[m];
            var set = new DisjointSet(n);
            for (int i = 0; i < m; i++)
            {
                f[i] = ri - 1; t[i] = ri - 1; w[i] = ri;
            }
            var G = Enumerate(n, x => new List<KeyValuePair<int, long>>());

            var sum = 0L;
            foreach (var id in Enumerate(m, x => x).OrderBy(x => w[x]))
            {
                if (set.Unite(f[id], t[id]))
                {
                    sum += w[id];
                    G[f[id]].Add(new KeyValuePair<int, long>(t[id], w[id]));
                    G[t[id]].Add(new KeyValuePair<int, long>(f[id], w[id]));
                }
            }
            if (sum > X)
            {
                Console.WriteLine(0); return;
            }
            var dist = Enumerate(n, x => new long[n]);
            for (int i = 0; i < n; i++)
            {
                Action<int, int, long> dfs = null;
                dfs = (prev, cur, v) =>
                {
                    dist[i][cur] = v;
                    foreach (var e in G[cur]) if (e.Key != prev) dfs(cur, e.Key, Max(v, e.Value));
                };
                dfs(-1, i, 0);
            }
            var eq = 0;
            var over = 0;
            for (int i = 0; i < m; i++)
            {
                var d = w[i] - dist[f[i]][t[i]];
                if (d == X - sum) eq++;
                else if (d > X - sum) over++;
            }
            ModInt ans = 0;
            if (X == sum)
            {
                ans += (ModInt.Pow(2, n - 1) - 2) * ModInt.Pow(2, m - (n - 1));
                ans += 2 * (ModInt.Pow(2, eq - (n - 1)) - 1) * ModInt.Pow(2, over);
            }
            else
            {
                ans += 2 * (ModInt.Pow(2, eq) - 1) * ModInt.Pow(2, over);
            }
            Console.WriteLine(ans);
        }
        const long INF = 5L << 60;
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
#region DisjointSet
public class DisjointSet {
    int[] par;
    byte[] rank;
    public DisjointSet(int n) {
        par = new int[n];
        for (int i = 0; i < n; i++)
            par[i] = -1;
        rank = new byte[n];
    }
    public int this[int id] {
        get {
            if ((par[id] < 0)) return id;
            return par[id] = this[par[id]];
        }
    }
    public bool Unite(int x, int y) {
        x = this[x]; y = this[y];
        if (x == y) return false;
        if (rank[x] < rank[y]) { var z = x; x = y; y = z; }
        par[x] += par[y];
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }
    public int Size(int x) { return -par[this[x]]; }
    public bool IsUnited(int x, int y) { return this[x] == this[y]; }

}
#endregion