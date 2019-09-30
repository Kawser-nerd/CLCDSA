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
        private static Dictionary<int, char> map = new Dictionary<int, char>
        {
            { 0, 'R' },
            { 1, 'O' },
            { 2, 'Y' },
            { 3, 'G' },
            { 4, 'B' },
            { 5, 'V' },
        };

        private static void SolveCase()
        {
            int n = ReadInt();
            int R = ReadInt();
            int O = ReadInt();
            int Y = ReadInt();
            int G = ReadInt();
            int B = ReadInt();
            int V = ReadInt();

            int ry = -B - G + O + R - V + Y;
            int rg = 2 * G;
            int rb = B - G - O + R + V - Y;
            int ob = 2 * O;
            int yb = B + G - O - R - V + Y;
            int yv = 2 * V;

            if (ry < 0 || rb < 0 || yb < 0)
            {
                Writer.WriteLine("IMPOSSIBLE");
                return;
            }

            a = new int[6, 6];
            a[0, 2] = ry;
            a[2, 0] = ry;
            a[0, 3] = rg;
            a[3, 0] = rg;
            a[0, 4] = rb;
            a[4, 0] = rb;
            a[1, 4] = ob;
            a[4, 1] = ob;
            a[2, 4] = yb;
            a[4, 2] = yb;
            a[2, 5] = yv;
            a[5, 2] = yv;
            for (int i = 0; i < 6; i++)
            {
                int sum = 0;
                for (int j = 0; j < 6; j++)
                {
                    sum += a[i, j];
                }
                if (sum > 0)
                {
                    way = new List<int>();
                    Run(i);
                    if (way.Count <= n)
                    {
                        Writer.WriteLine("IMPOSSIBLE");
                    }
                    else
                    {
                        way.RemoveAt(way.Count - 1);
                        Writer.WriteLine(string.Join("", way.Select(p => map[p])));
                    }
                    break;
                }
            }
        }

        private static void Run(int t)
        {
            for (int i = 0; i < 6; i++)
            {
                if (a[t, i] > 0)
                {
                    a[t, i]--;
                    a[i, t]--;
                    Run(i);
                }
            }
            way.Add(t);
        }

        private static int[,] a;

        private static List<int> way;

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
