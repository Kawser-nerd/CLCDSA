using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Trace;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
using Number = System.Int64;
namespace Program {
    public class Solver {
        Random rnd = new Random(0);
        public void Solve() {
            //?????
            //???????????? B_v ?????
            //A_v ?????????
            //????????? C_v = max(0,A_v - B_v) ????????
            //??????????????????????
            //??? X ???????????????
            //O(N^2 polylogN) ????

            // X ??????????????????????????
            // C_v ??????????C_v>=C_u ???????????????????
            // ????? C_v ????????
            // ????? max(dp[u],C_v-S_u) ????????

            var n = ri; var m = ri;
            var AB = Enumerate(n, x => new long[] { rl, rl });
            var C = Enumerate(n, x => Max(0, AB[x][0] - AB[x][1]));
            var G = Enumerate(n, x => new List<int>());
            foreach (var i in Rep(m)) {
                var u = ri - 1;
                var v = ri - 1;
                G[u].Add(v); G[v].Add(u);
            }
            var H = Enumerate(n, x => new List<int>());
            var r = Enumerate(n, x => x);
            var s = new DisjointSet(n);
            foreach (var id in Enumerate(n, x => x).OrderBy(x => C[x] * 1000000L + x)) {
                foreach (var t in G[id]) {
                    var v = C[id] * 1000000L + id;
                    var u = C[t] * 1000000L + t;
                    if (v >= u && !s.IsUnited(id, t)) {
                        H[id].Add(r[s[t]]);
                        s.Unite(id, t);
                        r[s[id]] = id;
                    }
                }
            }
            Func<int, KeyValuePair<long, long>> dfs = null;
            dfs = (cur) => {
                var sum = AB[cur][1];
                var ret = C[cur];
                foreach (var t in H[cur]) {
                    var res = dfs(t);
                    sum += res.Key;
                    ret = Min(ret, Max(res.Value, C[cur] - res.Key));
                }

                return new KeyValuePair<long, long>(sum, ret);
            };
            var ans = dfs(r[s[0]]);
            Console.WriteLine(ans.Key + ans.Value);
        }
        const long INF = 1L << 60;
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static IEnumerable<int> Rep(int n) => Enumerable.Range(0, n);
        static IEnumerable<int> RRep(int n) => Enumerable.Range(0, n).Reverse();
        static T[] Enumerate<T>(int n, Func<int, T> f) {
            var a = new T[n];
            for (int i = 0; i < a.Length; ++i) a[i] = f(i);
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
        solver.Solve();
        Console.Out.Flush();
    }
}
#endregion
#region Ex
namespace Program.IO {
    using System.IO;
    using System.Text;
    using System.Globalization;

    public class Printer : StreamWriter {
        public override IFormatProvider FormatProvider => CultureInfo.InvariantCulture;
        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    }

    public class StreamScanner {
        public StreamScanner(Stream stream) { str = stream; }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;

        private byte read() {
            if (isEof) return 0;
            if (ptr >= len) {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0) {
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