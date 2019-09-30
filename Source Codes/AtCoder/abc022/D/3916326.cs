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
            double xBefore = 0;
            double yBefore = 0;
            double xAfter = 0;
            double yAfter = 0;
            for(int i = 0; i < n; i++)
            {
                xBefore += xyBefore[i][0];
                yBefore += xyBefore[i][1];
                xAfter += xyAfter[i][0];
                yAfter += xyAfter[i][1];
            }
            xBefore /=  n;
            yBefore /= n;
            xAfter /= n;
            yAfter /= n;

            double distBefore = Math.Pow(xyBefore[0][0] - xBefore, 2)
                    + Math.Pow(xyBefore[0][1] - yBefore, 2);
            double distAfter = Math.Pow(xyAfter[0][0] - xAfter, 2)
                    + Math.Pow(xyAfter[0][1] - yAfter, 2);

            for (int i = 1; i < n; i++)
            {
                distBefore = Math.Max(distBefore,
                    Math.Pow(xyBefore[i][0] - xBefore, 2)
                    + Math.Pow(xyBefore[i][1] - yBefore, 2));
                distAfter = Math.Max(distAfter,
                    Math.Pow(xyAfter[i][0] - xAfter, 2)
                    + Math.Pow(xyAfter[i][1] - yAfter, 2));
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