using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class ARC093_D
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] ab = ReadInts();
            int a = ab[0];
            int b = ab[1];
            bool[,] grid = new bool[100, 100];//white true
            for(int i = 0; i < 100; i++)
            {
                for(int j = 0; j < 100; j++)
                {
                    if (i < 50) grid[i, j] = false;
                    else grid[i, j] = true;
                }
            }
            for(int i = 1; i < 50; i+=2)
            {
                for(int j = 1; j < 100; j+=2)
                {
                    if (a == 1) break;
                    grid[i, j] = true;
                    a--;
                }
            }
            for (int i = 51; i < 100; i+=2)
            {
                for (int j = 1; j < 100; j+=2)
                {
                    if (b == 1) break;

                    grid[i, j] = false;
                    b--;
                }
            }

            WriteLine("100 100");
            for (int i = 0; i < 100; i++)
            {
                for(int j = 0; j < 100; j++)
                {
                    Write(grid[i, j] ? '.' : '#');
                }
                WriteLine();
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