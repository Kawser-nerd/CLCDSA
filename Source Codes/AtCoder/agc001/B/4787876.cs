using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class AGC001_B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            long[] nx = ReadLongs();
            long n = nx[0];
            long x = nx[1];
            long min = Min(n - x, x);
            long max = Max(n - x, x);
            WriteLine(GetLength(min, max));
        }

        static long GetLength(long min,long max)
        {
            long cnt = max / min;
            long val = min * 3 * cnt;
            if (max % min > 0)
            {
                val += GetLength(max % min, min);
            }
            return val;
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