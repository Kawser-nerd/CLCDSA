using System;
using System.Collections.Generic;
using System.Linq;
using System.Globalization;
using System.IO;
using System.Text;

#region code challenges entry point
#if !SOLVER_ATWORKSPACE
class Program{static void Main(string[] args){using (var output = new CC.FormattedStreamWriter(Console.OpenStandardOutput())) using (var error = new CC.FormattedStreamWriter(Console.OpenStandardError())) using (var input = new CC.BufferedStreamReader(Console.OpenStandardInput()))new CC.Solver(input, output, error).Do();}}
#endif
#endregion

#region code helpers boilerplate
namespace CC
{
    class BufferedStreamReader : StreamReader { const int QUEUE_INITSIZE = 10000; public BufferedStreamReader(String fileName) : base(fileName) { } public BufferedStreamReader(Stream stream) : base(stream) { } private Queue<string> buffer = new Queue<string>(QUEUE_INITSIZE); public override string ReadLine() { if (buffer.Count > 0) throw new InvalidOperationException("must read from buffer first"); return base.ReadLine(); } public string ReadToken() { while (buffer.Count == 0) { base.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).ToList().ForEach((t) => { buffer.Enqueue(t); }); } return buffer.Dequeue(); } public void ResetBuffer() { buffer = new Queue<string>(QUEUE_INITSIZE); } }
    class FormattedStreamWriter : StreamWriter { public FormattedStreamWriter(Stream stream) : base(stream) { } public FormattedStreamWriter(string filePath) : base(filePath) { } public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } } }
    static class IOExtensions
    {
        public static string String(this BufferedStreamReader reader) { return reader.ReadToken(); }
        public static string[] StringArray(this BufferedStreamReader reader, int n) { var array = new string[n]; for (int i = 0; i < n; ++i) { array[i] = reader.ReadToken(); } return array; }
        public static int Int(this BufferedStreamReader reader) { return int.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static int[] IntArray(this BufferedStreamReader reader, int n) { var array = new int[n]; for (int i = 0; i < n; ++i) { array[i] = int.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static uint UnsignedInt(this BufferedStreamReader reader) { return uint.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static long Long(this BufferedStreamReader reader) { return long.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static long[] LongArray(this BufferedStreamReader reader, int n) { var array = new long[n]; for (int i = 0; i < n; ++i) { array[i] = long.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static ulong UnsignedLong(this BufferedStreamReader reader) { return ulong.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static double Double(this BufferedStreamReader reader) { return double.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static double[] DoubleArray(this BufferedStreamReader reader, int n) { var array = new double[n]; for (int i = 0; i < n; ++i) { array[i] = double.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static decimal Decimal(this BufferedStreamReader reader) { return decimal.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static decimal[] DecimalArray(this BufferedStreamReader reader, int n) { var array = new decimal[n]; for (int i = 0; i < n; ++i) { array[i] = decimal.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static void ArrayLine<T>(this FormattedStreamWriter writer, T[] array, int n, string format = "{0}", string separator = " ") { for (int i = 0; i < n; ++i) { if (i > 0) writer.Write(separator); writer.Write(format, array[i]); } writer.WriteLine(); }
        public static void ArrayLine<T>(this FormattedStreamWriter writer, T[] array, string format = "{0}", string separator = " ") { writer.ArrayLine(array, array.Length, format, separator); }
    }
    partial class Solver
    {
        protected readonly BufferedStreamReader read;
        protected readonly FormattedStreamWriter write;
        protected readonly FormattedStreamWriter error;
        public Solver(BufferedStreamReader read, FormattedStreamWriter write, FormattedStreamWriter error) { this.read = read; this.write = write; this.error = error; }
        public static T[][] Create2DArray<T>(int dim1, int dim2) { var res = new T[dim1][]; for (int i = 0; i < dim1; ++i) res[i] = new T[dim2]; return res; }
        public static T[][][] Create3DArray<T>(int dim1, int dim2, int dim3) { var res = new T[dim1][][]; for (int i = 0; i < dim1; ++i) res[i] = Create2DArray<T>(dim2, dim3); return res; }
        public static T[][][][] Create4DArray<T>(int dim1, int dim2, int dim3, int dim4) { var res = new T[dim1][][][]; for (int i = 0; i < dim1; ++i) res[i] = Create3DArray<T>(dim2, dim3, dim4); return res; }
        public void Do() { Run(); }
    }
    static class Utils
    {
        public static void Swap<T>(ref T one, ref T second) { T tmp = one; one = second; second = tmp; }
    }
}
#endregion

namespace CC
{
    using System.Diagnostics;
    using System.Text;

    partial class Solver
    {
        public void Run()
        {
            var n = read.Int();
            n *= 2;
            var c = new int[n];
            var a = new int[n];
            for (int i = 0; i < n; ++i)
            {
                c[i] = read.String() == "B"? 1: 0;
                a[i] = read.Int();
            }
            var same = Create2DArray<int>(2, n / 2 + 1);
            var nots = Create3DArray<int>(2, n / 2 + 1, n / 2 + 1);
            for (int i = 1; i < n; ++i)
                for (int j = 0; j < i; ++j)
                    if (c[i] == c[j] && a[i] < a[j])
                        ++same[c[i]][a[i]];
                    else if (c[i] != c[j])
                        ++nots[c[i]][a[i]][a[j]];

            n /= 2;
            for (int h = 0; h < 2; ++h)
                for (int i = 1; i <= n; ++i)
                    for (int j = n - 1; j >= 1; --j)
                        nots[h][i][j] += nots[h][i][j + 1];

            var dp = Create2DArray<int>(n + 1, n + 1);

            for (int i = 0; i <= n; ++i)
                for (int j = 0; j <= n; ++j)
                    if (i != 0 || j != 0)
                    {
                        dp[i][j] = int.MaxValue;
                        if (i > 0)
                            dp[i][j] = Math.Min(dp[i][j], dp[i - 1][j] + same[0][i] + (j < n ? nots[0][i][j + 1]: 0));
                        if (j > 0)
                            dp[i][j] = Math.Min(dp[i][j], dp[i][j - 1] + same[1][j] + (i < n ? nots[1][j][i + 1]: 0));
                    }
            write.WriteLine(dp[n][n]);
        }
    }
}