using System;
using System.Collections.Generic;
//using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

//using System.Threading;

namespace ReadWriteTemplate
{
    public static class Solver
    {
        private static void SolveCase()
        {
            long MAX_LONG = long.MaxValue / 2;

            int n = ReadInt();
            int q = ReadInt();
            var e = new long[n];
            var s = new long[n];
            var d = new long[n * n];
            for (int i = 0; i < n; i++)
            {
                e[i] = ReadLong();
                s[i] = ReadLong();
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    long x = ReadLong();
                    d[n * i + j] = x >= 0 ? x : MAX_LONG;
                }
            }
            var a = new long[n * n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[n * i + j] = d[n * i + j];
                }
            }
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        a[n * i + j] = Math.Min(a[n * i + j], a[n * i + k] + a[n * k + j]);
                    }
                }
            }

            var b = new double[n * n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[n * i + j] <= e[i])
                    {
                        b[n * i + j] = (double) a[n * i + j] / s[i];
                    }
                    else
                    {
                        b[n * i + j] = double.MaxValue / (n * n);
                    }
                }
            }

            var c = new double[n * n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    c[n * i + j] = b[n * i + j];
                }
            }
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        c[n * i + j] = Math.Min(c[n * i + j], c[n * i + k] + c[n * k + j]);
                    }
                }
            }
            for (int i = 0; i < q; i++)
            {
                int uk = ReadInt();
                int vk = ReadInt();
                Writer.Write("{0} ", c[n * (uk - 1) + vk - 1].ToString(CultureInfo.InvariantCulture));
            }
            Writer.WriteLine();
        }

        public static void Solve()
        {
            int T = ReadInt();
            for (int i = 0; i < T; i++)
            {
                Writer.Write("Case #{0}: ", i + 1);
                SolveCase();
            }
        }

        public static void Main()
        {
            //Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

#if DEBUG
            Reader = File.OpenText("input.txt"); Writer = File.CreateText("output.txt");
#else
            Reader = Console.In; Writer = Console.Out;
#endif
            //Reader = File.OpenText("concatenation.in"); Writer = File.CreateText("concatenation.out");

            Solve();

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
