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
            var t = read.Int();
            for (int caseNum = 1; caseNum <= t; ++caseNum)
            {
                var n = read.Int();
                var c = read.Int();                
                var m = read.Int();
                var cust = new int[c];
                var all = Create2DArray<int>(2, n);
                for (int j = 0; j < m; ++j)
                {
                    var p = read.Int() - 1;
                    var b = read.Int() - 1;
                    if (c <= 2)
                        ++all[b][p];
                }
                if (c > 2)
                {
                    write.WriteLine("Case #{0}: {1} {2}", caseNum, -1, -1);
                    continue;
                }
                List<int> coupl = new List<int>();
                for (int i = 0; i < n; ++i)
                    if (all[0][i] > 0 && all[1][i] > 0)
                        coupl.Add(i);
                int pos1 = 0;
                int pos2 = 1;
                int res = 0;
                int imps = 0;
                while (pos2 < coupl.Count)
                {
                    var pa = coupl[pos1];
                    var pb = coupl[pos2];
                    var mn = Math.Min(all[0][pa], all[1][pb]);
                    all[0][pa] -= mn;
                    all[1][pb] -= mn;
                    res += mn;
                    if (all[0][pa] == 0 && all[1][pb] > 0)
                        pos1 = pos2;
                    else if (all[0][pa] == 0 && all[1][pb] == 0)
                        pos1 = pos2 + 1;
                    pos2 = pos2 + 1;
                }
                coupl = new List<int>();
                for (int i = 0; i < n; ++i)
                    if (all[0][i] > 0 && all[1][i] > 0)
                        coupl.Add(i);
                if (coupl.Count > 1)
                    throw new Exception("bad algo");
                if (coupl.Count == 1)
                {
                    var p = coupl[0];
                    for (int i = 0; i < n && all[0][p] > 0; ++i)
                        if (i != p && all[1][i] > 0)
                        {
                            var mn = Math.Min(all[0][p], all[1][i]);
                            all[0][p] -= mn;
                            all[1][i] -= mn;
                            res += mn;
                        }
                    for (int i = 0; i < n && all[1][p] > 0; ++i)
                        if (i != p && all[0][i] > 0)
                        {
                            var mn = Math.Min(all[1][p], all[0][i]);
                            all[1][p] -= mn;
                            all[0][i] -= mn;
                            res += mn;
                        }
                    if (all[0][p] > 0 && all[1][p] > 0)
                    {
                        if (p > 0)
                        {
                            imps = Math.Min(all[0][p], all[1][p]);
                            res += Math.Max(all[0][p], all[1][p]);
                        }
                        else
                            res += all[0][p] + all[1][p];
                    }
                    else
                    {
                        var s0 = all[0].Sum();
                        var s1 = all[1].Sum();
                        res += Math.Max(s0, s1);
                    }
                }
                else
                {
                    var s0 = all[0].Sum();
                    var s1 = all[1].Sum();
                    res += Math.Max(s0, s1);
                }
                write.WriteLine("Case #{0}: {1} {2}", caseNum, res, imps);
            }
        }
    }
}