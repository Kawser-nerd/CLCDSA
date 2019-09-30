using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _008_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] xy = ReadInts();
            int x = xy[0];
            int y = xy[1];
            if (x == y)
            {
                Console.WriteLine(0);
                return;
            }
            int res = 0;
            bool increase = Math.Abs(y) > Math.Abs(x);
            if (increase && x < 0) res++;
            else if (!increase && x > 0) res++;
            res += Math.Abs(Math.Abs(y) - Math.Abs(x));
            if (increase && y < 0) res++;
            else if (!increase && y > 0) res++;
            Console.WriteLine(res);
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