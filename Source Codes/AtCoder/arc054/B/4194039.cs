using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
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
            double p = ReadDouble();
            double x = -1.5 * Math.Log(1.5 / p / Math.Log(2)) / Math.Log(2);
            //Console.WriteLine(1.5 / p / Math.Log(2));
            //Console.WriteLine(x);
            if (x < 0) x = 0;
            Console.WriteLine(x + p / Math.Pow(2, x / 1.5));
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