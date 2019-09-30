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
        const int MOD = 998244353;

        public int nod(int a, int b)
        {
            if (a > b)
                return nod(b, a);
            if (a == 0)
                return b;
            return nod(b % a, a);
        }

        public Tuple<long, long> Solve(long a, long b, long k)
        {
            if (a > b)
            {
                var temp1 = Solve(b, a, k);
                if (temp1 != null)
                {
                    var y = temp1.Item1;
                    var x = temp1.Item2;
                    if (y < 0)
                    {
                        var net = (-y + a - 1) / a;
                        x -= b * net;
                        y += a * net;
                    }
                    temp1 = Tuple.Create(x, y);
                }
                return temp1;
            }
            if (a == 0)
            {
                if (k % b == 0)
                    return Tuple.Create(0L, k / b);
                return null;
            }
            var temp = Solve(b % a, a, k);
            if (temp == null)
                return null;
            var x1 = temp.Item2 - temp.Item1 * (b / a);
            var y1 = temp.Item1;
            if (x1 < 0)
            {
                var net = (-x1 + b - 1) / b;
                x1 += b * net;
                y1 -= a * net;
            }
            if (y1 < 0)
            {
                var net = (-y1 + a - 1) / a;
                x1 -= b * net;
                y1 += a * net;
            }
            return Tuple.Create(x1, y1);
        }

        static int pow(int m, int e, int mod)
        {
            var res = 1;
            while (e > 0)
            {
                if ((e & 1) == 1)
                {
                    res = (int)(1L * res * m % mod);
                }
                e >>= 1;
                m = (int)(1L * m * m % mod);
            }
            return res % mod;
        }

        static int inverse_prime(int num, int prime)
        {
            return pow(num, prime - 2, prime);
        }

        public void Run()
        {            
            var n = read.Int();
            var a = read.Int();
            var b = read.Int();
            var k = read.Long();
            var dc = nod(a, b);
            var answer = 0L;
            if (k % dc == 0)
            {
                a /= dc;
                b /= dc;
                k /= dc;
                var res = Solve(a, b, k);

                if (res != null)
                {
                    var x = res.Item1;
                    var y = res.Item2;
                    if (y > n)
                    {
                        var net = (y - n + a - 1) / a;
                        y -= a * net;
                        x += b * net;
                    }
                    while (y + a <= n)
                    {
                        y += a;
                        x -= b;
                    }
                    var array = new long[n + 1];
                    array[0] = 1;
                    for (int i = 1; i <= n; ++i)
                    {
                        array[i] = array[i - 1];
                        array[i] = array[i] * (n - i + 1) % MOD;
                        array[i] = array[i] * inverse_prime(i, MOD) % MOD;
                    }
                    while (y >= 0 && x <= n)
                    {
                        if (x >= 0)
                        {
                            answer += array[x] * array[y] % MOD;
                            answer %= MOD;
                        }
                        y -= a;
                        x += b;
                    }
                }
            }
            write.WriteLine(answer);
        }
    }
}