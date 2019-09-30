using System;
using System.Collections.Generic;
using System.Linq;
using System.Globalization;
using System.IO;
using CodeChallenges;
using System.Diagnostics;

namespace CodeChallenges.Boilerplate.IO
{
    #region helpers
    class FormattedStreamWriter : StreamWriter { public FormattedStreamWriter(Stream stream) : base(stream) { } public FormattedStreamWriter(string filePath) : base(filePath) { } public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } } }
    static class IOExtensions
    {
        public static string ReadString(this StreamReader reader) { return reader.ReadToken(); }
        public static string[] ReadStringArray(this StreamReader reader, int n) { var array = new string[n]; for (int i = 0; i < n; ++i) { array[i] = reader.ReadToken(); } return array; }
        public static int ReadInt(this StreamReader reader) { return int.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static int[] ReadIntArray(this StreamReader reader, int n) { var array = new int[n]; for (int i = 0; i < n; ++i) { array[i] = int.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static uint ReadUnsignedInt(this StreamReader reader) { return uint.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static long ReadLong(this StreamReader reader) { return long.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static long[] ReadLongArray(this StreamReader reader, int n) { var array = new long[n]; for (int i = 0; i < n; ++i) { array[i] = long.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static ulong ReadUnsignedLong(this StreamReader reader) { return ulong.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static double ReadDouble(this StreamReader reader) { return double.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static double[] ReadDoubleArray(this StreamReader reader, int n) { var array = new double[n]; for (int i = 0; i < n; ++i) { array[i] = double.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static decimal ReadDecimal(this StreamReader reader) { return decimal.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); }
        public static decimal[] ReadDecimalArray(this StreamReader reader, int n) { var array = new decimal[n]; for (int i = 0; i < n; ++i) { array[i] = decimal.Parse(reader.ReadToken(), CultureInfo.InvariantCulture); } return array; }
        public static void ResetBuffer() { buffer = new Queue<string>(1000); }
        static Queue<string> buffer = new Queue<string>(1000);
        static string ReadToken(this StreamReader reader) { while (buffer.Count == 0) { reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries).ToList().ForEach((t) => { buffer.Enqueue(t); }); } return buffer.Dequeue(); }
    }
    #endregion
}

#region launch
class Program
{
    static void Main(string[] args)
    {
#if SOLVER_ATWORKSPACE
        var run = true; var outputFile = "output.txt"; var inputFile = "input.txt";
        switch (args[0])
        {
            case "g": run = false; outputFile = "input.txt"; inputFile = "output.txt"; break;
            case "r":
            default: run = true; inputFile = "input.txt"; outputFile = "output.txt"; break;
        }
#endif

        using (var writer = new CodeChallenges.Boilerplate.IO.FormattedStreamWriter(
#if SOLVER_ATWORKSPACE
outputFile
#else
            Console.OpenStandardOutput()
#endif
))
        {
            using (var reader = new StreamReader(
#if SOLVER_ATWORKSPACE
inputFile
#else 
            Console.OpenStandardInput()
#endif
))
            {
#if SOLVER_ATWORKSPACE
                var stopw = new Stopwatch(); stopw.Start();
#endif
#if SOLVER_ATWORKSPACE
                if (run) new Solver(reader, writer).Do(); else new Generator(reader, writer).Create();

#else
                new Solver(reader, writer).Do();
#endif
#if SOLVER_ATWORKSPACE
                stopw.Stop(); writer.WriteLine("> {0}ms", stopw.ElapsedMilliseconds);
#endif
            }
        }
    }
}
#endregion

namespace CodeChallenges
{
    using CodeChallenges.Boilerplate.IO;

    public class Solver
    {
        private readonly StreamReader reader;
        private readonly StreamWriter writer;

        public Solver(StreamReader reader, StreamWriter writer)
        {
            this.reader = reader;
            this.writer = writer;
        }        

        //public int Solve(int W, int K, int N)
        //{
        //    if (K == 0)
        //        return 0;
        //    if (dim[N][K][W] > 0)
        //        return dim[N][K][W] - 1;
        //    var one = K < N ? Solve(W, K, N - 1): 0;
        //    var two = (W >= w[N - 1])? (v[N - 1] + Solve(W - w[N - 1], K - 1, N - 1)): 0;
        //    dim[N][K][W] = Math.Max(one, two) + 1;
        //    return dim[N][K][W] - 1;
        //}

        public void Do()
        {
            const int DELTA = 3;
            int N = reader.ReadInt();
            int W = reader.ReadInt();
            int[][][] dim = new int[N + 1][][];
            int[] w = new int[N];
            int[] v = new int[N];
            for (int i = 0; i < N; ++i)
            {
                w[i] = reader.ReadInt();
                v[i] = reader.ReadInt();
            }
            var w0 = w[0];
            for (int i = 0; i <= N; ++i)
            {
                dim[i] = new int[N + 1][];
                for (int j = 0; j <= N; ++j)
                {
                    dim[i][j] = new int[DELTA * N + 1];
                    for (int k = 0; k <= DELTA * N; ++k)
                        dim[i][j][k] = int.MinValue;
                }
            }            
            for (int i = 0; i <= N; ++i)
            {
                for (int k = 0; k <= DELTA * N; ++k)
                    dim[i][0][k] = 0;
                if (i > 0)
                    w[i - 1] -= w0;
                for (int j = 1; j <= i; ++j)
                    for (int k = 0; k <= DELTA * N; ++k)
                    {
                        if (k >= w[i - 1])
                            dim[i][j][k] = Math.Max(dim[i][j][k], v[i - 1] + dim[i - 1][j - 1][k - w[i - 1]]);
                        if (i > j)
                            dim[i][j][k] = Math.Max(dim[i][j][k], dim[i - 1][j][k]);
                    }
            }
            int total = 0;
            for (int ii = 1; ii <= N; ++ii)
                if (W - 1L * ii * w0 >= 0)
                {
                    var WN = Math.Min(W - ii * w0, ii * DELTA);
                    total = Math.Max(total, dim[N][ii][WN]);
                }
            writer.WriteLine(total);
        }
    }
}