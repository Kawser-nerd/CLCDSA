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
            var h = sc.Integer() + 1;
            var deg = new int[2 * h];
            var set = new DisjointSet(2 * h + 1);
            for (int i = 0; i < n; i++)
            {
                var a = ri; var b = ri; var c = ri; var d = ri;
                if (c == 0 && d == 0)
                {
                    //Console.WriteLine($"{a} {b + h}");
                    deg[a]++; deg[b + h]--; set.Unite(a, b + h);
                }
                else if (c != 0 && d == 0)
                {
                    //Console.WriteLine($"{c + h} {b + h}");
                    deg[c + h]++; deg[b + h]--; set.Unite(c + h, b + h);
                }
                else if (c == 0 && d != 0)
                {
                    //Console.WriteLine($"{a} {d}");
                    deg[a]++; deg[d]--; set.Unite(a, d);
                }
                else if (c != 0 && d != 0)
                {
                    //Console.WriteLine($"{c + h} {d}");
                    deg[c + h]++; deg[d]--; set.Unite(c + h, d);
                }
                else throw new Exception();
            }
            Debug.WriteLine(deg.AsJoinedString());
            var fail = false;
            fail |= deg.All(x => x == 0);
            fail |= deg.Take(h).Min() < 0;
            fail |= deg.Skip(h).Max() > 0;

            for (int i = 0; i < h; i++)
            {
                var k = -deg[i + h];
                if (k == 0) continue;
                for (int j = 0; j < h; j++)
                {
                    var mi = Math.Min(deg[j], k);
                    if (mi == 0) continue;
                    deg[j] -= mi;
                    k -= mi;
                    set.Unite(i + h, 2 * h);
                    set.Unite(j, 2 * h);
                }
                fail |= k != 0;
                deg[i + h] = k;
            }
            Debug.WriteLine(deg.AsJoinedString());
            fail |= deg.Any(x => x != 0);
            var cnt = 0;
            for (int i = 0; i <= 2 * h; i++)
            {
                if (set[i] == i && set.Size(i) != 1) cnt++;
                //if (set[i] == i) { Console.WriteLine($"{i} {set.Size(i)}"); }
            }

            fail |= cnt > 1;
            if (fail)
                Console.WriteLine("NO");
            else Console.WriteLine("YES");

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