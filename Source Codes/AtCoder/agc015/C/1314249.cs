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
    static class Utils
    {
        public static void Swap<T>(ref T one, ref T second) { T tmp = one; one = second; second = tmp; }
    }
}
#endregion

namespace CC
{
    using CC.BP;
    using System.Diagnostics;

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
            var n = read.Int();
            var m = read.Int();
            var q = read.Int();
            var s = new string[n];
            var dot = Create2DArray<int>(n + 1, m + 1);
            var hor = Create2DArray<int>(n + 1, m + 1);
            var ver = Create2DArray<int>(n + 1, m + 1);
            for (int i = 0; i < n; ++i)
            {
                s[i] = read.String();
                for (int j = 0; j < m; ++j)
                {
                    dot[i + 1][j + 1] = s[i][j] - '0' + dot[i][j + 1] + dot[i + 1][j] - dot[i][j];
                    var hr = 0;
                    if (j > 0 && s[i][j] - '0' == 1 && s[i][j - 1] - '0' == 1)
                        hr = 1;
                    hor[i + 1][j + 1] = hr + hor[i][j + 1] + hor[i + 1][j] - hor[i][j];
                    var vr = 0;
                    if (i > 0 && s[i][j] - '0' == 1 && s[i - 1][j] - '0' == 1)
                        vr = 1;
                    ver[i + 1][j + 1] = vr + ver[i][j + 1] + ver[i + 1][j] - ver[i][j];
                }
            }
            while (q-- > 0)
            {
                var x1 = read.Int() - 1;
                var y1 = read.Int() - 1;
                var x2 = read.Int() - 1;
                var y2 = read.Int() - 1;
                var dts = dot[x2 + 1][y2 + 1] + dot[x1][y1] - dot[x2 + 1][y1] - dot[x1][y2 + 1];
                var hors = 0;
                var verts = 0;
                if (y2 > y1)
                    hors = hor[x2 + 1][y2 + 1] + hor[x1][y1 + 1] - hor[x2 + 1][y1 + 1] - hor[x1][y2 + 1];
                if (x2 > x1)
                    verts = ver[x2 + 1][y2 + 1] + ver[x1 + 1][y1] - ver[x2 + 1][y1] - ver[x1 + 1][y2 + 1];
                write.WriteLine(dts - hors - verts);
            }
        }
    }
}