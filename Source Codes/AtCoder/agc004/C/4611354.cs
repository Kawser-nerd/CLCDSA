using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _004_C
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
            bool[,] grid = new bool[h, w];
            bool[,,] res = new bool[h, w, 2];
            for (int i = 0; i < w; i++) res[0, i, 0] = true;
            Read();
            for(int i = 1; i < h-1; i++)
            {
                string s = Read();
                int index = i % 2 == 0 ? 0 : 1;
                res[i, 0, 0] = true;
                res[i, w - 1, 1] = true;
                for(int j = 1; j < w-1; j++)
                {
                    res[i, j, index] = true;
                    res[i, j, (index + 1) % 2] = s[j] == '#';
                }
            }
            Read();
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    Write(res[i, j, 0] ? '#' : '.');
                }
                WriteLine();
            }
            WriteLine();
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    Write(res[i, j, 1] ? '#' : '.');
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