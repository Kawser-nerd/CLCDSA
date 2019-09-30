using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
//using System.Threading.Tasks;
namespace Program
{

    public class Solver
    {
        public void Solve()
        {
            var __ = sc.Integer();
            for (int _ = 1; _ <= __; _++)
            {
                var r = sc.Integer();
                var c = sc.Integer();
                var map = Enumerate(r, x => sc.Char(c));
                var n = r * c;
                var G = Enumerate(n, x => new List<int>());
                var RG = Enumerate(n, x => new List<int>());

                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                    {
                        if (map[i][j] == '.') continue;
                        switch (map[i][j])
                        {
                            case '>':
                                for (int y = j + 1; y < c; y++)
                                    if (map[i][y] != '.')
                                    {
                                        G[i * c + j].Add(i * c + y);
                                        RG[i * c + y].Add(i * c + j);
                                        break;
                                    }
                                break;
                            case '<':
                                for (int y = j - 1; y >= 0; y--)
                                    if (map[i][y] != '.')
                                    {
                                        G[i * c + j].Add(i * c + y);
                                        RG[i * c + y].Add(i * c + j);
                                        break;
                                    }
                                break;
                            case 'v':
                                for (int x = i + 1; x < r; x++)
                                    if (map[x][j] != '.')
                                    {
                                        G[i * c + j].Add(x * c + j);
                                        RG[x * c + j].Add(i * c + j);
                                        break;
                                    }
                                break;
                            case '^':
                                for (int x = i - 1; x >= 0; x--)
                                    if (map[x][j] != '.')
                                    {
                                        G[i * c + j].Add(x * c + j);
                                        RG[x * c + j].Add(i * c + j);
                                        break;
                                    }
                                break;

                            default:
                                break;
                        }

                    }
                int size;
                var scc = DSCCHelper.SCC(G, RG, out size);
                var set = new DisjointSet(size);
                for (int i = 0; i < n; i++)
                {
                    foreach (var to in G[i])
                        set.Unite(scc[i], scc[to]);
                }
                var ans = 0;
                for (int p = 0; p < n; p++)
                {
                    if (map[p / c][p % c] == '.') continue;
                    if (G[p].Count == 0)
                    {
                        if (set.Size(scc[p]) > 1)
                            ans++;
                        else
                        {
                            var cnt = 0;
                            var i = p / c; var j = p % c;
                            for (int y = j + 1; y < c; y++)
                                if (map[i][y] != '.')
                                {
                                    cnt++;
                                    break;
                                }
                            for (int y = j - 1; y >= 0; y--)
                                if (map[i][y] != '.')
                                {
                                    cnt++;
                                    break;
                                }
                            for (int x = i + 1; x < r; x++)
                                if (map[x][j] != '.')
                                {
                                    cnt++;
                                    break;
                                }
                            for (int x = i - 1; x >= 0; x--)
                                if (map[x][j] != '.')
                                {
                                    cnt++;
                                    break;
                                }
                            if (cnt > 0) ans++;
                            else ans = 1 << 30;
                        }
                    }
                }
                if (ans >= 1 << 30)
                    IO.Printer.Out.WriteLine("Case #{0}: IMPOSSIBLE", _);
                else IO.Printer.Out.WriteLine("Case #{0}: {1}", _, ans);

                //IO.Printer.Out.WriteLine("Case #{0}: {1}", _);
            }

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
    public class Printer : StreamWriter
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
        public long Long()
        {
            if (isEof) return long.MinValue;
            long ret = 0; byte b = 0; var ng = false;
            do b = read();
            while (b != '-' && (b < '0' || '9' < b));
            if (b == '-') { ng = true; b = read(); }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                else ret = ret * 10 + b - '0';
            }
        }
        public int Integer() { return (isEof) ? int.MinValue : (int)Long(); }
        public double Double() { return double.Parse(Scan(), CultureInfo.InvariantCulture); }
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
#region DecomposiitonOfStronglyConnectedComponents
static public class DSCCHelper
{
    static public int[] SCC(List<int>[] G, List<int>[] RG, out int k)
    {
        var n = G.Length;
        var used = new bool[n];
        var vs = new List<int>(n);
        var cmp = new int[n];
        Action<int> dfs = null;
        dfs = v =>
        {
            used[v] = true;
            foreach (var to in G[v])
                if (!used[to]) dfs(to);
            vs.Add(v);
        };
        Action<int, int> rdfs = null;
        rdfs = (v, t) =>
        {
            used[v] = true;
            cmp[v] = t;
            foreach (var to in RG[v])
                if (!used[to]) rdfs(to, t);
        };

        for (int i = 0; i < used.Length; i++)
            if (!used[i]) dfs(i);
        used = new bool[n];
        k = 0;
        for (int i = vs.Count - 1; i >= 0; i--)
            if (!used[vs[i]]) rdfs(vs[i], k++);
        return cmp;

    }
}
#endregion
#region DisjointSet
public class DisjointSet
{
    int[] par, ranks, count;
    public DisjointSet(int n)
    {
        par = new int[n];
        count = new int[n];
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            count[i] = 1;
        }
        ranks = new int[n];
    }
    public int this[int id] { get { return (par[id] == id) ? id : this[par[id]]; } }
    public bool Unite(int x, int y)
    {
        x = this[x]; y = this[y];
        if (x == y) return false;
        if (ranks[x] < ranks[y])
        {
            par[x] = y;
            count[y] += count[x];
        }
        else
        {
            par[y] = x;
            count[x] += count[y];
            if (ranks[x] == ranks[y])
                ranks[x]++;
        }
        return true;
    }
    public int Size(int x) { return count[this[x]]; }
    public bool IsUnited(int x, int y) { return this[x] == this[y]; }

}
#endregion
