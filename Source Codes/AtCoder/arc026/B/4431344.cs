using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _026
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            long n = ReadLong();
            long val = -n;
            long max = (long)Sqrt(n);
            for(long i = 1; i <= max; i++)
            {
                if (n % i > 0) continue;

                val += i;
                if (i < n / i)
                {
                    val += n / i;
                }
            }
            if (val > n)
            {
                WriteLine("Abundant");
            }
            if (val == n)
            {
                WriteLine("Perfect");
            }
            if (val < n)
            {
                WriteLine("Deficient");
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