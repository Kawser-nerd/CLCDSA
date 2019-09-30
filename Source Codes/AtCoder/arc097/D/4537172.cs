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
            //?????????????????
            //??????????????????????????
            // u->v ???????????
            //???????????????????
            //???????????????dfs ?????????????????
            //dfs??????????????????????
            //?????????????????????????????-1?????
            //??????2(N-1)
            //??????? X_u = |G[v]|+S[v]+1 mod2
            //???? u->v ???????????? ?????-[u->v)????X_i=0???+[u->v)????X_i==1???
            var n = ri;
            var G = Enumerate(n, x => new List<int>());
            foreach (var i in Rep(n - 1)) {
                var u = ri - 1;
                var v = ri - 1;
                G[u].Add(v);
                G[v].Add(u);
            }
            var s = rs.Select(x => x == 'B' ? 1 : 0).ToArray();
            if (s.Sum() == n) { Console.WriteLine(0); return; }
            var r = Array.FindIndex(s, 0, n, x => x == 0);

            var H = Enumerate(n, x => new List<int>());
            var sz = new int[n];
            var sum = new int[n];
            Action<int, int> dfs = null;
            dfs = (prev, cur) => {
                sz[cur] = 1;
                sum[cur] = s[cur];
                foreach (var t in G[cur])
                    if (t != prev) {
                        dfs(cur, t);
                        if (sz[t] != sum[t]) {
                            sz[cur] += sz[t];
                            sum[cur] += sum[t];
                            H[cur].Add(t);
                            H[t].Add(cur);
                        }
                    }
            };
            dfs(-1, r);
            var X = new int[n];
            foreach (var i in Rep(n))
                X[i] = (1 + s[i] + H[i].Count) % 2;
            var ans = solve(X, H, r);
            if (ans < 0) ans = 1;
            Console.WriteLine(ans);
        }
        int solve(int[] c, List<int>[] G, int r) {
            //??????????????????
            //u--v ????????? ?????+v???????????????-??????????
            //?????-Max(???????????*2)???
            Debug.WriteLine(c.AsJoinedString());
            var add = 0;
            var ans = 0;
            Func<int, int, int> dfs = null;
            dfs = (prev, cur) => {
                add += 2;
                var ret = 0;
                if (c[cur] == 1) { ret = 1; add++; }
                foreach (var t in G[cur])
                    if (t != prev) {
                        Debug.WriteLine($"{cur + 1} {t + 1}");
                        var res = dfs(cur, t);
                        ans = Max(ans, (ret + res));
                        ret = Max(ret, res + c[cur]);
                    }
                ans = Max(ans, ret);
                return ret;
            };

            dfs(-1, r);
            add -= 2;
            Debug.WriteLine(add);
            Debug.WriteLine(ans);
            return add - 2 * ans;
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