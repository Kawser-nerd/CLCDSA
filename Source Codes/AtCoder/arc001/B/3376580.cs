using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_2_Challenge
{
    class _1
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] ab = ReadInts();
            int margin = Math.Abs(ab[0]-ab[1]);
            int tenCnt = margin / 10;
            if (margin % 10 >= 8) tenCnt++;
            margin = Math.Abs(10 * tenCnt - margin);
            int fiveCnt = margin / 5;
            if (margin % 5 == 4) fiveCnt++;
            margin = Math.Abs(5 * fiveCnt - margin);
            int oneCnt = margin;
            Console.WriteLine(tenCnt + fiveCnt + oneCnt);
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