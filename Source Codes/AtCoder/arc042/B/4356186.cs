using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _042
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            double[] xy = ReadDoubles();
            double x = xy[0];
            double y = xy[1];
            int n = ReadInt();
            double[][] points = new double[n][];
            for(int i = 0; i < n; i++)
            {
                points[i] = ReadDoubles();
            }
            double min = double.MaxValue;
            for(int i = 0; i < n; i++)
            {
                double[] xy1 = points[i];
                double[] xy2 = points[(i + 1) % n];
                double a = Sqrt(Pow(xy1[0] - x, 2) + Pow(xy1[1] - y, 2));
                double b = Sqrt(Pow(xy2[0] - x, 2) + Pow(xy2[1] - y, 2));
                double c = Sqrt(Pow(xy1[0] - xy2[0], 2)
                    + Pow(xy1[1] - xy2[1], 2));
                double val = (a + b + c) * (-a + b + c)
                    * (a - b + c) * (a + b - c) / 4 / c / c;
                min = Min(min, Sqrt(val));
            }
            WriteLine(min);
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