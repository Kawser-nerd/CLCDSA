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
            int n = ReadInt();
            var a = ReadIntArray().OrderByWithShuffle(x => x).ToArray();
            var dict = new Dictionary<int, int>();
            foreach (var x in a)
            {
                if (dict.ContainsKey(x))
                {
                    dict[x]++;
                }
                else
                {
                    dict[x] = 1;
                }
            }

            var p = new int[32];
            for (int i = 0; i < 31; i++)
            {
                p[i] = 1 << i;
            }

            int ans = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = 31 - 1; j >= 1; j--)
                {
                    int d = p[j] - a[i];
                    if (d > 0 && dict[a[i]] > 0)
                    {
                        if (a[i] != d)
                        {
                            if (dict.ContainsKey(d) && dict[d] > 0)
                            {
                                ans++;
                                dict[a[i]]--;
                                dict[d]--;
                                break;
                            }
                        }
                        else
                        {
                            if (dict[d] > 1)
                            {
                                ans++;
                                dict[d] -= 2;
                                break;
                            }
                        }
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