using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _004
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            string[] ss = Read().Split('/');
            long x = long.Parse(ss[0]);
            long y = long.Parse(ss[1]);
            long gcd = GCD(x, y);
            x = x / gcd;
            y = y / gcd;
            decimal min = Max((2 * x - y) / y / y + 1, 1);
            decimal max = (2 * x + y) / y / y;
            if (min > max)
            {
                WriteLine("Impossible");
            }
            else
            {
                for (decimal i = min; i <= max; i++)
                {
                    WriteLine(y * i + " " + ((i * y) * (i * y + 1) / 2 - i * x));
                }
            }
        }

        static long GCD(long a, long b)
        {
            if (b > a)
            {
                long temp = b;
                b = a;
                a = temp;
            }
            long c = b;
            do
            {
                c = a % b;
                a = b;
                b = c;
            } while (c > 0);
            return a;
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