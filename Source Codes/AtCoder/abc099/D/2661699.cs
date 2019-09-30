using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;


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
            var c = scanner.Integer();
            var ds = new List<List<int>>();
            for (int i = 0; i < c; i++)
                ds.Add(scanner.ScanLine().Split().Select(v => int.Parse(v)).ToList());
            var grid = new List<List<int>>();
            for (int i = 0; i < n; i++)
                grid.Add(scanner.ScanLine().Split().Select(v => int.Parse(v)).ToList());
            IO.Printer.Out.WriteLine(GetAns(n, c, ds, grid));
            IO.Printer.Out.Flush();
        }

        public static long GetAns(int n, int c, List<List<int>> ds, List<List<int>> grid)
        {
            var c1Dict = new Dictionary<int, long>();
            var c2Dict = new Dictionary<int, long>();
            var c3Dict = new Dictionary<int, long>();

            for (var flg = 0; flg < 3; flg++)
            {
                for (var c1 = 1; c1 <= c; c1++)
                {
                    var sum = 0L;
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (flg != (i + j) % 3) continue;

                            if (grid[i][j] != c1)
                                sum += ds[grid[i][j] - 1][c1 - 1];
                        }
                    }
                    var tgtDict = flg == 0 ? c1Dict : flg == 1 ? c2Dict : c3Dict;
                    tgtDict.Add(c1, sum);
                }
            }

            var ret = long.MaxValue;

            for (var c1 = 1; c1 <= c; c1++)
            {
                for (var c2 = 1; c2 <= c; c2++)
                {
                    if (c1 == c2) continue;
                    for(var c3=1; c3<=c; c3++)
                    {
                        if (c3 == c1 || c3 == c2) continue;
                        ret = Math.Min(ret, c1Dict[c1] + c2Dict[c2] + c3Dict[c3]);
                    }
                }
            }
            return ret;
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