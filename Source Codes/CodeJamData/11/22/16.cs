using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

namespace FHC
{
    class Program
    {
        readonly TextReader reader = new StreamReader("../../Input.txt");
        readonly TextWriter writer = new StreamWriter("../../Output.txt");
        string bufferedLine;
        int bufferedLineIndex;

        static IEnumerable<int> ReadInts(string data)
        {
            return data.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s));
        }

        string ReadToken()
        {
            if (bufferedLine == null)
                bufferedLine = reader.ReadLine();
            while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            while (bufferedLineIndex >= bufferedLine.Length)
            {
                bufferedLine = reader.ReadLine();
                bufferedLineIndex = 0;
                while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                    bufferedLineIndex++;
            }
            int index = bufferedLineIndex;
            while (bufferedLineIndex < bufferedLine.Length && !char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            return bufferedLine.Substring(index, bufferedLineIndex - index);
        }

        int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        long ReadLong()
        {
            return long.Parse(ReadToken());
        }

        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            var program = new Program();
            stopwatch.Start();
            program.Run();
            stopwatch.Stop();
            program.reader.Close();
            program.writer.Close();
            Console.WriteLine("Elapsed: " + stopwatch.Elapsed);
        }

        void Run()
        {
            int testCount = ReadInt();
            for (int i = 1; i < testCount + 1; i++)
            {
                var stopwatch = new Stopwatch();
                int C = ReadInt(), D = ReadInt();
                int[] P = new int[C], V = new int[C];
                for (int j = 0; j < C; j++)
                {
                    P[j] = ReadInt();
                    V[j] = ReadInt();
                }
                stopwatch.Start();
                var res = Calc(C, D, P, V);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1:0.000000000}", i, res);
            }
        }

        struct Line
        {
            public double Left;
            public double Right;

            public double Length
            {
                get
                {
                    return Right - Left;
                }
            }
        }

        static bool Intersect(Line line1, Line line2, out Line intersection, ref double res)
        {
            if (line1.Right > line2.Left && line2.Right > line1.Left)
            {
                double newLength = line1.Length + line2.Length;
                double right = Math.Max(line1.Right, line2.Right);
                double left = Math.Min(line1.Left, line2.Left);
                double delta = (newLength - (right - left)) / 2;
                intersection = new Line {
                    Left = left - delta,
                    Right = right + delta
                };
                res += delta;
                return true;
            }
            intersection = new Line();
            return false;
        }

        bool Ok(int C, int D, int[] P, int[] V, double res)
        {
            double leftBound = double.NegativeInfinity;
            for (int i = 0; i < C; i++)
            {
                double x = Math.Max(leftBound + D, P[i] - res);
                leftBound = x + (V[i] - 1) * D;
                if (leftBound > P[i] + res)
                {
                    return false;
                }
            }
            return true;
        }

        double Calc(int C, int D, int[] PP, int[] VV)
        {
            double min = 0, max = 100000000000000;
            while (max - min > 1E-9)
            {
                double m = (min + max) / 2;
                if (Ok(C, D, PP, VV, m))
                {
                    max = m;
                } else
                {
                    min = m;
                }
            }
            return (min + max) / 2;
        }
    }
}