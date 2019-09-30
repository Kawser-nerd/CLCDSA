using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ReadWriteTemplate
{
    public class Solver
    {
        public static int bestNoise;
        public static bool[,] map;
        public static bool[,] bestMap;

        private static void SolveCase(int caseNumber)
        {
            var r = ReadInt();
            var c = ReadInt();
            var n = ReadInt();

            //bestNoise = int.MaxValue;
            //map = new bool[r, c];
            //bestMap = new bool[r, c];
            //StartBT(0, n, r, c);

            int minfillnoise = Math.Min(Fill(r, c, n, 0), Fill(r, c, n, 1));

            /*if (minfillnoise != bestNoise)
            {
                Writer.WriteLine("Case #{0}: {1}", caseNumber, bestNoise);
                Writer.WriteLine("{0} {1} {2}", r, c, n);
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        Writer.Write(bestMap[i, j] ? '#' : '.');
                    }
                    Writer.WriteLine();
                }
                Writer.WriteLine();
            }*/
            Writer.WriteLine("Case #{0}: {1}", caseNumber, minfillnoise);
        }

        public static int Fill(int r, int c, int n, int mod)
        {
            var m = new bool[r, c];
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (n > 0 && (i + j) % 2 == mod)
                    {
                        m[i, j] = true;
                        n--;
                    }
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (n > 0 && !m[i, j] &&
                        ((i == 0 && j == 0) ||
                         (i == 0 && j == c - 1) ||
                         (i == r - 1 && j == 0) ||
                         (i == r - 1 && j == c - 1)))
                    {
                        m[i, j] = true;
                        n--;
                    }
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (n > 0 && !m[i, j] && (i == 0 || i == r - 1 || j == 0 || j == c - 1))
                    {
                        m[i, j] = true;
                        n--;
                    }
                }
            }
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (n > 0 && !m[i, j])
                    {
                        m[i, j] = true;
                        n--;
                    }
                }
            }
            return CalcNoise(r, c, m);
        }

        private static void StartBT(int pos, int t, int r, int c)
        {
            if (t == 0)
            {
                var noise = CalcNoise(r, c, map);

                if (noise < bestNoise)
                {
                    bestNoise = noise;
                    for (int i = 0; i < r; i++)
                    {
                        for (int j = 0; j < c; j++)
                        {
                            bestMap[i, j] = map[i, j];
                        }
                    }
                }
                return;
            }

            if (r * c - pos < t)
            {
                return;
            }

            StartBT(pos + 1, t, r, c);
            map[pos / c, pos % c] = true;
            StartBT(pos + 1, t - 1, r, c);
            map[pos / c, pos % c] = false;
        }

        private static int CalcNoise(int r, int c, bool[,] map)
        {
            int noise = 0;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (map[i, j])
                    {
                        if (i + 1 < r && map[i + 1, j])
                        {
                            noise++;
                        }
                        if (j + 1 < c && map[i, j + 1])
                        {
                            noise++;
                        }
                    }
                }
            }
            return noise;
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
