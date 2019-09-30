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
            var a = Enumerate(n, x => sc.Integer(4));
            long ans = 0;
            Func<int[], int, long> g = (c, d) =>
             {
                 var v = 0L;
                 for (int i = 0; i < 4; i++) v = v * 1000 + c[(i + d) % 4];
                 return v;
             };
            Func<int[], long[]> h = c =>
                {
                    var hash = new long[4];
                    for (int d = 0; d < 4; d++)
                        hash[d] = g(c, d);
                    Array.Sort(hash);
                    return hash;
                };
            var binomial = new long[n + 2, 6];
            binomial[0, 0] = 1;
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= 4; j++)
                {
                    binomial[i + 1, j] += binomial[i, j];
                    binomial[i + 1, j + 1] += binomial[i, j];
                }
            var fact = new int[5];
            fact[0] = 1;
            for (int i = 1; i < 5; i++)
                fact[i] = fact[i - 1] * i;
            var map = new HashMap<long, int>();
            for (int i = 0; i < n; i++)
                map[h(a[i])[0]]++;
            var b = new long[n];
            for (int i = 0; i < n; i++)
                b[i] = h(a[i])[0];
            var coef = new HashMap<long, int>();
            foreach (var x in map)
            {
                var v = x.Key;
                var c = new int[4];
                for (int i = 3; i >= 0; i--)
                {
                    c[i] = (int)(v % 1000); v /= 1000;
                }
                for (int i = 0; i < 4; i++)
                    coef[g(c, i)]++;
            }

            for (int i = 0; i < n; i++)
            {
                map[b[i]]--;
                for (int d = 0; d < 4; d++)
                {
                    var x = new int[4];
                    for (int j = 0; j < 4; j++)
                        x[j] = a[i][(d + j) % 4];
                    for (int j = i + 1; j < n; j++)
                    {
                        var y = a[j];
                        map[b[j]]--;
                        var c = Enumerate(4, v => new int[4]);
                        c[0][0] = x[1];
                        c[0][1] = x[0];
                        c[0][2] = y[1];
                        c[0][3] = y[0];
                        c[1][0] = x[0];
                        c[1][1] = x[3];
                        c[1][2] = y[2];
                        c[1][3] = y[1];
                        c[2][0] = x[3];
                        c[2][1] = x[2];
                        c[2][2] = y[3];
                        c[2][3] = y[2];
                        c[3][0] = x[2];
                        c[3][1] = x[1];
                        c[3][2] = y[0];
                        c[3][3] = y[3];

                        var need = new HashMap<long, List<long>>();
                        for (int k = 0; k < 4; k++)
                            need[h(c[k])[0]].Add(g(c[k], 0));

                        var add = 1L;
                        foreach (var hash in need)
                        {
                            foreach (var v in hash.Value)
                                add *= coef[v];
                            var sum = hash.Value.Count;
                            int cnt;
                            if (map.TryGetValue(hash.Key, out cnt))
                            {
                                add *= binomial[cnt, sum] * fact[sum];
                            }
                            else add = 0;
                        }
                        ans += add;
                        map[b[j]]++;
                    }
                }
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
#region HashMap<K,V>
public class HashMap<K, V>: Dictionary<K, V>
where V : new()
{
    public HashMap() : base() { }
    public HashMap(int cap) : base(cap) { }
    new public V this[K i]
    {
        get
        {
            V v;
            return TryGetValue(i, out v) ? v :
            //    base[i] = default(V);
            base[i] = new V();
        }
        set { base[i] = value; }
    }
}
#endregion