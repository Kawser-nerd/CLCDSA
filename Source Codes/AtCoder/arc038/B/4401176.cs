using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _038
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hw = ReadInts();
            int h = hw[0];
            int w = hw[1];
            bool[,] grid = new bool[h + 1, w + 1];
            for(int i = 0; i < h; i++)
            {
                string s = Read();
                for(int j = 0; j < w; j++)
                {
                    grid[i, j] = s[j] == '.';
                }
            }
            bool[,] dp = new bool[h + 1, w + 1];
            for(int i = h - 1; i >= 0; i--)
            {
                for(int j = w - 1; j >= 0; j--)
                {
                    bool win = (grid[i, j + 1] && !dp[i, j + 1])
                        || (grid[i + 1, j] && !dp[i + 1, j])
                        || (grid[i + 1, j + 1] && !dp[i + 1, j + 1]);
                    dp[i, j] = win;
                }
            }
            WriteLine(dp[0, 0] ? "First" : "Second");
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