using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _025
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
            int[,] cGrid = new int[h, w];
            for(int i = 0; i < h; i++)
            {
                int[] cs = ReadInts();
                for(int j = 0; j < w; j++)
                {
                    cGrid[i, j] = cs[j];
                }
            }
            int[,] sums = new int[h, w];//black-white
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if (i == 0)
                    {
                        if (j > 0)
                        {
                            sums[i, j] = sums[i, j - 1];
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            sums[i, j] = sums[i - 1, j];
                        }
                        else
                        {
                            sums[i, j] = sums[i, j - 1] + sums[i - 1, j]
                                - sums[i - 1, j - 1];
                        }
                    }
                    if ((i + j) % 2 == 0)
                    {
                        sums[i, j] += cGrid[i, j];
                    }
                    else
                    {
                        sums[i, j] -= cGrid[i, j];
                    }
                    //WriteLine(sums[i, j]);
                }
            }

            int max = 0;
            for(int i = 0; i < h; i++)
            {
                for(int j = i; j < h; j++)
                {
                    for(int k = 0; k < w; k++)
                    {
                        for(int l = k; l < w; l++)
                        {
                            int val = sums[j, l];
                            if (i > 0) val -= sums[i - 1, l];
                            if (k > 0) val -= sums[j, k - 1];
                            if (i > 0 && k > 0) val += sums[i - 1, k - 1];
                            if (val == 0)
                            {
                                max = Max(max, (j - i + 1) * (l - k + 1));
                            }
                        }
                    }
                }
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