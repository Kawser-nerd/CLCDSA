using System;
using System.Linq;
using System.Collections.Generic;
using Debug = System.Diagnostics.Debug;
using SB = System.Text.StringBuilder;
//using System.Numerics;
using Number = System.Int64;
using static System.Math;
//using static MathEx;
//using P = System.Collections.Generic.KeyValuePair<int, int>;

namespace Program
{
    public class Solver
    {
        public void Solve()
        {
            //??????? x ????????x?a_i ???????????????????
            //b?????????????????
            //+1????????????????…
            var n = ri;
            var a = Enumerate(n, x => rl).ToList();
            a.Add(f(a.ToArray()));
            var b = Enumerate(n, x => rl).ToList();
            b.Add(f(b.ToArray()));

            Debug.WriteLine(a.AsJoinedString());
            Debug.WriteLine(b.AsJoinedString());
            var map = new HashMap<long, int>();
            foreach (var x in a)
                map[x]++;
            foreach (var x in b)
                map[x]--;
            if (map.All(x => x.Value == 0))
            {
                var xs = new List<long>();
                for (int i = 0; i <= n; i++)
                    xs.Add(a[i]);
                xs = xs.Distinct().ToList(); xs.Sort();
                for (int i = 0; i <= n; i++)
                {
                    a[i] = xs.BinarySearch(a[i]);
                    b[i] = xs.BinarySearch(b[i]);
                }
                var m = xs.Count;
                var s = new DisjointSet(m);
                Debug.WriteLine(a.AsJoinedString());
                Debug.WriteLine(b.AsJoinedString());
                for (int i = 0; i <= n; i++)
                {
                    if (a[i] != b[i]) s.Unite((int)a[i], (int)b[i]);
                }


                var cnt = 0;
                for (int i = 0; i < n; i++)
                    if (a[i] != b[i]) cnt++;

                if (cnt == 0) IO.Printer.Out.WriteLine(0);
                else
                {

                    for (int i = 0; i < m; i++)
                    {
                        if (s[i] != i) continue;
                        if (s.Size(i) == 1) continue;
                        if (!s.IsUnited(i, (int)a[n])) cnt++;
                    }

                    IO.Printer.Out.WriteLine(cnt);
                }
            }
            else IO.Printer.Out.WriteLine(-1);

        }
        long f(long[] a)
        {
            var ret = 0L;
            foreach (var x in a) ret ^= x;
            return ret;
        }
        //*
        int ri => sc.Integer();
        long rl => sc.Long();
        double rd => sc.Double();
        string rs => sc.Scan();
        char rc => sc.Char();

        [System.Diagnostics.Conditional("DEBUG")]
        void put(params object[] a) => Debug.WriteLine(string.Join(" ", a));

        //*/
        public IO.StreamScanner sc = new IO.StreamScanner(Console.OpenStandardInput());

        static T[] Enumerate<T>(int n, Func<int, T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f(i);
            return a;
        }
        static void Swap<T>(ref T a, ref T b)
        {
            var tmp = a;
            a = b;
            b = tmp;
        }
    }
}

#region main

static class Ex
{
    public static string AsString(this IEnumerable<char> ie)
    {
        return new string(ie.ToArray());
    }

    public static string AsJoinedString<T>(this IEnumerable<T> ie, string st = " ")
    {
        return string.Join(st, ie);
    }

    public static void Main()
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
        static Printer()
        {
            Out = new Printer(Console.OpenStandardOutput()) { AutoFlush = false };
        }

        public static Printer Out { get; set; }

        public override IFormatProvider FormatProvider
        {
            get { return CultureInfo.InvariantCulture; }
        }

        public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true))
        {
        }

        public Printer(Stream stream, Encoding encoding) : base(stream, encoding)
        {
        }

        public void Write<T>(string format, T[] source)
        {
            base.Write(format, source.OfType<object>().ToArray());
        }

        public void WriteLine<T>(string format, T[] source)
        {
            base.WriteLine(format, source.OfType<object>().ToArray());
        }
    }

    public class StreamScanner
    {
        public StreamScanner(Stream stream)
        {
            str = stream;
        }

        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof;

        public bool IsEndOfStream
        {
            get { return isEof; }
        }

        private byte read()
        {
            if (isEof) return 0;
            if (ptr < len) return buf[ptr++];
            ptr = 0;
            if ((len = str.Read(buf, 0, 1024)) > 0) return buf[ptr++];
            isEof = true;
            return 0;
        }

        public char Char()
        {
            byte b;
            do b = read(); while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }

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
            long ret = 0;
            byte b;
            var ng = false;
            do b = read(); while (b != 0 && b != '-' && (b < '0' || '9' < b));
            if (b == 0) return long.MinValue;
            if (b == '-')
            {
                ng = true;
                b = read();
            }
            for (; ; b = read())
            {
                if (b < '0' || '9' < b)
                    return ng ? -ret : ret;
                ret = ret * 10 + b - '0';
            }
        }

        public int Integer()
        {
            return (isEof) ? int.MinValue : (int)Long();
        }

        public double Double()
        {
            var s = Scan();
            return s != "" ? double.Parse(s, CultureInfo.InvariantCulture) : double.NaN;
        }

        static T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }

        public char[] Char(int n)
        {
            return enumerate(n, Char);
        }

        public string[] Scan(int n)
        {
            return enumerate(n, Scan);
        }

        public double[] Double(int n)
        {
            return enumerate(n, Double);
        }

        public int[] Integer(int n)
        {
            return enumerate(n, Integer);
        }

        public long[] Long(int n)
        {
            return enumerate(n, Long);
        }
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
  //                base[i] = default(V);
  base[i] = new V();
        }
        set { base[i] = value; }
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