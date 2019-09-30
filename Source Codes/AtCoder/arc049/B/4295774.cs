using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _049
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            double[][] xycs = new double[n][];
            for (int i = 0; i < n; i++)
            {
                xycs[i] = ReadDoubles();
            }
            double bottom = -110000;
            double top = 110000;
            double thres = 0.000001;
            double xCost = 0;
            while (top - bottom > thres)
            {
                double mid = (bottom + top) / 2;
                double lCost = 0;
                double rCost = 0;
                for(int i = 0; i < n; i++)
                {
                    if (xycs[i][0] < mid)
                    {
                        lCost = Math.Max(
                            lCost, (mid - xycs[i][0]) * xycs[i][2]);
                    }
                    else
                    {
                        rCost = Math.Max(
                            rCost, (xycs[i][0]-mid) * xycs[i][2]);
                    }
                }
                if (lCost < rCost)
                {
                    bottom = mid;
                }
                else
                {
                    top = mid;
                }
                xCost = Math.Max(lCost, rCost);
            }
            bottom = -110000;
            top = 110000;
            double yCost = 0;
            while (top - bottom > thres)
            {
                double mid = (bottom + top) / 2;
                double lCost = 0;
                double rCost = 0;
                for (int i = 0; i < n; i++)
                {
                    if (xycs[i][1] < mid)
                    {
                        lCost = Math.Max(
                            lCost, (mid - xycs[i][1]) * xycs[i][2]);
                    }
                    else
                    {
                        rCost = Math.Max(
                            rCost, (xycs[i][1] - mid) * xycs[i][2]);
                    }
                }
                if (lCost < rCost)
                {
                    bottom = mid;
                }
                else
                {
                    top = mid;
                }
                yCost = Math.Max(lCost, rCost);
            }
            Console.WriteLine(Math.Max(xCost, yCost));
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