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

        public void Do()
        {
            var t = reader.ReadInt();
            for (int caseNum = 1; caseNum <= t; ++caseNum)
            {
                var d = reader.ReadInt();
                var n = reader.ReadInt();
                var s = new int[n];
                var k = new int[n];
                for (int j = 0; j < n; ++j)
                {
                    k[j] = reader.ReadInt();
                    s[j] = reader.ReadInt();
                }
                decimal speed = decimal.MaxValue;
                for (int j =0 ; j < n; ++j)
                {
                    speed = Math.Min(speed, 1M * d * s[j] / (d - k[j]));
                }
                writer.WriteLine("Case #{0}: {1:F8}", caseNum, speed);
            }
        }
    }
}