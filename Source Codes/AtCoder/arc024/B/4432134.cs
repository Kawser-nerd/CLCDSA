using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _024
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] colors = new int[n * 2];
            for (int i = 0; i < n; i++)
            {
                colors[i] = ReadInt();
                colors[i + n] = colors[i];
            }
            int max = 1;
            int now = 1;
            for(int i = 1; i < 2 * n; i++)
            {
                if (colors[i] == colors[i - 1])
                {
                    now++;
                    max = Max(max, now);
                }
                else
                {
                    now = 1;
                }
            }
            if (max == 2 * n)
            {
                WriteLine(-1);
            }
            else
            {
                WriteLine((max - 1) / 2 + 1);
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