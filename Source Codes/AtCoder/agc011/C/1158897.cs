using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {

        public void Solve()
        {
            var n = sc.Integer();
            var m = sc.Integer();
            var a = new int[2 * m];
            var b = new int[2 * m];
            var G = Enumerate(n, x => new List<int>());
            for (int i = 0; i < m; i++)
            {
                a[i] = sc.Integer() - 1;
                b[i] = sc.Integer() - 1;
                if (a[i] > b[i]) Swap(ref a[i], ref b[i]);
                a[i + m] = b[i];
                b[i + m] = a[i];
                G[a[i]].Add(b[i]);
                G[b[i]].Add(a[i]);
            }
            var s = new DisjointSet(n);
            for (int i = 0; i < m; i++)
                s.Unite(a[i], b[i]);

            var ans = 0L;
            long odd = 0;
            long even = 0;
            var vis = new int[n];

            long X = 0;
            for (int i = 0; i < n; i++)
                vis[i] = -1;
            for (int i = 0; i < n; i++)
            {
                if (vis[i] != -1) continue;
                if (G[i].Count == 0)
                {
                    X++;
                    continue;
                }
                var f = true;
                Action<int, int> dfs = null;
                dfs = (cur, c) =>
                  {
                      vis[cur] = c;
                      foreach (var to in G[cur])
                      {
                          var nc = c ^ 1;
                          if (vis[to] == -1) dfs(to, nc);
                          else if (vis[to] != nc)
                          {
                              f = false;
                          }
                      }

                  };
                dfs(i, 0);
                if (f)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            ans += even * (even * 2 + odd);
            ans += odd * (odd + even);
            ans += Math.BigMul(n, n) - (n - X) * (n - X);
            /*


            var set = new DisjointSet(n * n);

            long otaku = 0;
            for (int i = 0; i < 2 * m; i++)
                for (int j = 0; j < 2 * m; j++)
                {
                    var u = a[i] * n + a[j];
                    var v = b[i] * n + b[j];

                    set.Unite(u, v);
                }
            for (int i = 0; i < n * n; i++)
                if (set[i] == i)
                {
                    //if (i / n == 6 || i % n == 6) continue;
                    var res = new List<KeyValuePair<int, int>>();
                    for (int j = 0; j < n * n; j++)
                    {
                        if (set[j] == i) res.Add(new KeyValuePair<int, int>(j / n + 1, j % n + 1));
                    }
                    IO.Printer.Out.WriteLine(res.AsJoinedString());
                    IO.Printer.Out.WriteLine();
                    otaku++;
                }
            IO.Printer.Out.WriteLine(otaku);
            //*/
            IO.Printer.Out.WriteLine(ans);
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
#region DisjointSet
public class DisjointSet
{
    int[] par;
    byte[] rank;
    public DisjointSet(int n)
    {
        par = new int[n];
        for (int i = 0; i < n; i++)
            par[i] = -1;
        rank = new byte[n];
    }
    public int this[int id]
    {
        get
        {
            if ((par[id] < 0)) return id;
            return par[id] = this[par[id]];
        }
    }
    public bool Unite(int x, int y)
    {
        x = this[x]; y = this[y];
        if (x == y) return false;
        if (rank[x] < rank[y])
        {
            par[y] += par[x];
            par[x] = y;
        }
        else
        {
            par[x] += par[y];
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        return true;
    }
    public int Size(int x) { return -par[this[x]]; }
    public bool IsUnited(int x, int y) { return this[x] == this[y]; }

}
#endregion