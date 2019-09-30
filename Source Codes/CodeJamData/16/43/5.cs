using System;
using System.Linq;
using System.Linq.Expressions;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int64;
using _ANSWER = System.String;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var T = sc.Integer();
            var ans = new _ANSWER[T][];
            var f = new Func<_ANSWER[]>[T];
            for (int _ = 0; _ < T; _++)
            {
                var r = sc.Integer();
                var c = sc.Integer();
                var a = sc.Integer(2 * (r + c));
                f[_] = () => solve(r, c, a);
                ans[_] = f[_]();
                IO.Printer.Out.WriteLine("Case #{0}:", _ + 1);
                foreach (var x in ans[_])
                    IO.Printer.Out.WriteLine(x);
            }
            //System.Threading.Tasks.Parallel.For(0, T, i => ans[i] = f[i]());
            for (int _ = 0; _ < T; _++)
            {
            }
        }
        _ANSWER[] solve(int r, int c, int[] a)
        {
            for (int i = 0; i < a.Length; i++)
                a[i]--;
            var ans = new string[r];
            var N = 2 * (r + c);
            var SZ = r * c;
            for (int mask = 0; mask < 1 << SZ; mask++)
            {
                //mask = 1;
                var s = new DisjointSet(N + 4 * SZ);
                for (int i = 0; i < c; i++)
                {
                    s.Unite(4 * SZ + i, i * 4);
                    s.Unite(4 * SZ + r + c + (c - i - 1), (r - 1) * (4 * c) + i * 4 + 2);
                }
                for (int i = 0; i < r; i++)
                {
                    s.Unite(4 * SZ + c + i, i * (4 * c) + (c - 1) * 4 + 1);
                    s.Unite(4 * SZ + c + r + c + (r - i - 1), i * (4 * c) + 0 * 4 + 3);
                }
                var C = new char[SZ];
                for (int x = 0; x < r; x++)
                    for (int y = 0; y < c; y++)
                    {
                        var cell = x * (4 * c) + y * 4;
                        if (x > 0)
                        {
                            var nc = (x - 1) * (4 * c) + y * 4;
                            s.Unite(cell + 0, nc + 2);
                        }
                        if (x + 1 < r)
                        {
                            var nc = (x + 1) * (4 * c) + y * 4;
                            s.Unite(cell + 2, nc + 0);
                        }
                        if (y > 0)
                        {
                            var nc = x * (4 * c) + (y - 1) * 4;
                            s.Unite(cell + 3, nc + 1);
                        }
                        if (y + 1 < c)
                        {
                            var nc = x * (4 * c) + (y + 1) * 4;
                            s.Unite(cell + 1, nc + 3);
                        }
                    }
                for (int i = 0; i < SZ; i++)
                {
                    var x = i / c;
                    var y = i % c;
                    var cell = x * (4 * c) + y * 4;
                    if ((mask >> i & 1) == 1)
                    {
                        C[i] = '/';
                        s.Unite(cell + 0, cell + 3);
                        s.Unite(cell + 1, cell + 2);
                    }
                    else
                    {
                        C[i] = '\\';
                        s.Unite(cell + 0, cell + 1);
                        s.Unite(cell + 2, cell + 3);
                    }
                }
                var ok = true;
                for (int i = 0; i < N; i += 2)
                {
                    if (s.IsUnited(4 * SZ + a[i], 4 * SZ + a[i + 1]))
                        continue;
                    else
                        ok = false;
                }
                if (ok)
                {
                    for (int i = 0; i < r; i++)
                    {
                        var sb = new StringBuilder();
                        for (int j = 0; j < c; j++)
                            sb.Append(C[i * c + j]);
                        ans[i] = sb.ToString();
                    }
                    return ans;
                }
            }

            return new string[] { "IMPOSSIBLE" };
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
    public int[] par, ranks, count;
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