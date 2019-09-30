using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using StringBuilder = System.Text.StringBuilder;
using System.Numerics;
using Point = System.Numerics.Complex;
using Number = System.Int64;
namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            var n = sc.Integer();
            var u = sc.Long();
            var v = sc.Long();
            var a = sc.Long(n);
            long ans = 0;
            var E = new List<Triplet<long, int, int>>();
            for (int i = 1; i < n; i++)
                E.Add(Triplet.Create(u * (a[i] - a[i - 1]), i - 1, i));
            E.Sort();
            var set = new DisjointSet(n);
            foreach (var x in E)
            {
                if (x.I > v) continue;
                if (set.IsUnited(x.J, x.K)) continue;
                else
                {
                    set.Unite(x.J, x.K);
                    ans += x.I;
                }
            }
            var cnt = 0;
            for (int i = 0; i < n; i++)
                if (set[i] == i) cnt++;
            IO.Printer.Out.WriteLine(ans + (cnt - 1) * v);
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

#region Triplet<ST,FT,TT>
static public class Triplet
{
    static public Triplet<FT, ST, TT> Create<FT, ST, TT>(FT f, ST s, TT t) where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
    {
        return new Triplet<FT, ST, TT>(f, s, t);
    }

    static public Triplet<FT, ST, TT> Max<FT, ST, TT>(Triplet<FT, ST, TT> p, Triplet<FT, ST, TT> q) where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
    {
        return p.CompareTo(q) >= 0 ? p : q;
    }
    static public Triplet<FT, ST, TT> Min<FT, ST, TT>(Triplet<FT, ST, TT> p, Triplet<FT, ST, TT> q) where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
    {
        return p.CompareTo(q) <= 0 ? p : q;
    }
}
public struct Triplet<FT, ST, TT>: IComparable<Triplet<FT, ST, TT>> where FT : IComparable<FT> where ST : IComparable<ST> where TT : IComparable<TT>
{
    public FT I;
    public ST J;
    public TT K;
    public Triplet(FT i, ST j, TT k) : this() { I = i; J = j; K = k; }
    public int CompareTo(Triplet<FT, ST, TT> other)
    {
        var cmp = I.CompareTo(other.I);
        if (cmp != 0) return cmp;
        cmp = J.CompareTo(other.J);
        if (cmp != 0) return cmp;
        return K.CompareTo(other.K);
    }
    public override string ToString() { return string.Format("{0} {1} {2}", I, J, K); }
}
#endregion