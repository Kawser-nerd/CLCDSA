using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _044
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] array = ReadInts();
            int[] dstArray = new int[n];
            for(int i = 0; i < n; i++)
            {
                if((i==0&&array[i]>0)
                    || (i > 0 && array[i] == 0))
                {
                    WriteLine(0);
                    return;
                }
                else
                {
                    dstArray[array[i]]++;
                }
            }

            long mask = 1000000000 + 7;
            long res = 1;
            int cnt = 1;
            for (int i = 1; i < n&&cnt<n; i++)
            {
                if (dstArray[i] == 0)
                {
                    WriteLine(0);
                    return;
                }
                long prevPat = 1;
                for(int j = 0; j < dstArray[i - 1]; j++)
                {
                    prevPat *= 2;
                    prevPat %= mask;
                }
                prevPat -= 1;
                if (prevPat < 0) prevPat += mask;

                long pat = prevPat;
                for(int j = 0; j < dstArray[i]; j++)
                {
                    res *= pat;
                    res %= mask;
                    pat *= 2;
                    pat %= mask;
                    cnt++;
                }
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