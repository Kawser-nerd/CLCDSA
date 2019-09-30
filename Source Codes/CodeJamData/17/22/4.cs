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
                var r = reader.ReadInt();
                var o = reader.ReadInt();
                var y = reader.ReadInt();
                var g = reader.ReadInt();
                var b = reader.ReadInt();
                var v = reader.ReadInt();
                if (n == v + y)
                {
                    if (v != y)
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                    }
                    else
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, string.Join("", Enumerable.Repeat("YV", y)));
                    }
                    continue;
                }
                else
                {
                    if (v > 0 && v >= y)
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                        continue;
                    }
                }
                if (n == g + r)
                {
                    if (g != r)
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                    }
                    else
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, string.Join("", Enumerable.Repeat("RG", r)));
                    }
                    continue;
                }
                else
                {
                    if (g > 0 && g >= r)
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                        continue;
                    }
                }
                if (n == b + o)
                {
                    if (b != o)
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                    }
                    else
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, string.Join("", Enumerable.Repeat("BO", b)));
                    }
                    continue;
                }
                else
                {
                    if (o > 0 && o >= b)
                    {
                        writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                        continue;
                    }
                }
                var y1 = y - v;
                var r1 = r - g;
                var b1 = b - o;
                if (y1 > r1 + b1 || b1 > r1 + y1 || r1 > y1 + b1)
                {
                    writer.WriteLine("Case #{0}: {1}", caseNum, "IMPOSSIBLE");
                    continue;
                }
                var res = "";
                if (r1 >= y1 && r1 >= b1)
                {
                    res = string.Join("", Enumerable.Repeat("RY", r1 - b1))
                        + string.Join("", Enumerable.Repeat("RYB", b1 + y1 - r1))
                        + string.Join("", Enumerable.Repeat("RB", r1 - y1));
                }
                else if (y1 >= r1 && y1 >= b1)
                {
                    res = string.Join("", Enumerable.Repeat("YR", y1 - b1))
                        + string.Join("", Enumerable.Repeat("YRB", b1 + r1 - y1))
                        + string.Join("", Enumerable.Repeat("YB", y1 - r1));
                }
                else
                {
                    res = string.Join("", Enumerable.Repeat("BR", b1 - y1))
                        + string.Join("", Enumerable.Repeat("BYR", y1 + r1 - b1))
                        + string.Join("", Enumerable.Repeat("BY", b1 - r1));
                }
                if (v > 0)
                {
                    for (int j = 0; j < res.Length; ++j)
                    {
                        if (res[j] == 'Y')
                        {
                            res = res.Substring(0, j) + string.Join("", Enumerable.Repeat("YV", v)) + res.Substring(j);
                            break;
                        }
                    }
                }
                if (g > 0)
                {
                    for (int j = 0; j < res.Length; ++j)
                    {
                        if (res[j] == 'R')
                        {
                            res = res.Substring(0, j) + string.Join("", Enumerable.Repeat("RG", g)) + res.Substring(j);
                            break;
                        }
                    }
                }
                if (o > 0)
                {
                    for (int j = 0; j < res.Length; ++j)
                    {
                        if (res[j] == 'B')
                        {
                            res = res.Substring(0, j) + string.Join("", Enumerable.Repeat("BO", o)) + res.Substring(j);
                            break;
                        }
                    }
                }
                writer.WriteLine("Case #{0}: {1}", caseNum, res);
            }
        }
    }
}