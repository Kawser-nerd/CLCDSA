using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _054
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] lxysd = ReadInts();
            int l = lxysd[0];
            int x = lxysd[1];
            int y = lxysd[2];
            int s = lxysd[3];
            int d = lxysd[4];
            double forward = (l + d - s) % l;
            double reverse = l - forward;
            if (y > x)
            {
                Console.WriteLine(
                    Math.Min(forward / (x + y), reverse / (y - x)));
            }
            else
            {
                Console.WriteLine(forward / (x + y));
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