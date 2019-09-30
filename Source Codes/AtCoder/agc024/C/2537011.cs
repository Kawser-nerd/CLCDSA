using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace ReadWriteTemplate
{
    public static class Solver
    {
        private static void SolveCase()
        {
            int n = ReadInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = ReadLong();
            }

            if (a[0] != 0)
            {
                Writer.WriteLine(-1);
                return;
            }

            long max = 0;
            long ans = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] < max)
                {
                    Writer.WriteLine(-1);
                    return;
                }
                if (a[i] > max)
                {
                    ans += a[i];
                }
                max = a[i] - 1;
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
                Writer.Write("Case #{0}: ", i + 1);
                SolveCase();
            }*/

            /*sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds);*/
        }

        public static void Main()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

#if DEBUG
            //Reader = Console.In; Writer = Console.Out;
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");
#else
            Reader = Console.In; Writer = Console.Out;
#endif

            Solve();
            /*Thread thread = new Thread(Solve, 64 * 1024 * 1024);
            thread.CurrentCulture = CultureInfo.InvariantCulture;
            thread.Start();
            thread.Join();*/

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