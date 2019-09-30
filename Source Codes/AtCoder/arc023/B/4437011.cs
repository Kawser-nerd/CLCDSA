using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _023
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] rcd = ReadInts();
            int r = rcd[0];
            int c = rcd[1];
            int d = rcd[2];
            int[,] grid = new int[r, c];
            for(int i = 0; i < r; i++)
            {
                int[] array = ReadInts();
                for(int j = 0; j < c; j++)
                {
                    grid[i, j] = array[j];
                }
            }
            int max = 1;
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    int dist = i + j;
                    if (dist <= d && dist % 2 == d % 2)
                    {
                        max = Max(max, grid[i, j]);
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