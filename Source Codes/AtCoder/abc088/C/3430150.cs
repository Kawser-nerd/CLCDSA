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

            var c1 = scanner.ScanLine().Split().Select(v => int.Parse(v)).ToList();
            var c2 = scanner.ScanLine().Split().Select(v => int.Parse(v)).ToList();
            var c3 = scanner.ScanLine().Split().Select(v => int.Parse(v)).ToList();

            var ans = false;

            for (var a1 = -100; !ans && a1 <= 100; a1++)
            {
                for (var a2 = -100; !ans && a2 <= 100; a2++)
                {
                    var b1 = GetBs(a1, c1);
                    var b2 = GetBs(a2, c2);
                    if (Same(b1, b2))
                    {
                        for (var a3 = -100; !ans && a3 <= 100; a3++)
                        {
                            var b3 = GetBs(a3, c3);
                            if (Same(b2, b3)) ans = true;
                        }
                    }
                }
            }

            IO.Printer.Out.WriteLine(ans ? "Yes" : "No");
            IO.Printer.Out.Flush();
        }

        static List<int> GetBs(int a, List<int> c)
        {
            var ret = new List<int>();
            foreach(var cval in c)
            {
                ret.Add(a - cval);
            }
            return ret;
        }

        static bool Same(List<int> a1, List<int> a2)
        {
            for (int i = 0; i < a1.Count(); i++)
            {
                if (a1[i] != a2[i]) return false;
            }
            return true;
        }
    }
}

#if DEBUG
#endif

#region INOUT

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

    #endregion