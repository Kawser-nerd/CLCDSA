using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _036
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] hs = new int[n];
            for (int i = 0; i < n; i++) hs[i] = ReadInt();
            int[] leftCnts = new int[n];
            for (int i = 1; i < n; i++)
            {
                if (hs[i] > hs[i - 1])
                    leftCnts[i] = leftCnts[i - 1] + 1;
            }
            int[] rightCnts = new int[n];
            for (int i = n - 2; i >= 0; i--)
            {
                if (hs[i] > hs[i + 1])
                    rightCnts[i] = rightCnts[i + 1] + 1;
            }
            int res = 0;
            for(int i = 0; i < n; i++)
            {
                res = Max(res, leftCnts[i] + rightCnts[i] + 1);
            }
            WriteLine(res);
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