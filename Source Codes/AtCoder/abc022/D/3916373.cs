using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_022
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var xyBefore = new int[n][];
            for(int i = 0; i < n; i++)
            {
                xyBefore[i] = ReadInts();
            }
            var xyAfter = new int[n][];
            for(int i = 0; i < n; i++)
            {
                xyAfter[i] = ReadInts();
            }
            double[] gB = new double[2] { 0, 0 };
            double[] gA = new double[2] { 0, 0 };
            for(int i = 0; i < n; i++)
            {
                gB[0] += xyBefore[i][0];
                gB[1] += xyBefore[i][1];
                gA[0] += xyAfter[i][0];
                gA[1] += xyAfter[i][1];
            }
            gB[0] /= n;
            gB[1] /= n;
            gA[0] /= n;
            gA[1] /= n;

            double distBefore = Math.Pow(xyBefore[0][0] - gB[0], 2)
                    + Math.Pow(xyBefore[0][1] - gB[1], 2);
            double distAfter = Math.Pow(xyAfter[0][0] - gA[0], 2)
                    + Math.Pow(xyAfter[0][1] - gA[1], 2);

            for (int i = 1; i < n; i++)
            {
                distBefore = Math.Max(distBefore,
                    Math.Pow(xyBefore[i][0] - gB[0], 2)
                    + Math.Pow(xyBefore[i][1] - gB[1], 2));
                distAfter = Math.Max(distAfter,
                    Math.Pow(xyAfter[i][0] - gA[0], 2)
                    + Math.Pow(xyAfter[i][1] - gA[1], 2));
            }

            Console.WriteLine(Math.Sqrt(distAfter / distBefore));
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