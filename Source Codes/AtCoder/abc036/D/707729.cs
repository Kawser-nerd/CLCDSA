using System;
using System.Collections.Generic;
using System.IO;

#region Program
namespace Program
{
    #region Solver
    public class Solver
    {
        public IO.StreamScanner
        sc = new IO.StreamScanner(Console.OpenStandardInput());

        // ??? (2 <= N <= 10^5)
        static int N;

        // ?ab
        int[] ab;

        // ? a?b ?b?a???List
        List<int>[] abList;

        #region Solver
        public Solver()
        {
            N = sc.Integer();
            ab = new int[N - 1];

            // ? a?b ?b?a???List???
            // ????????
            abList = new List<int>[N];

            // List????
            for (int i = 0; i < N; ++i) abList[i] = new List<int>();

            for (int i = 0; i < N - 1; ++i)
            {
                ab = sc.Integer(2);
                abList[ab[0] - 1].Add(ab[1] - 1);
                abList[ab[1] - 1].Add(ab[0] - 1);
            }
        }
        #endregion

        #region Solve
        public void Solve()
        {
            wb[] ans = paintColor(-1, 0);
            Console.WriteLine((ans[0] + ans[1]).num);
        }
        #endregion

        #region paintColor
        wb[] paintColor(int from, int now)
        {
            var ret = new wb[2] { 1, 1 };
            foreach (var to in abList[now])
            {
                // ?????? ???????????
                if (from == to) continue;
                var res = paintColor(now, to);
                // ???+?
                ret[0] *= res[0] + res[1];
                // ???
                ret[1] *= res[0];
            }
            return ret;
        }
        #endregion

        #region wb
        // ?????????????????
        public partial struct wb
        {
            public const long Mod = (long)1e9 + 7;
            public long num;
            public wb(long n) : this()
            {
                num = n % Mod;
            }
            public static wb
                operator +(wb left, wb right)
            {
                var n = left.num + right.num;
                if (n >= Mod) n -= Mod;
                return n;
            }
            public static wb
                operator *(wb left, wb right)
            {
                return left.num * right.num;
            }
            public static implicit operator wb(long n)
            {
                return new wb(n);
            }
        }
        #endregion
    }
    #endregion
}
#endregion

#region Execute
class Execute
{
    public static void Main(string[] args)
    {
        new Program.Solver().Solve();
        Program.IO.Printer.Out.Flush();
    }
}
#endregion

#region Program.IO
namespace Program.IO
{
    using System.Text;
    using System.Globalization;
    using System.Linq;
    public class Printer : StreamWriter
    {
        static Printer()
        {
            Out = new Printer(Console.OpenStandardOutput())
            {
                AutoFlush = false
            };
        }
        public static Printer Out
        {
            get;
            set;
        }
        public override IFormatProvider FormatProvider
        {
            get
            {
                return CultureInfo.InvariantCulture;
            }
        }
        public Printer(System.IO.Stream stream)
            : base(stream, new UTF8Encoding(false, true))
        {
        }
        public Printer(System.IO.Stream stream, Encoding encoding)
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
        public readonly Stream str;
        private readonly byte[] buf = new byte[1024];
        private int len, ptr;
        public bool isEof = false;
        public StreamScanner(Stream stream)
        {
            str = stream;
        }
        private T[] enumerate<T>(int n, Func<T> f)
        {
            var a = new T[n];
            for (int i = 0; i < n; ++i) a[i] = f();
            return a;
        }
        public long Long()
        {
            if (isEof)
            {
                return long.MinValue;
            }
            long ret = 0;
            byte b = 0;
            var ng = false;
            do
            {
                b = read();
            }
            while (b != '-' && (b < '0' || '9' < b));
            if (b == '-')
            {
                ng = true;
                b = read();
            }
            for (; true; b = read())
            {
                if (b < '0' || '9' < b)
                {
                    return ng ? -ret : ret;
                }
                else ret = ret * 10 + b - '0';
            }
        }
        public long[] Long(int n)
        {
            return enumerate(n, Long);
        }
        public int Integer()
        {
            return (isEof) ? int.MinValue : (int)Long();
        }
        public int[] Integer(int n)
        {
            return enumerate(n, Integer);
        }
        public char[] Char(int n)
        {
            return enumerate(n, Char);
        }
        public char Char()
        {
            byte b = 0;
            do
            {
                b = read();
            }
            while ((b < 33 || 126 < b) && !isEof);
            return (char)b;
        }
        public string Scan()
        {
            var sb = new StringBuilder();
            for (var b = Char(); b >= 33 && b <= 126; b = (char)read())
            {
                sb.Append(b);
            }
            return sb.ToString();
        }
        private byte read()
        {
            if (isEof)
            {
                return 0;
            }
            if (ptr >= len)
            {
                ptr = 0;
                if ((len = str.Read(buf, 0, 1024)) <= 0)
                {
                    isEof = true;
                    return 0;
                }
            }
            return buf[ptr++];
        }
    }
}
#endregion