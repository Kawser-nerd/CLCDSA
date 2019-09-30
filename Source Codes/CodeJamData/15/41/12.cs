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
            int r = ReadInt();
            int c = ReadInt();
            var map = new int[r, c];
            for (int i = 0; i < r; i++)
            {
                var line = Reader.ReadLine();
                for (int j = 0; j < c; j++)
                {
                    var ch = line[j];
                    switch (ch)
                    {
                        case '>':
                            map[i, j] = 0;
                            break;
                        case 'v':
                            map[i, j] = 1;
                            break;
                        case '<':
                            map[i, j] = 2;
                            break;
                        case '^':
                            map[i, j] = 3;
                            break;
                        case '.':
                            map[i, j] = -1;
                            break;
                    }
                }
            }

            var sx = new[] {0, 1, 0, -1};
            var sy = new[] {1, 0, -1, 0};

            int ans = 0;

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (map[i, j] == -1)
                    {
                        continue;
                    }

                    int k = -1;
                    bool found = false;
                    for (int l = 0; l < 4; l++)
                    {
                        k = (map[i, j] + l) % 4;
                        int x = i;
                        int y = j;
                        bool ok = true;
                        while (true)
                        {
                            x += sx[k];
                            y += sy[k];

                            if (x < 0 || r <= x || y < 0 || c <= y)
                            {
                                ok = false;
                                break;
                            }

                            if (map[x, y] >= 0)
                            {
                                break;
                            }
                        }

                        if (ok)
                        {
                            if (k != map[i, j])
                            {
                                ans++;
                            }
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        Writer.Write("IMPOSSIBLE");
                        return;
                    }
                }
            }

            Writer.Write(ans);
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
