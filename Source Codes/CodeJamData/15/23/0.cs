using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ReadWriteTemplate
{
    public class Solver
    {
        private static void SolveCase(int caseNumber)
        {
            var hikers = new List<Hiker>();

            int n = ReadInt();
            for (int i = 0; i < n; i++)
            {
                long d = ReadLong();
                int h = ReadInt();
                long m = ReadLong();
                for (int j = 0; j < h; j++)
                {
                    hikers.Add(new Hiker {D = d, M = m + j,});
                }
            }

            if (hikers.Count < 2)
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, 0);
                return;
            }

            hikers = hikers.OrderBy(h => h.M).ToList();

            int ans = 0;
            if ((360 - hikers[1].D) * hikers[1].M >= (720 - hikers[0].D) * hikers[0].M)
            {
                ans = 1;
            }

            Writer.WriteLine("Case #{0}: {1}", caseNumber, ans);
        }

        public class Hiker
        {
            public long D { get; set; }

            public long M { get; set; }
        }

        public static void Solve()
        {
            var n = ReadInt();
            for (int i = 0; i < n; i++)
            {
                SolveCase(i + 1);
            }
        }

        public static void Main()
        {
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
