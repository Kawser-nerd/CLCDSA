using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _005
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            string[] strs = Read().Split();
            int x = int.Parse(strs[0]) - 1;
            int y = int.Parse(strs[1]) - 1;
            string w = strs[2];
            int dx = 0;
            int dy = 0;
            if (w.Contains('R')) dx += 1;
            if (w.Contains('L')) dx -= 1;
            if (w.Contains('D')) dy += 1;
            if (w.Contains('U')) dy -= 1;
            char[,] grid = new char[9, 9];
            for (int i = 0; i < 9; i++)
            {
                string s = Read();
                for (int j = 0; j < 9; j++)
                {
                    grid[i, j] = s[j];
                }
            }
            char[] res = new char[4];
            for(int i = 0; i < 4; i++)
            {
                res[i] = grid[y, x];

                if (x == 0 && dx < 0) dx = 1;
                if (x == 8 && dx > 0) dx = -1;
                if (y == 0 && dy < 0) dy = 1;
                if (y == 8 && dy > 0) dy = -1;
                x += dx;
                y += dy;
            }
            WriteLine(res);
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