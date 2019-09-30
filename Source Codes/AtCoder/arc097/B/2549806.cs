using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


#if DEBUG
using Microsoft.VisualStudio.TestTools.UnitTesting;
#endif

namespace competitive_programming
{
    public class Program
    {
        static void Main(string[] args)
        {
#if DEBUG
            var scanner = new IO.StreamScanner(File.Open("input.txt", FileMode.Open));
#else
            var scanner = new IO.StreamScanner(Console.OpenStandardInput());
#endif

            var n = scanner.Integer();
            var m = scanner.Integer();
            var p = scanner.ScanLine().Split().Select(v => int.Parse(v)).ToList();
            var pairs = new List<Tuple<int, int>>();
            for (int i = 0; i < m; i++)
            {
                pairs.Add(new Tuple<int, int>(scanner.Integer(), scanner.Integer()));
            }
            IO.Printer.Out.WriteLine(GetAns(n, m, p, pairs));
            IO.Printer.Out.Flush();
        }

        public static int GetAns(int n, int m, List<int> p, List<Tuple<int, int>> pairs)
        {
            var valToIndex = new Dictionary<int, int>();
            for (int i = 0; i < n; i++)
            {
                valToIndex.Add(p[i], i + 1);
            }

            var uf = new UnionFind_WithSize(n + 1);
            foreach (var pair in pairs)
            {
                uf.Unite(pair.Item1, pair.Item2);
            }

            var valToIndices = new Dictionary<int, HashSet<int>>();
            var groups = new Dictionary<int, HashSet<int>>();
            for (int i = 1; i <= n; i++)
            {
                var root = uf.root(i);
                if (!groups.ContainsKey(root)) groups.Add(root, new HashSet<int>());
                groups[root].Add(valToIndex[i]);
                valToIndices.Add(i, groups[root]);
            }

            var ret = 0;
            for (int i = n; i >= 1; i--)
            {
                if (valToIndices[i].Contains(i)) ret++;
            }
            return ret;
        }
    }

    public class UnionFind_WithSize
    {
        List<int> par;

        public UnionFind_WithSize(int N)
        {
            par = new List<int>(N);
            for (int i = 0; i < N; i++) par.Add(-1);
        }

        public void Init()
        {
            for (int i = 0; i < par.Count; i++) par[i] = -1;
        }

        public int root(int x)
        {
            return par[x] >= 0 ? par[x] = root(par[x]) : x;
        }

        public bool Same(int x, int y)
        {
            return root(x) == root(y);
        }

        public bool Unite(int x, int y)
        {
            x = root(x);
            y = root(y);
            if (x == y) return false;
            if (par[x] > par[y])
            {
                var tmp = y;
                y = x;
                x = tmp;
            }
            par[x] += par[y];
            par[y] = x;
            return true;
        }

        public int Size(int x)
        {
            return -par[root(x)];
        }
    }

#if DEBUG
    [TestClass]
    public class Test
    {
    }
#endif

    namespace IO
    {
        using System.IO;
        using System.Text;
        using System.Globalization;

        public class Printer : StreamWriter
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

            public Printer(Stream stream)
                : base(stream, new UTF8Encoding(false, true))
            {
            }

            public Printer(Stream stream, Encoding encoding)
                : base(stream, encoding)
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
}