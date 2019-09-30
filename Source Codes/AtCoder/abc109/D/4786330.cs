using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class ABC109_D
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
            int[,] grid = new int[h, w];
            for(int i = 0; i < h; i++)
            {
                int[] row = ReadInts();
                for(int j = 0; j < w; j++)
                {
                    grid[i, j] = row[j];
                }
            }
            List<int[]> res = new List<int[]>();
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w-1; j++)
                {
                    if (grid[i, j] % 2 == 0) continue;

                    res.Add(new int[4] { i + 1, j + 1, i + 1, j + 2 });
                    grid[i, j + 1]++;
                }
            }
            for(int i = 0; i < h - 1; i++)
            {
                if (grid[i, w - 1] % 2 == 0) continue;

                res.Add(new int[4] { i + 1, w, i + 2, w });
                grid[i + 1, w - 1]++;
            }

            WriteLine(res.Count);
            for (int i = 0; i < res.Count; i++)
            {
                WriteLine(res[i][0] + " " + res[i][1] + " "
                    + res[i][2] + " " + res[i][3]);
            }
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