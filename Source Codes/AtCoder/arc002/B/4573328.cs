using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _002
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] ymd = Array.ConvertAll(Read().Split('/'), int.Parse);
            int y = ymd[0];
            int m = ymd[1];
            int d = ymd[2];
            int[] monthes = new int[12] {
                31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            bool uruu = y % 4 == 0 && !(y % 100 == 0 && y % 400 > 0);
            while (y % (m * d) > 0)
            {
                d++;
                int mCnt = monthes[m - 1];
                if (m == 2 && uruu) mCnt++;
                if (d == mCnt + 1)
                {
                    d = 1;
                    m++;
                    if (m == 13)
                    {
                        m = 1;
                        y++;
                        uruu = y % 4 == 0 && !(y % 100 == 0 && y % 400 > 0);
                    }
                }
            }
            Write(y + "/");
            Write(m.ToString("00") + "/");
            WriteLine(d.ToString("00"));
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