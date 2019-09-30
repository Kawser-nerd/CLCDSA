using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
using System.Numerics;
using static System.Math;
namespace Program {
    public class Solver {
        Random rnd = new Random();
        public void Solve() {
            var n = ri;
            var m = ri;
            var G = new bool[n, n];
            for (int i = 0; i < m; i++)
            {
                var f = ri - 1; var t = ri - 1;
                G[f, t] = G[t, f] = true;
            }
            var set = new DisjointSet(2 * n);
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (!G[i, j])
                    {
                        set.Unite(i, j + n);
                        set.Unite(i + n, j);
                    }
            for (int i = 0; i < n; i++)
                if (set[i] == set[i + n])
                {
                    Console.WriteLine(-1); return;
                }
            var cnt = new List<KeyValuePair<int, int>>();
            var used = new bool[n];
            for (int i = 0; i < n; i++)
            {
                if (used[i]) continue;
                var a = new int[2];
                Action<int, int> dfs = null;
                dfs = (v, k) =>
                {
                    used[v] = true;
                    a[k]++;
                    for (int j = 0; j < n; j++)
                        if (!G[v, j] && !used[j]) dfs(j, k ^ 1);
                };
                dfs(i, 0);
                cnt.Add(new KeyValuePair<int, int>(a[0], a[1]));
            }

            Debug.WriteLine(cnt.AsJoinedString());
            var dp = new bool[n + 1000];
            dp[0] = true;
            foreach (var x in cnt)
            {
                var next = new bool[n + 1000];
                for (int j = n - 1; j >= 0; j--)
                {
                    next[j + x.Key] |= dp[j];
                    next[j + x.Value] |= dp[j];
                }
                dp = next;
            }
            var min = INF;
            for (int i = 0; i <= n; i++)
                if (dp[i]) min = Min(min, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
            Console.WriteLine(min);
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