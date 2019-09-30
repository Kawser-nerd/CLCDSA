using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.D_Challenge
{
    class ABC_038
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var whs = new int[n][];
            for (int i = 0; i < n; i++)
            {
                whs[i] = ReadInts();
            }
            whs = whs.OrderBy(a => -a[1]).ToArray();//?????
            whs = whs.OrderBy(a => a[0]).ToArray();

            var dp = new List<int>();//??????
            dp.Add(whs[0][1]);
            for (int i = 1; i < n; i++)
            {
                if (dp[dp.Count - 1] < whs[i][1])
                {
                    dp.Add(whs[i][1]);
                }
                else
                {
                    dp[BinarySearch(dp, whs[i][1])] = whs[i][1];
                }
            }

            Console.WriteLine(dp.Count);
        }

        //value??????????
        static int BinarySearch(List<int> list, int value)
        {
            int bottom = 0;
            int top = list.Count;
            while (top - bottom > 1)
            {
                int x = (top + bottom) / 2;
                if (list[x] <= value)
                {
                    bottom = x;
                }
                else
                {
                    top = x;
                }
            }
            if (list[bottom] < value) bottom++;
            return bottom;
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