using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _051
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int k = ReadInt();
            long a = 1;
            long b = 0;
            for(int i = 0; i < k; i++)
            {
                long tmp = a;
                a = b;
                b = tmp;
                while (a <= b) a += b;
            }
            Console.WriteLine(a + " " + b);
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