using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _043
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] ds = new int[n];
            for(int i = 0; i < n; i++)
            {
                ds[i] = ReadInt();
            }
            Array.Sort(ds);
            long mask = 1000000000 + 7;
            int[] indexes = new int[n];
            for(int i = 0; i < n; i++)
            {
                int bottom = 0;
                int top = n;
                while (bottom + 1 < top)
                {
                    int mid = (bottom + top) / 2;
                    if (ds[mid] < ds[i] * 2)
                    {
                        bottom = mid;
                    }
                    else
                    {
                        top = mid;
                    }
                }
                indexes[i] = bottom + 1;
            }
            long[,] cntSums = new long[n, 3];
            for(int i = 0; i < 3; i++)
            {
                for(int j = n - 2; j >= 0; j--)
                {
                    int index = indexes[j];
                    if (index >= n) continue;
                    if (i == 0)
                    {
                        cntSums[j, i] = n - index;
                    }
                    else
                    {
                        cntSums[j, i] = cntSums[index, i - 1];
                    }
                    cntSums[j, i] += cntSums[j + 1, i];
                    cntSums[j, i] %= mask;
                }
            }
            //for (int i = 0; i < n; i++) WriteLine(cntSums[i, 0] + " " + cntSums[i, 1] + " " + cntSums[i, 2]);
            WriteLine(cntSums[0, 2]);
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