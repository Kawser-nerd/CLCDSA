using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Number = System.Int64;

namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var a = sc.Integer(n);
            var RG = Enumerate(n, x => new List<int>());
            var RA = Enumerate(n, x => -1);
            var size = new int[n];
            var iscycle = Enumerate(n, x => true);
            var s = new DisjointSet(n);
            var t = new DisjointSet(n);
            {
                var d = new int[n];
                var g = Enumerate(n, x => new List<int>());
                for (int i = 0; i < n; i++)
                {

                    a[i]--;
                    g[i].Add(a[i]);
                    RG[a[i]].Add(i);
                    s.Unite(i, a[i]);
                    d[a[i]]++;
                }
                if (d.Any(x => x >= 3))
                {
                    Debug.WriteLine("hoge");
                    IO.Printer.Out.WriteLine(0); return;
                }
                foreach (var x in Graph.TopologicalSort(g))
                    iscycle[x] = false;
                for (int i = 0; i < n; i++)
                {
                    if (iscycle[i] && iscycle[a[i]])
                    {
                        t.Unite(i, a[i]);
                        RA[a[i]] = i;
                    }
                    if (!iscycle[i] && !iscycle[a[i]])
                        t.Unite(i, a[i]);
                }
                for (int i = 0; i < n; i++)
                {
                    if (!iscycle[i] && RG[i].Count > 1)
                    {
                        Debug.WriteLine("turai");
                        IO.Printer.Out.WriteLine(0);
                        return;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (!iscycle[i] && iscycle[a[i]]) size[a[i]] = t.Size(i);
                }
            }
            ModInteger ans = 1;
            //??: cycle, namori
            var cycle = new int[n + 1];
            {
                var used = new bool[n];
                Func<int, int, int, ModInteger> dfs = null;
                dfs = (cur, sz, d) =>
                  {
                      Debug.WriteLine($"{cur} {sz} {d}");
                      if (sz == -1 && size[cur] == 0)
                          return dfs(RA[cur], -1, -1);
                      else if (size[cur] == 0)
                      {
                          used[cur] = true;
                          return dfs(RA[cur], sz, d + 1);
                      }
                      else
                      {
                          ModInteger ret = 0;
                          if (sz == -1) ret = 1;
                          if (sz > d) ret = 0;
                          else if (sz == d) ret = 1;
                          else ret = 2;

                          if (used[cur]) return ret;
                          used[cur] = true;

                          ret *= dfs(RA[cur], size[cur], 1);

                          return ret;
                      }
                  };
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == i)
                        if (s.Size(i) == t.Size(i)) { cycle[s.Size(i)]++; }
                }
                for (int i = 0; i < n; i++)
                    if (s.Size(i) != t.Size(i) && RA[i] != -1 && !used[i]) ans *= dfs(i, -1, -1);
            }
            //IO.Printer.Out.WriteLine(ans);
            //return;
            //cycle
            for (int i = 0; i <= n; i++)
            {
                if (cycle[i] == 0) continue;
                var k = cycle[i];
                var dp = new ModInteger[k + 1];
                for (int j = 0; j <= k; j++)
                    dp[j].num = -1;
                Func<int, ModInteger> dfs = null;
                dfs = m =>
                  {
                      if (m == 0) return 1;
                      else if (m < 0) return 0;
                      if (dp[m].num != -1) return dp[m];
                      var ret = dfs(m - 1);
                      if (i % 2 != 0 && i != 1) ret *= 2;
                      ret += dfs(m - 2) * i * (m - 1);
                      return dp[m] = ret;
                  };
                ans *= dfs(k);
            }
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
#region ModNumber
public partial struct ModInteger
{
    public const long Mod = (long)1e9 + 7;
    public long num;
    public ModInteger(long n) : this() { num = n % Mod; if (num < 0) num += Mod; }
    public override string ToString() { return num.ToString(); }
    public static ModInteger operator +(ModInteger l, ModInteger r) { var n = l.num + r.num; if (n >= Mod) n -= Mod; return new ModInteger() { num = n }; }
    public static ModInteger operator -(ModInteger l, ModInteger r) { var n = l.num + Mod - r.num; if (n >= Mod) n -= Mod; return new ModInteger() { num = n }; }
    public static ModInteger operator *(ModInteger l, ModInteger r) { return new ModInteger(l.num * r.num); }
    public static implicit operator ModInteger(long n) { return new ModInteger(n); }
    public static ModInteger Pow(ModInteger v, long k)
    {
        ModInteger ret = 1;
        var n = k;
        for (; n > 0; n >>= 1, v *= v)
        {
            if ((n & 1) == 1)
                ret = ret * v;
        }
        return ret;
    }
}
#endregion
#region TopologicalSort
static partial class Graph
{
    //???????????Queue?????
    //???????????count????????-1??????
    static public int[] TopologicalSort(List<int>[] G, int[] count = null)
    {
        const int Capacity = 0;//?????0?????1
        var n = G.Length;
        if (count == null)
        {
            count = new int[n];
            foreach (var l in G)
                foreach (var x in l) count[x]++;
        }
        var ret = new List<int>();
        var q = new Queue<int>();
        for (int i = 0; i < n; i++)
            if (count[i] == Capacity) q.Enqueue(i);
        while (q.Any())
        {
            var p = q.Dequeue();
            ret.Add(p);
            foreach (var x in G[p])
                if (--count[x] == Capacity) q.Enqueue(x);
        }
        return ret.ToArray();
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