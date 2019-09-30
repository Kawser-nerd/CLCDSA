using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Threading;

namespace ReadWriteTemplate
{
    public class Solver
    {
        private static void SolveCase(int caseNumber)
        {
            var n = ReadInt();
            long v = (long) Math.Round(ReadDouble() * 10000);
            long x = (long) Math.Round(ReadDouble() * 10000);
            var s = new Source[n];
            for (int i = 0; i < n; i++)
            {
                s[i] = new Source
                {
                    R = (long) Math.Round(ReadDouble() * 10000),
                    C = (long) Math.Round(ReadDouble() * 10000),
                };
            }

            long rm = 0;
            long re = 0;
            long rl = 0;

            long pm = 0;
            long pe = 0;
            long pl = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i].C < x)
                {
                    rl += s[i].R;
                    pl += s[i].R * (x - s[i].C);
                }
                if (s[i].C == x)
                {
                    re += s[i].R;
                }
                if (s[i].C > x)
                {
                    rm += s[i].R;
                    pm += s[i].R * (s[i].C - x);
                }
            }

            if (pm > pl)
            {
                var t = pm;
                pm = pl;
                pl = t;

                t = rm;
                rm = rl;
                rl = t;

                for (int i = 0; i < n; i++)
                {
                    s[i].C = 2 * x - s[i].C;
                }
            }

            if (pm == 0 && re == 0)
            {
                Writer.Write("IMPOSSIBLE");
                return;
            }

            s = s.Where(z => z.C < x).OrderByDescending(z => z.R).ToArray();
            long sumR = rm + re;
            for (int i = 0; i < s.Length; i++)
            {
                if (pm == 0)
                {
                    break;
                }
                long ps = s[i].R * (x - s[i].C);
                if (ps < pm)
                {
                    pm -= ps;
                    sumR += s[i].R;
                }
                else
                {
                    double dSum = sumR + s[i].R * ((1.0 * pm) / ps);
                    Writer.Write("{0:0.00000000}", v / dSum);
                    return;
                }
            }
            Writer.Write("{0:0.00000000}", 1.0 * v / sumR);
        }

        public class Source
        {
            public long R { get; set; }

            public long C { get; set; }

            public override string ToString()
            {
                return string.Format("R: {0}, C: {1}", R, C);
            }
        }

        public static void Solve()
        {
            var t = ReadInt();
            for (int i = 0; i < t; i++)
            {
                Writer.Write("Case #{0}: ", i + 1);
                SolveCase(i + 1);
                Writer.WriteLine();
            }
        }

        public static void Main()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            //Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");

            Solve();

            Reader.Close();
            Writer.Close();
        }

        #region Read/Write

        private static TextReader Reader;

        private static TextWriter Writer;

        private static Queue<string> CurrentLineTokens = new Queue<string>();

        private static string[] ReadAndSplitLine()
        {
            return Reader.ReadLine().Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }

        public static string ReadToken()
        {
            while (CurrentLineTokens.Count == 0)
                CurrentLineTokens = new Queue<string>(ReadAndSplitLine());
            return CurrentLineTokens.Dequeue();
        }

        public static int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        public static long ReadLong()
        {
            return long.Parse(ReadToken());
        }

        public static double ReadDouble()
        {
            return double.Parse(ReadToken(), CultureInfo.InvariantCulture);
        }

        public static int[] ReadIntArray()
        {
            return ReadAndSplitLine().Select(int.Parse).ToArray();
        }

        public static long[] ReadLongArray()
        {
            return ReadAndSplitLine().Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            return ReadAndSplitLine().Select(s => double.Parse(s, CultureInfo.InvariantCulture)).ToArray();
        }

        public static int[][] ReadIntMatrix(int numberOfRows)
        {
            int[][] matrix = new int[numberOfRows][];
            for (int i = 0; i < numberOfRows; i++)
                matrix[i] = ReadIntArray();
            return matrix;
        }

        public static string[] ReadLines(int quantity)
        {
            string[] lines = new string[quantity];
            for (int i = 0; i < quantity; i++)
                lines[i] = Reader.ReadLine().Trim();
            return lines;
        }

        public static void WriteArray<T>(IEnumerable<T> array)
        {
            Writer.WriteLine(string.Join(" ", array));
        }

        #endregion
    }
}
