using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _015
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] res = new int[6];
            for(int i = 0; i < n; i++)
            {
                double[] ts = ReadDoubles();
                int max = (int)(ts[0] * 10);
                int min = (int)(ts[1] * 10);

                if (max >= 350) res[0]++;
                if (max >= 300 && max < 350) res[1]++;
                if (max >= 250 && max < 300) res[2]++;
                if (min >= 250) res[3]++;
                if (min < 0 && max >= 0) res[4]++;
                if (max < 0) res[5]++;
            }
            for (int i = 0; i < 6; i++)
            {
                Write(res[i]);
                if (i < 5) Write(" ");
            }
            WriteLine();
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