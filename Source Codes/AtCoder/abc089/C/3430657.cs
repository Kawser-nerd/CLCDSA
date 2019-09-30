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
            var ss = new List<string>();

            for (int i = 0; i < n; i++) ss.Add(scanner.ScanLine());

            var strsDict = new Dictionary<char, int>();
            foreach(var s in ss)
            {
                if (!"MARCH".Contains(s[0])) continue;
                if (!strsDict.ContainsKey(s[0])) strsDict.Add(s[0], 0);
                strsDict[s[0]]++;
            }

            var ret = 0L;
            var combi = new List<char[]>();
            var array = "MARCH".ToCharArray();
            GetPermutation(ref combi, array, 0, array.Length - 1);

            var allCombi = new HashSet<string>();
            foreach(var c in combi)
            {
                allCombi.Add(new string(c.Take(3).OrderBy(d => d).ToArray()));
            }

            foreach(var ptn in allCombi.ToList())
            {
                if (!strsDict.ContainsKey(ptn[0]) || !strsDict.ContainsKey(ptn[1]) || !strsDict.ContainsKey(ptn[2]))
                    continue;
                ret += ((long)strsDict[ptn[0]] * (long)strsDict[ptn[1]] * (long)strsDict[ptn[2]]);
            }

            IO.Printer.Out.WriteLine(ret);
            IO.Printer.Out.Flush();
        }

        static public void GetPermutation<T>(ref List<T[]> ret, T[] arry, int i, int n)
        {
            int j;
            if (i == n)
                ret.Add(new List<T>(arry).ToArray());
            else
            {
                for (j = i; j <= n; j++)
                {
                    Swap(ref arry[i], ref arry[j]);
                    GetPermutation(ref ret, arry, i + 1, n);
                    Swap(ref arry[i], ref arry[j]); //backtrack
                }
            }
        }

        static public void Swap<T>(ref T a, ref T b)
        {
            T tmp;
            tmp = a;
            a = b;
            b = tmp;
        }

        // m????????n?????????
        public static Int64 GetMcn(int m, int n)
        {
            Int64 val;
            if (m < n) return 0;
            n = Math.Min(n, m - n);
            if (n == 0) val = 1;
            else val = GetMcn(m - 1, n - 1) * m / n;
            return val;
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