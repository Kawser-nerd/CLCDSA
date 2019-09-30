using System;
using System.Collections.Generic;
using System.IO;

namespace Contest
{
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

        public string[][] GetMatrix(int h)
        {
            string[][] result = new string[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = Array();
            }

            return result;

        }

        public int[][] GetIntMatrix(int h)
        {
            int[][] result = new int[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = IntArray();
            }

            return result;
        }

        public long[][] GetLongMatrix(int h)
        {
            long[][] result = new long[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = LongArray();
            }

            return result;
        }

        public double[][] GetDoubleMatrix(int h)
        {
            double[][] result = new double[h][];
            for (int i = 0; i < h; i++)
            {
                result[i] = DoubleArray();
            }

            return result;
        }

        public char[][] GetCharMatrix(int h)
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

    class Program
    {
        private const long Mod = 1000000007;
        private int N, A, B;
        private int NN;

        int BitCount(int n)
        {
            n = (n & 0x55555555) + (n >> 1 & 0x55555555);
            n = (n & 0x33333333) + (n >> 2 & 0x33333333);
            n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
            return (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
        }

        public void Solve()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            A = sc.NextInt();
            B = sc.NextInt();
            NN = 1 << N;
            if (BitCount(A) % 2 == BitCount(B) % 2)
            {
                Console.WriteLine("NO");
                return;
            }
            Console.WriteLine("YES");
            Console.WriteLine(string.Join(" ", S(N, A, B)));
        }

        private int[] S(int n, int a, int b)
        {
            //Console.WriteLine($"{n} {a} {b}");
            if (n == 1)
            {
                return new int[] { a, b };
            }
            int cpA = 0;
            int cpB = a ^ b;
            int diffBit;
            for (diffBit = 0; diffBit < n; diffBit++)
            {
                if ((cpB & (1 << diffBit)) > 0) break;
            }

            int aa = 0;
            int bb = Skip(n, cpB, diffBit);
            var left = S(n - 1, aa, aa ^ 1);
            var right = S(n - 1, aa ^ 1, bb);
            int nn = 1 << n;
            var ans = new int[nn];
            for (int i = 0; i < (nn >> 1); i++)
            {
                ans[i] = Add(n, left[i], diffBit);
                ans[i + (nn >> 1)] = Add(n, right[i], diffBit) | (1 << diffBit);
            }

            for (int i = 0; i < nn; i++)
            {
                ans[i] ^= a;
            }

            return ans;
        }

        /// <summary>
        /// 2?n??bit???0?????
        /// </summary>
        /// <param name="n"></param>
        /// <param name="i"></param>
        /// <param name="bit"></param>
        /// <returns></returns>
        private int Add(int n, int i, int bit)
        {
            int res = 0;
            for (int j = 0; j < n; j++)
            {
                int b = 1 << j;
                if (j < bit)
                {
                    res |= i & b;
                }
                else if (j > bit)
                {
                    res |= (i & (b >> 1)) << 1;
                }
            }

            return res;
        }

        /// <summary>
        /// ??n??i?bit??????
        /// </summary>
        /// <param name="n"></param>
        /// <param name="i"></param>
        /// <param name="bit"></param>
        /// <returns></returns>
        private int Skip(int n, int i, int bit)
        {
            int res = 0;
            for (int j = 0; j < n; j++)
            {
                if (j < bit)
                {
                    res |= i & (1 << j);
                }
                else if (j > bit)
                {
                    res |= (i & (1 << j)) >> 1;
                }
            }

            return res;
        }


        static void Main(string[] args) => new Program().Solve();
    }
}