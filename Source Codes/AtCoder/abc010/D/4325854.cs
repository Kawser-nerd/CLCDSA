using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Contest
{
    using C = System.Int32;
    class Scanner
    {
        public Scanner()
        {
            _stream = new StreamReader(Console.OpenStandardInput());
            _pos = 0;
            _line = new string[0];
            _separator = ' ';
        }

        private char _separator;
        private StreamReader _stream;
        private int _pos;
        private string[] _line;

        #region get a element
        public string Next()
        {
            if (_pos >= _line.Length)
            {
                _line = _stream.ReadLine().Split(_separator);
                _pos = 0;
            }
            return _line[_pos++];
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public double NextDouble()
        {
            return double.Parse(Next());
        }
        #endregion
        #region convert array
        private int[] ToIntArray(string[] array)
        {
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        private long[] ToLongArray(string[] array)
        {
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
        private double[] ToDoubleArray(string[] array)
        {
            var result = new double[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = double.Parse(array[i]);
            }

            return result;
        }
        #endregion
        #region get row elements
        #region get array
        public string[] Array()
        {
            if (_pos >= _line.Length)
                _line = _stream.ReadLine().Split(_separator);

            _pos = _line.Length;
            return _line;
        }
        public int[] IntArray()
        {
            return ToIntArray(Array());
        }
        public long[] LongArray()
        {
            return ToLongArray(Array());
        }
        public double[] DoubleArray()
        {
            return ToDoubleArray(Array());
        }
        #endregion
        #region get 2~4 elements
        public void GetRow(out string a, out string b)
        {
            a = Next();
            b = Next();
        }
        public void GetRow(out string a, out string b, out string c)
        {
            a = Next();
            b = Next();
            c = Next();
        }
        public void GetRow(out string a, out string b, out string c, out string d)
        {
            a = Next();
            b = Next();
            c = Next();
            d = Next();
        }

        public void GetIntRow(out int a, out int b)
        {
            a = NextInt();
            b = NextInt();
        }
        public void GetIntRow(out int a, out int b, out int c)
        {
            a = NextInt();
            b = NextInt();
            c = NextInt();
        }
        public void GetIntRow(out int a, out int b, out int c, out int d)
        {
            a = NextInt();
            b = NextInt();
            c = NextInt();
            d = NextInt();
        }

        public void GetLongRow(out long a, out long b)
        {
            a = NextLong();
            b = NextLong();
        }
        public void GetLongRow(out long a, out long b, out long c)
        {
            a = NextLong();
            b = NextLong();
            c = NextLong();
        }
        public void GetLongRow(out long a, out long b, out long c, out long d)
        {
            a = NextLong();
            b = NextLong();
            c = NextLong();
            d = NextLong();
        }

        public void GetDoubleRow(out double a, out double b)
        {
            a = NextDouble();
            b = NextDouble();
        }
        public void GetDoubleRow(out double a, out double b, out double c)
        {
            a = NextDouble();
            b = NextDouble();
            c = NextDouble();
        }
        public void GetDoubleRow(out double a, out double b, out double c, out double d)
        {
            a = NextDouble();
            b = NextDouble();
            c = NextDouble();
            d = NextDouble();
        }
        #endregion
        #endregion
        #region get 2~4 column elements
        public void GetColumn(int n, out string[] a)
        {
            a = new string[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = Next();
            }
        }
        public void GetColumn(int n, out string[] a, out string[] b)
        {
            a = new string[n];
            b = new string[n];
            for (int i = 0; i < n; i++)
            {
                GetRow(out a[i], out b[i]);
            }
        }
        public void GetColumn(int n, out string[] a, out string[] b, out string[] c)
        {
            a = new string[n];
            b = new string[n];
            c = new string[n];
            for (int i = 0; i < n; i++)
            {
                GetRow(out a[i], out b[i], out c[i]);
            }
        }
        public void GetColumn(int n, out string[] a, out string[] b, out string[] c, out string[] d)
        {
            a = new string[n];
            b = new string[n];
            c = new string[n];
            d = new string[n];
            for (int i = 0; i < n; i++)
            {
                GetRow(out a[i], out b[i], out c[i], out d[i]);
            }
        }

        public void GetIntColumn(int n, out int[] a)
        {
            string[] sa;
            GetColumn(n, out sa);
            a = ToIntArray(sa);
        }
        public void GetIntColumn(int n, out int[] a, out int[] b)
        {
            string[] sa, sb;
            GetColumn(n, out sa, out sb);
            a = ToIntArray(sa);
            b = ToIntArray(sb);
        }
        public void GetIntColumn(int n, out int[] a, out int[] b, out int[] c)
        {
            string[] sa, sb, sc;
            GetColumn(n, out sa, out sb, out sc);
            a = ToIntArray(sa);
            b = ToIntArray(sb);
            c = ToIntArray(sc);
        }
        public void GetIntColumn(int n, out int[] a, out int[] b, out int[] c, out int[] d)
        {
            string[] sa, sb, sc, sd;
            GetColumn(n, out sa, out sb, out sc, out sd);
            a = ToIntArray(sa);
            b = ToIntArray(sb);
            c = ToIntArray(sc);
            d = ToIntArray(sd);
        }

        public void GetLongColumn(int n, out long[] a)
        {
            string[] sa;
            GetColumn(n, out sa);
            a = ToLongArray(sa);
        }
        public void GetLongColumn(int n, out long[] a, out long[] b)
        {
            string[] sa, sb;
            GetColumn(n, out sa, out sb);
            a = ToLongArray(sa);
            b = ToLongArray(sb);
        }
        public void GetLongColumn(int n, out long[] a, out long[] b, out long[] c)
        {
            string[] sa, sb, sc;
            GetColumn(n, out sa, out sb, out sc);
            a = ToLongArray(sa);
            b = ToLongArray(sb);
            c = ToLongArray(sc);
        }
        public void GetLongColumn(int n, out long[] a, out long[] b, out long[] c, out long[] d)
        {
            string[] sa, sb, sc, sd;
            GetColumn(n, out sa, out sb, out sc, out sd);
            a = ToLongArray(sa);
            b = ToLongArray(sb);
            c = ToLongArray(sc);
            d = ToLongArray(sd);
        }

        public void GetDoubleColumn(int n, out double[] a)
        {
            string[] sa;
            GetColumn(n, out sa);
            a = ToDoubleArray(sa);
        }
        public void GetDoubleColumn(int n, out double[] a, out double[] b)
        {
            string[] sa, sb;
            GetColumn(n, out sa, out sb);
            a = ToDoubleArray(sa);
            b = ToDoubleArray(sb);
        }
        public void GetDoubleColumn(int n, out double[] a, out double[] b, out double[] c)
        {
            string[] sa, sb, sc;
            GetColumn(n, out sa, out sb, out sc);
            a = ToDoubleArray(sa);
            b = ToDoubleArray(sb);
            c = ToDoubleArray(sc);
        }
        public void GetDoubleColumn(int n, out double[] a, out double[] b, out double[] c, out double[] d)
        {
            string[] sa, sb, sc, sd;
            GetColumn(n, out sa, out sb, out sc, out sd);
            a = ToDoubleArray(sa);
            b = ToDoubleArray(sb);
            c = ToDoubleArray(sc);
            d = ToDoubleArray(sd);
        }
        #endregion
        #region get matrix
        string[][] GetMatrix(int h)
        {
            string[][] result = new string[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = Array();
            }

            return result;

        }
        int[][] GetIntMatrix(int h)
        {
            int[][] result = new int[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = IntArray();
            }

            return result;
        }
        long[][] GetLongMatrix(int h)
        {
            long[][] result = new long[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = LongArray();
            }

            return result;
        }
        double[][] GetDoubleMatrix(int h)
        {
            double[][] result = new double[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = DoubleArray();
            }

            return result;
        }
        char[][] GetCharMatrix(int h)
        {
            char[][] result = new char[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = Next().ToCharArray();
            }

            return result;
        }
        #endregion
    }


    #region Max Flow
    /// <summary>
    /// ???????????????????????????
    /// </summary>
    public class MaxFlow
    {
        readonly List<Edge>[] G;
        readonly int[] lv, iter;
        /// <summary>
        /// ??? <paramref name="V"/> ??????????????????
        /// </summary>
        /// <param name="V">????</param>
        /// <remarks>????? O(<paramref name="V"/>) ????????</remarks>
        public MaxFlow(int V)
        {
            G = new List<Edge>[V];
            lv = new int[V];
            iter = new int[V];
            for (int i = 0; i < G.Length; i++)
                G[i] = new List<Edge>();
        }

        /// <summary>
        /// ?? <paramref name="from"/> ???? <paramref name="to"/> ???? <paramref name="cap"/> ???????????
        /// </summary>
        /// <param name="from">???????? 0-indexed ????</param>
        /// <param name="to">???????? 0-indexed ????</param>
        /// <param name="cap">????</param>
        /// <remarks>????? O(1) ????????</remarks>
        public void AddDirectedEdge(int from, int to, C cap)
        {
            addEdge(from, to, cap, 0);
        }

        /// <summary>
        /// ?? <paramref name="from"/> ???? <paramref name="to"/> ???? <paramref name="cap"/> ???????????
        /// </summary>
        /// <param name="from">???????? 0-indexed ????</param>
        /// <param name="to">???????? 0-indexed ????</param>
        /// <param name="cap">????</param>
        /// <remarks>????? O(1) ????????</remarks>
        public void AddUndirectedEdge(int from, int to, C cap)
        {
            addEdge(from, to, cap, cap);
        }
        void addEdge(int f, int t, C c1, C c2)
        {
            var a = new Edge(t, c1);
            var b = new Edge(f, c2);
            Edge.Link(a, b);
            G[f].Add(a);
            G[t].Add(b);
        }


        /// <summary>
        /// ?? <paramref name="src"/> ???? <paramref name="sink"/> ?????? <paramref name="f"/> ???????????
        /// </summary>
        /// <param name="src">????????? 0-indexed ????</param>
        /// <param name="sink">????????? 0-indexed ????</param>
        /// <param name="f">??????????????????-1????????????????</param>
        /// <remarks>?????Dinic??????????? O(EV^2) ????????V??????E??????????</remarks>
        public C Execute(int src, int sink, C f = -1)
        {
            C flow = 0;
            if (f < 0) f = C.MaxValue;
            while (f > 0)
            {
                bfs(src);
                if (lv[sink] == 0) return flow;
                Array.Clear(iter, 0, iter.Length);
                C df;
                while ((df = dfs(src, sink, f)) > 0) { flow += df; f -= df; }
            }
            return flow;
        }

        void bfs(int s)
        {
            Array.Clear(lv, 0, lv.Length);
            var q = new Queue<int>();
            lv[s] = 1;
            q.Enqueue(s);
            while (q.Count > 0)
            {
                var v = q.Dequeue();
                foreach (var e in G[v])
                    if (e.Cap > 0 && lv[e.To] == 0)
                    {
                        lv[e.To] = lv[v] + 1;
                        q.Enqueue(e.To);
                    }
            }

        }
        C dfs(int v, int t, C f)
        {
            if (v == t) return f;
            C ret = 0;
            for (; iter[v] < G[v].Count; iter[v]++)
            {
                var e = G[v][iter[v]];
                if (e.Cap <= 0 || lv[v] >= lv[e.To]) continue;
                C df = dfs(e.To, t, Math.Min(f, e.Cap));
                if (df <= 0) continue;
                e.Cap -= df;
                e.Rev.Cap += df;
                ret += df; f -= df;
                if (f == 0) break;
            }
            return ret;

        }
        class Edge
        {
            public static void Link(Edge e1, Edge e2)
            {
                e1.Rev = e2; e2.Rev = e1;
            }
            public int To { get; private set; }
            public Edge Rev { get; private set; }
            public C Cap { get; set; }
            public Edge(int t, C c)
            {
                To = t;
                Cap = c;
            }
            public override string ToString()
            {
                return string.Format("to: {0}, cap: {1}", To, Cap);
            }
        }


    }
    #endregion
    class Program
    {
        private int N, G, E;
        private int[] P;
        private int[] A, B;

        private void Scan()
        {
            var line = Console.ReadLine().Split(' ');
            N = int.Parse(line[0]);
            G = int.Parse(line[1]);
            E = int.Parse(line[2]);
            P = new int[G];
            line = Console.ReadLine().Split(' ');
            for (int i = 0; i < G; i++)
            {
                P[i] = int.Parse(line[i]);
            }
            A = new int[E];
            B = new int[E];
            for (int i = 0; i < E; i++)
            {
                line = Console.ReadLine().Split(' ');
                A[i] = int.Parse(line[0]);
                B[i] = int.Parse(line[1]);
            }
        }
        public void Solve()
        {
            Scan();
            MaxFlow flow = new MaxFlow(N + 1);
            for (int i = 0; i < E; i++)
            {
                flow.AddUndirectedEdge(A[i], B[i], 1);
            }

            foreach (var i in P)
            {
                flow.AddDirectedEdge(i, N, 1);
            }

            Console.WriteLine(flow.Execute(0, N));
        }

        static void Main(string[] args) => new Program().Solve();
    }
}