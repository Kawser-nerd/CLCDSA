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
        public string Find(string s, ref int k, int len, List<int> positions)
        {
            for (char x = 'a'; x <= 'z'; ++x)
            {
                int found = 0;
                var lst = new List<int>();
                for (int j = 0; j < positions.Count; ++j)
                    if (s[positions[j]] == x)
                    {
                        found = positions[j] + 1;
                        if (positions[j] + 1 < s.Length)
                            lst.Add(positions[j] + 1);
                    }
                if (found > 0)
                {
                    if (k == 1)
                        return s.Substring(found - len - 1, len + 1);
                    k--;
                    var res = Find(s, ref k, len + 1, lst);
                    if (res != null)
                        return res;
                }
            }
            return null;
        }

        public void Run()
        {
            var s = read.String();
            int k = read.Int();
            var positions = Enumerable.Range(0, s.Length).ToList();
            write.WriteLine(Find(s, ref k, 0, positions));
        }
    }
}