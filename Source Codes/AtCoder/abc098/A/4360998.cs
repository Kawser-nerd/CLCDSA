using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

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

    class Program
    {

        private int N;
        public void Solve()
        {
            var s = new Scanner();
            var a = s.NextInt();
            var b = s.NextInt();
            Console.WriteLine(Math.Max(Math.Max(a + b, a - b), a * b));
        }
        static void Main(string[] args) => new Program().Solve();
    }
}