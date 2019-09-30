using System;
using System.IO;

#region Program
namespace Program
{
    #region Solver
    public class Solver
    {
        static IO.StreamScanner
        sc = new IO.StreamScanner(Console.OpenStandardInput());

        static int H;
        static int W;
        static int[] HW;

        // ???????????????????
        static readonly int[] moveY = { 1, 0, -1, 0, 1, -1, 1, -1 };
        static readonly int[] moveX = { 0, 1, 0, -1, 1, 1, -1, -1 };
        static readonly int move = 8;

        static readonly char d = '.';
        static readonly char s = '#';
        static readonly string impossible = "impossible";
        static readonly string possible = "possible";

        static readonly bool white;
        static readonly bool black = true;

        static bool[,] after;
        static bool[,] before;
        static bool[,] re;

        #region Solver
        static Solver()
        {
            HW = sc.Integer(2);
            H = HW[0];
            W = HW[1];

            // ??????????????
            after = new bool[H, W];
            before = new bool[H, W];
            re = new bool[H, W];

            for (int i = 0; i < H; i++)
            {
                string tmp = sc.Scan();
                for (int j = 0; j < W; j++)
                {
                    if (tmp[j] == s)
                    {
                        after[i, j] = black;
                        before[i, j] = black;
                    }
                }
            }
        }
        #endregion

        #region Solve
        public void Solve()
        {
            // ?????? white
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    WhiteBlack(i, j, after, before, white);
            // ????? black
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    WhiteBlack(i, j, before, re, black);
            // ????
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (after[i, j] != re[i, j])
                    {
                        // ????????
                        Console.WriteLine(impossible);
                        return;
                    }
                }
            }
            // ????
            Console.WriteLine(possible);
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Console.Write(before[i, j] ? s : d);
                }
                Console.WriteLine();
            }
        }
        #endregion

        #region WhiteBlack
        public void WhiteBlack(
            int y, int x, bool[,] self, bool[,] other, bool wb)
        {
            // ??????(?)?????????
            if (self[y, x] == !wb) return;

            // ????
            other[y, x] = wb;

            // ??????(?)????????(?)???
            for (int i = 0; i < move; i++)
            {
                int[] nextYX = { y + moveY[i], x + moveX[i] };
                // ??
                if (nextYX[0] >= H || nextYX[1] >= W
                    || nextYX[0] < 0 || nextYX[1] < 0) continue;
                // ??
                other[nextYX[0], nextYX[1]] = wb;
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