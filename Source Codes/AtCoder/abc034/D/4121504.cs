using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_034
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            var ws = new long[n];
            var ps = new int[n];
            for (int i = 0; i < n; i++)
            {
                long[] wp = ReadLongs();
                ws[i] = wp[0];
                ps[i] = (int)wp[1];
            }

            double bottom = 0;
            double top = 100;
            double thres = 0.000001;
            while (top-bottom>=thres)
            {
                double x = (bottom + top) * 0.5;
                double[] wpps = new double[n];
                for(int i =0; i < n; i++)
                {
                    wpps[i] = ws[i] * (ps[i] - x);
                }
                Array.Sort(wpps);
                Array.Reverse(wpps);
                double val = 0;
                for(int i = 0; i < k; i++)
                {
                    val += wpps[i];
                }
                if (val >= 0)
                {
                    bottom = x;
                }
                else
                {
                    top = x;
                }
            }
            Console.WriteLine(bottom);
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