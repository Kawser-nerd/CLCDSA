using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.Virtual
{
    class AGC008_B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            long[] array = ReadLongs();
            long[] sums = new long[n];
            sums[0] = array[0];
            long[] plusSums = new long[n];
            if (array[0] > 0) plusSums[0] = array[0];
            for (int i = 1; i < n; i++)
            {
                sums[i] = sums[i - 1] + array[i];
                plusSums[i] = plusSums[i - 1];
                if (array[i] > 0) plusSums[i] += array[i];
            }
            long res = 0;
            for(int i = k - 1; i < n; i++)
            {
                long val = plusSums[n - 1] - plusSums[i];
                long range = sums[i];
                if (i - k >= 0)
                {
                    val += plusSums[i - k];
                    range -= sums[i - k];
                }
                range = Max(0, range);
                res = Max(res, val + range);
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