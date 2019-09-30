using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _048
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] ab = ReadInts();
            long a = ab[0];
            long b = ab[1];
            if (a * b < 0)
            {
                Console.WriteLine(b - a - 1);
            }
            else
            {
                Console.WriteLine(b - a);
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