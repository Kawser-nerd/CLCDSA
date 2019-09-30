using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _050
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] rb = ReadLongs();
            long[] xy = ReadLongs();
            long r = rb[0];
            long b = rb[1];
            long x = xy[0];
            long y = xy[1];

            long bottom = 0;
            long top = Math.Min(r, b)+1;
            while (bottom + 1 < top)
            {
                long mid = (bottom + top) / 2;
                if (
                    mid <= (r - mid) / (x - 1) + (b - mid) / (y - 1))
                {
                    bottom = mid;
                }
                else
                {
                    top = mid;
                }
            }
            Console.WriteLine(bottom);
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