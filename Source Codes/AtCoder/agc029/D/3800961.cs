using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace ReadWriteTemplate
{
    public static class Solver
    {
        private static void SolveCase()
        {
            int h = ReadInt();
            int w = ReadInt();
            int n = ReadInt();

            int[] x = new int[n];
            int[] y = new int[n];
            for (int i = 0; i < n; i++)
            {
                x[i] = ReadInt();
                y[i] = ReadInt();
            }

            int ans = h;

            int[] b = new int[h + 1];
            for (int i = 0; i < h + 1; i++)
            {
                b[i] = int.MaxValue / 2;
            }

            for (int i = 0; i < n; i++)
            {
                if (x[i] >= y[i])
                {
                    b[x[i] - y[i]] = Math.Min(b[x[i] - y[i]], x[i] - 1);
                }
            }

            for (int i = 1; i < h + 1; i++)
            {
                b[i] = Math.Max(b[i - 1], b[i]);
            }

            for (int i = 0; i < n; i++)
            {
                int d = x[i] - y[i] - 1;
                if (d >= 0)
                {
                    if (x[i] <= b[x[i] - y[i]])
                    {
                        ans = Math.Min(ans, x[i] - 1);
                    }
                }
            }

            Writer.WriteLine(ans);
        }

        public static void Solve()
        {
            SolveCase();

            /*var sw = Stopwatch.StartNew();*/

            /*int T = ReadInt();
            for (int i = 0; i < T; i++)
            {
                // Writer.Write("Case #{0}: ", i + 1);
                SolveCase();
            }*/

            /*sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds);*/
        }

        public static void Main()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

#if DEBUG
            // Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");
#else
            Reader = Console.In; Writer = Console.Out;
#endif

            // Solve();
            Thread thread = new Thread(Solve, 64 * 1024 * 1024);
            thread.CurrentCulture = CultureInfo.InvariantCulture;
            thread.Start();
            thread.Join();

            Reader.Close();
            Writer.Close();
        }

        public static IOrderedEnumerable<TSource> OrderByWithShuffle<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector)
        {
            return source.Shuffle().OrderBy(keySelector);
        }

        public static T[] Shuffle<T>(this IEnumerable<T> source)
        {
            T[] result = source.ToArray();
            Random rnd = new Random();
            for (int i = result.Length - 1; i >= 1; i--)
            {
                int k = rnd.Next(i + 1);
                T tmp = result[k];
                result[k] = result[i];
                result[i] = tmp;
            }
            return result;
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

        public static string ReadLine()
        {
            return Reader.ReadLine();
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