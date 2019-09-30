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
    using System.Text;

    public class Solver
    {
        private readonly StreamReader reader;
        private readonly StreamWriter writer;

        public Solver(StreamReader reader, StreamWriter writer)
        {
            this.reader = reader;
            this.writer = writer;
        }

        public void Do()
        {
            var t = reader.ReadInt();
            for (int caseNum = 1; caseNum <= t; ++caseNum)
            {
                var n = reader.ReadInt();
                var q = reader.ReadInt();
                var e = new int[n];
                var s = new int[n];
                for (int i = 0;i < n; ++i)
                {
                    e[i] = reader.ReadInt();
                    s[i] = reader.ReadInt();
                }
                var d = new long[n][];
                for (int i = 0; i < n; ++i)
                {
                    d[i] = reader.ReadLongArray(n);
                }
                for (int i = 0;i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        for (int h = 0; h < n; ++h)
                        {
                            if (d[j][i] != -1 && d[i][h] != -1)
                            {
                                if (d[j][h] == -1 || d[j][h] > d[j][i] + d[i][h])
                                {
                                    d[j][h] = d[j][i] + d[i][h];
                                }                                
                            }
                        }
                    }
                }
                var hd = new decimal[n][];
                for (int i = 0; i < n; ++i)
                {
                    hd[i] = new decimal[n];
                    for (int j = 0; j < n; ++j)
                    {
                        if (d[i][j] == -1 || d[i][j] > e[i])
                        {
                            hd[i][j] = -1;
                        }
                        else
                        {
                            hd[i][j] = 1M * d[i][j] / s[i];
                        }
                    }
                }
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        for (int h = 0; h < n; ++h)
                        {
                            if (hd[j][i] != -1 && hd[i][h] != -1)
                            {
                                if (hd[j][h] == -1 || hd[j][h] > hd[j][i] + hd[i][h])
                                {
                                    hd[j][h] = hd[j][i] + hd[i][h];
                                }
                            }
                        }
                    }
                }

                var res = new decimal[q];
                for (int i = 0; i < q; ++i)
                {
                    var u = reader.ReadInt() - 1;
                    var v = reader.ReadInt() - 1;
                    res[i] = hd[u][v];
                    //var temp = new decimal[n];
                    //for (int h = 0; h < n; ++h)
                    //{
                    //    temp[h] = -1;
                    //}
                    //temp[v] = 0;
                    //for (int h = v - 1; h >= u; --h)
                    //{
                    //    decimal curTime = -1;
                    //    long dist = 0;
                    //    for (int k = h + 1; k <= v; ++k)
                    //    {
                    //        if (d[k - 1][k] == -1)
                    //            throw new Exception("unexpected");
                    //        dist += d[k - 1][k];
                    //        if (e[h] >= dist && temp[k] != -1)
                    //        {
                    //            var newTime = 1M * dist / s[h] + temp[k];
                    //            if (curTime == -1 || curTime > newTime)
                    //            {
                    //                curTime = newTime;
                    //            }
                    //        }
                    //    }
                    //    temp[h] = curTime;
                    //}
                    //res[i] = temp[u];
                }
                writer.WriteLine("Case #{0}: {1}", caseNum, string.Join(" ", res.Select(ri => ri.ToString("F8"))));
            }
        }
    }
}