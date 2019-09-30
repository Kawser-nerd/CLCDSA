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

        int N;
        int M;

        int[] a;
        int[] b;
        int[] y;

        int Q;
        int[] v;
        int[] w;
        int[] z;

        int[] wCopy;
        int[] yCopy;

        int[] ans;

        #region Solver
        public Solver()
        {
            N = sc.Integer();
            M = sc.Integer();

            a = new int[M];
            b = new int[M];
            y = new int[M];
            yCopy = new int[M];

            for (int i = 0; i < M; i++)
            {
                a[i] = sc.Integer();
                b[i] = sc.Integer();
                y[i] = sc.Integer();
            }

            Q = sc.Integer();
            v = new int[Q];
            w = new int[Q];
            wCopy = new int[Q];
            z = new int[Q];
            ans = new int[Q];
            for (int i = 0; i < Q; i++)
            {
                v[i] = sc.Integer();
                w[i] = sc.Integer();
                z[i] = i;
            }

            // deep copy all
            w.CopyTo(wCopy, 0);
            y.CopyTo(yCopy, 0);
        }
        #endregion

        #region Solve
        public void Solve()
        {
            // ???? ??? ???
            Array.Sort(y, a);
            Array.Sort(yCopy, b);

            // ???????? ??? ???
            Array.Sort(w, v);
            Array.Sort(wCopy, z);

            UnionFind uf = new UnionFind(N + 1);

            // ???????? ??????
            int j = M - 1;
            for (int i = Q - 1; i >= 0; i--)
            {
                // ???? ??????
                for (; j >= 0; j--)
                {
                    // ?????????
                    if (y[j] <= w[i]) break;

                    // ??????????
                    uf.unionSet(a[j], b[j]);
                }
                // ???????
                ans[z[i]] = uf.answer(v[i]);
            }

            // ??
            for (int i = 0; i < Q; i++) Console.WriteLine(ans[i]);
        }
        #endregion

        #region UnionFind
        struct UnionFind
        {
            // ????????????????????????
            static readonly int init = 1;

            int len;
            public int[] data;
            public int[] cnt;

            #region UnionFind
            public UnionFind(int len)
            {
                this.len = len;
                data = new int[len];
                cnt = new int[len];

                for (int i = 1; i < len; i++)
                {
                    data[i] = i;
                    cnt[i] = init;
                }
            }
            #endregion

            #region unionSet
            public void unionSet(int x, int y)
            {
                x = root(x);
                y = root(y);

                if (x == y) return;

                if (x != y)
                {
                    // ????????????????
                    if (data[y] < data[x]) swap(ref x, ref y);

                    // ???????????????
                    data[y] = x;

                    // ??????????????????????
                    cnt[x] += cnt[y];
                }
            }
            #endregion

            #region answer
            public int answer(int x)
            {
                return cnt[root(x)];
            }
            #endregion

            #region root
            int root(int x)
            {
                return data[x] == x ?
                      x
                    : data[x] = root(data[x]);
            }
            #endregion

            #region swap
            void swap<T>(ref T a, ref T b)
            {
                var tmp = a;
                a = b;
                b = tmp;
            }
            #endregion

            #region same
            public bool same(int x, int y)
            {
                return root(x) == root(y);
            }
            #endregion
        };
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