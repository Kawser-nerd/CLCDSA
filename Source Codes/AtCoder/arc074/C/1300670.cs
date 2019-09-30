using System;
using System.Collections.Generic;
using System.Linq;
using System.Globalization;
using System.IO;

#region code challenges entry point
#if !SOLVER_ATWORKSPACE
class Program{static void Main(string[] args){using (var output = new CC.BP.FormattedStreamWriter(Console.OpenStandardOutput()))using (var input = new CC.BP.BufferedStreamReader(Console.OpenStandardInput()))new CC.ConcreteSolver(input, output).Do();}}
#endif
#endregion

#region code helpers boilerplate
namespace CC.BP
{    
    class BufferedStreamReader : StreamReader { const int QUEUE_INITSIZE = 1000; public BufferedStreamReader(String fileName): base(fileName) { } public BufferedStreamReader(Stream stream): base(stream) { } private Queue<string> buffer = new Queue<string>(QUEUE_INITSIZE); public override string ReadLine() { if (buffer.Count > 0) throw new InvalidOperationException("must read from buffer first"); return base.ReadLine(); } public string ReadToken() { while (buffer.Count == 0) { base.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).ToList().ForEach((t) => { buffer.Enqueue(t); }); } return buffer.Dequeue(); } public void ResetBuffer() { buffer = new Queue<string>(QUEUE_INITSIZE); } }
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
    abstract class BaseSolver
    {
        public static T[][] Create2DArray<T>(int dim1, int dim2) { var res = new T[dim1][]; for (int i = 0; i < dim1; ++i) res[i] = new T[dim2]; return res; }
        public static T[][][] Create3DArray<T>(int dim1, int dim2, int dim3) { var res = new T[dim1][][]; for (int i = 0; i < dim1; ++i) res[i] = Create2DArray<T>(dim2, dim3); return res; }
        public static T[][][][] Create4DArray<T>(int dim1, int dim2, int dim3, int dim4) { var res = new T[dim1][][][]; for (int i = 0; i < dim1; ++i) res[i] = Create3DArray<T>(dim2, dim3, dim4); return res; }
        public abstract void Do();
    }    
}
#endregion

namespace CC
{
    using CC.BP;

    class ConcreteSolver : BaseSolver
    {
        private readonly BufferedStreamReader read;
        private readonly FormattedStreamWriter write;

        public ConcreteSolver(BufferedStreamReader read, FormattedStreamWriter write)
        {
            this.read = read;
            this.write = write;
        }        

        public override void Do()
        {
            const int MOD = (int)(1e9 + 7);
            var n = read.Int();
            var m = read.Int();
            var lst = Create2DArray<List<int>>(3, n + 1);
            for (int i = 0; i < m; ++i)
            {
                var l = read.Int();
                var r = read.Int();
                var x = read.Int() - 1;
                lst[x][r] = lst[x][r] ?? new List<int>();
                lst[x][r].Add(l);
            }
            var res = Create3DArray<int>(n + 1, n + 1, n + 1);
            res[0][0][0] = 1;
            for (int i = 0; i < n; ++i)
                for (int j = i; j < n; ++j)
                    if (j != i || i == 0)
                    {                                             
                        for (int h = 0; h <= j; ++h)
                        {
                            bool can = true;
                            if (lst[0][j + 1] != null)
                            {
                                foreach (var ls in lst[0][j + 1])
                                    if (ls <= j)
                                        can = false;
                            }
                            if (lst[1][j + 1] != null)
                            {
                                foreach (var ls in lst[1][j + 1])
                                    if (ls <= i || ls > j)
                                        can = false;
                            }
                            if (lst[2][j + 1] != null)
                            {
                                foreach (var ls in lst[2][j + 1])
                                    if (ls > i)
                                        can = false;
                            }
                            if (can)
                            {
                                if (i < h)
                                    res[i][j][j + 1] += res[i][h][j];
                                else
                                    res[i][j][j + 1] += res[h][i][j];
                                res[i][j][j + 1] %= MOD;
                            }
                        }                     
                        for (int h = j + 2; h <= n; ++h)
                        {
                            bool can = true;
                            if (lst[0][h] != null)
                            {
                                foreach (var ls in lst[0][h])
                                    if (ls <= j)
                                        can = false;
                            }
                            if (lst[1][h] != null)
                            {
                                foreach (var ls in lst[1][h])
                                    if (ls <= i || ls > j)
                                        can = false;
                            }
                            if (lst[2][h] != null)
                            {
                                foreach (var ls in lst[2][h])
                                    if (ls > i)
                                        can = false;
                            }
                            if (can)
                            {
                                res[i][j][h] += res[i][j][h - 1];
                                res[i][j][h] %= MOD;
                            }
                        }
                    }
            int answer = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                {
                    if (i < j)
                        answer += res[i][j][n];
                    else
                        answer += res[j][i][n];
                    answer %= MOD;
                }
            write.WriteLine(answer * 3L % MOD);
        }
    }
}