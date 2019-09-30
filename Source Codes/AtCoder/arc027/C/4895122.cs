using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _027
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] xy = ReadInts();
            int x = xy[0];
            int y = xy[1];
            int n = ReadInt();
            int[][] ths = new int[n][];
            for(int i = 0; i < n; i++)
            {
                ths[i] = ReadInts();
            }
            long[,] dp = new long[x + 1, y + 1];
            for(int i = 0; i <= x; i++)
            {
                for(int j = 0; j <= y; j++)
                {
                    dp[i, j] = -1;
                }
            }
            dp[0, 0] = 0;
            long max = 0;
            for(int i = 0; i < n; i++)
            {
                long[,] next = new long[x + 1, y + 1];
                for (int j = 0; j <= x; j++)
                {
                    for (int k = 0; k <= y; k++)
                    {
                        next[j, k] = dp[j, k];
                    }
                }
                for (int j = 0; j <= x; j++)
                {
                    for (int k = 0; k <= y; k++)
                    {
                        if (dp[j, k] == -1) continue;

                        int nextJ = j + 1;
                        int nextK = k + ths[i][0] - 1;
                        if (nextK > y)
                        {
                            nextJ += nextK - y;
                            nextK = y;
                        }
                        if (nextJ > x) continue;
                        next[nextJ, nextK] = Max(
                            next[nextJ, nextK], dp[j, k] + ths[i][1]);
                        max = Max(max, next[nextJ, nextK]);
                    }
                }
                dp = next;
            }
            WriteLine(max);
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}