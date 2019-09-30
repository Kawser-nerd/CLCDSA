using System;
using System.Collections.Generic;
using System.IO;

#region Program
namespace Program
{
    #region Solver
    public class Solver
    {
        static IO.StreamScanner
        sc = new IO.StreamScanner(Console.OpenStandardInput());

        static int N;
        static int v;
        static int w;

        static int[] aryV;
        static int[] aryW;

        // SegmentTree ???
        static int size;

        #region Solver
        static Solver()
        {
            N = sc.Integer();

            aryV = new int[N];
            aryW = new int[N];

            for (int i = 0; i < N; i++)
            {
                v = sc.Integer();
                w = sc.Integer();

                aryV[i] = v;
                aryW[i] = w;
            }
            Array.Sort(aryV, aryW);
        }
        #endregion

        #region Solve
        public void Solve()
        {
            int maxW = 0;
            Array.ForEach(aryW, delegate (int i)
            {
                maxW = Math.Max(maxW, i);
            });

            // SegmentTree ??? (2 * N - 1)
            size = 2 * maxW - 1;

            // SegmentTree??
            SegmentTree st = new SegmentTree(size);

            // aryV aryW
            // SegmentTree ?? ??
            for (int i = 0; i < N; i++)
            {
                int tmp = aryV[i];

                // aryW??????
                List<int> descList = new List<int>();
                for (int j = 0; i + j < N; j++)
                {
                    int idx = i + j;
                    if (tmp != aryV[idx]) break;
                    descList.Add(aryW[idx]);
                }
                // ???
                descList.Sort(CompareDescending);

                for (int j = 0; j < descList.Count; j++)
                {
                    // ??
                    // ?????????????????
                    //int max = st.query(0, descList[j]);
                    int max = st.query(0, descList[j] - 1);

                    // ??
                    st.update(descList[j], max + 1); ;
                }
                // ???? ?????
                // ?????????
                i = i + (descList.Count - 1);
            }

            // ??
            // ?? ????
            Console.WriteLine(st.query(0, st.size()));
        }
        #endregion

        #region CompareDescending
        // ???int????????????
        static int CompareDescending(int x, int y)
        {
            // ??
            return y.CompareTo(x);
        }
        #endregion
    }
    #endregion

    #region SegmentTree
    // SegmentTree ??2?? ??O(log n)
    public class SegmentTree
    {
        // ??? root??
        int n;

        // ????? ??
        static int min = 0;

        // SegmentTree ???????
        int[] data;

        // ???
        public SegmentTree(int size)
        {
            // Simplification
            // SegmentTree?????2???????
            // ??? (2 * N - 1) ???
            // 7 ??? 8?9 ?? 16 ???????
            for (n = 1; n < size; n *= 2) ;

            // ????? min (????? max)
            // ?? ????
            data = new int[n];
        }

        // update
        // k (0-origin) val
        // to v
        public void update(int k, int v)
        {
            // reaf???????
            k += (((n / 2) - 1) - 1);
            data[k] = v;

            // climb tree update
            for (; k > 0;)
            {
                // parent
                k = (k - 1) / 2;

                // ????? Math.Max (????? Math.Min)
                // left ? right
                data[k] = Math.Max(
                      data[k * 2 + 1]
                    , data[k * 2 + 2]
                );

            }

        }

        // first call
        public int query(int a, int b)
        {
            // reaf ? ???(0? (n / 2))
            // n - (n / 2)
            // = (n / 2)
            return query(a, b, 0, 0, (n / 2));
        }

        // ??[a, b)?????????
        // k:?????
        // l:Left
        // r:Right
        // ??k????[l, r)???????
        // query(a, b, 0, 0, n)?????
        private int query(int a, int b, int k, int l, int r)
        {
            // ??[a, b)???[l, r)
            if (r <= a || b <= l)
                // ?No Overlap?
                // ????? min (????? max)
                return min;
            if (a <= l && r <= b)
                // ?Total Overlap?
                return data[k];
            else
            {
                //if (n - 1 < k * 2 + 2) return data[k];
                // ?Partial Overlap?
                // ??????k * 2 + 1 ? k * 2 + 2 ?2?
                // ????????????????????
                int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

                // ????? Math.Max (????? Math.Min)
                return Math.Max(vl, vr);
            }
        }
        public int size()
        {
            return n;
        }
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