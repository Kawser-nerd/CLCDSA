using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_C
{
    class _008
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            long[] array = ReadLongs();
            long res1 = 0;
            res1 += (array[0] / 2) * 2;
            res1 += (array[3] / 2) * 2;
            res1 += (array[4] / 2) * 2;
            long res2 = 0;
            if (array[0] > 0 && array[3] > 0 && array[4] > 0)
            {
                res2 += 3;
            }
            res2+=((array[0]-1)/2)*2;
            res2 += ((array[3] - 1) / 2) * 2;
            res2 += ((array[4] - 1) / 2) * 2;
            WriteLine(Max(res1, res2) + array[1]);
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