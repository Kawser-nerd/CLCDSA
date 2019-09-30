using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var x = new double[n];
            var y = new double[n];
            var c = new double[n];
            for (int i = 0; i < n; i++)
            {
                var str = Console.ReadLine().Split().Select(s => Int32.Parse(s)).ToArray();
                x[i] = str[0];
                y[i] = str[1];
                c[i] = str[2];
            }

            double l = 0;
            double r = 100000 * 1000 + 1;

            while (r - l > 0.0001)
            {
                var m = (l + r) / 2.0;
                if (Possible(m, x, y, c))
                    r = m;
                else
                    l = m;
            }

            Console.WriteLine(r);
        }

        static bool Possible(double t, double[] x, double[] y, double[] c)
        {
            double x1 = -100001;
            double y1 = -100001;
            double x2 = 100001;
            double y2 = 100001;

            for (int i = 0; i < x.Length; i++)
            {
                if (x[i] - t / c[i] > x2) return false;
                if (y[i] - t / c[i] > y2) return false;
                if (x[i] + t / c[i] < x1) return false;
                if (y[i] + t / c[i] < y1) return false;

                x1 = Math.Max(x1, x[i] - t / c[i]);
                y1 = Math.Max(y1, y[i] - t / c[i]);
                x2 = Math.Min(x2, x[i] + t / c[i]);
                y2 = Math.Min(y2, y[i] + t / c[i]);
            }

            return true;
        }
    }
}