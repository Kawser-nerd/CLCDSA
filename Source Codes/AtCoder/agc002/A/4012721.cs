using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _002_A
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
            if (a * b < 0 || a == 0 || b == 0)
            {
                Console.WriteLine("Zero");
            }
            else
            {
                if (0 < a || (b < 0 && (b - a) % 2 == 1))
                {
                    Console.WriteLine("Positive");
                }
                else
                {
                    Console.WriteLine("Negative");
                }
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