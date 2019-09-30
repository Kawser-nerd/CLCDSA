using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _046
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] ab = ReadInts();
            int a = ab[0];
            int b = ab[1];
            if (a == b)
            {
                if (n % (a + 1) == 0)
                {
                    Console.WriteLine("Aoki");
                }
                else
                {
                    Console.WriteLine("Takahashi");
                }
            }
            else
            {
                if (a >= n || a > b)
                {
                    Console.WriteLine("Takahashi");
                }
                else
                {
                    Console.WriteLine("Aoki");
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