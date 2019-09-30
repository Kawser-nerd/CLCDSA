using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _057
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] ak = ReadLongs();
            long a = ak[0];
            long k = ak[1];
            long x = 2 * (long)Math.Pow(10, 12);
            if (k == 0)
            {
                Console.WriteLine(x - a);
                return;
            }
            long bottom = -1;
            long top = long.MaxValue;
            long first = a * k + 1;
            while (bottom + 1 < top)
            {
                long mid = (bottom + top) / 2;
                if (Math.Pow(k + 1, mid) * first >= k*x + 1)
                {
                    top = mid;
                }
                else
                {
                    bottom = mid;
                }
            }
            Console.WriteLine(top);
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