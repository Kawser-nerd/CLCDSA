using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _001_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] nx = ReadLongs();
            long n = nx[0];
            long x = nx[1];
            Console.WriteLine(Length(n, x));
        }

        static long Length(long n, long x)
        {
            long min = Math.Min(n - x, x);
            long max = n - min;
            long cnt = max / min;

            if (max % min == 0)
            {
                return min * 3 * cnt;
            }
            else
            {
                long margin = max % min;
                return min * 3 * cnt + Length(margin + min, min);
            }
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}