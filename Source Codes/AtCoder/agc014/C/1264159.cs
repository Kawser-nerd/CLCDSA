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
            int h = ReadInt();
            int w = ReadInt();
            int k = ReadInt();
            int[,] map = new int[h, w];
            int[,] d = new int[h, w];
            int sx = -1;
            int sy = -1;
            for (int i = 0; i < h; i++)
            {
                string s = Reader.ReadLine();
                for (int j = 0; j < w; j++)
                {
                    map[i, j] = s[j] == '#' ? -2 : -1;
                    if (s[j] == 'S')
                    {
                        sx = i;
                        sy = j;
                    }
                    d[i, j] = -1;
                }
            }

            d[sx, sy] = 0;
            Queue<Point> queue = new Queue<Point>();
            queue.Enqueue(new Point(sx, sy));

            int[] shx = new[] { 1, 0, -1, 0 };
            int[] shy = new[] { 0, 1, 0, -1 };

            while (queue.Count > 0)
            {
                var p = queue.Dequeue();
                int cd = d[p.X, p.Y];
                if (cd >= k)
                {
                    break;
                }
                for (int i = 0; i < 4; i++)
                {
                    int nx = p.X + shx[i];
                    int ny = p.Y + shy[i];
                    if (0 <= nx && nx < h && 0 <= ny && ny < w)
                    {
                        if (map[nx, ny] == -1 && d[nx, ny] == -1)
                        {
                            d[nx, ny] = cd + 1;
                            queue.Enqueue(new Point(nx, ny));
                        }
                    }
                }
            }

            int ans = int.MaxValue;
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (d[i, j] != -1)
                    {
                        if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                        {
                            Writer.WriteLine(1);
                            return;
                        }
                        int dist = int.MaxValue;
                        dist = Math.Min(dist, F(i, k));
                        dist = Math.Min(dist, F(h - 1 - i, k));
                        dist = Math.Min(dist, F(j, k));
                        dist = Math.Min(dist, F(w - 1 - j, k));
                        ans = Math.Min(ans, dist + 1);
                    }
                }
            }
            Writer.WriteLine(ans);
        }

        public static int F(int x, int k)
        {
            return (x + k - 1) / k;
        }

        public class Point
        {
            public Point(int x, int y)
            {
                X = x;
                Y = y;
            }

            public int X;

            public int Y;
        }

        public static void Solve()
        {
            //int T = ReadInt();
            //for (int i = 0; i < T; i++)
            {
                //Writer.Write("Case #{0}: ", i + 1);
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