using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _001_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] nx = ReadLongs();
            long n = nx[0];
            long x = nx[1];
            Console.WriteLine(Length(n, x));
        }

        static long Length(long n, long x)
        {
            if (x <= n - x)
            {
                long cnt = (n - x) / x;
                if ((n - x) % x == 0)
                {
                    return x * 3 * cnt;
                }
                else
                {
                    long margin = (n - x) % x;
                    return x * 3 * cnt + Length(margin + x, x);
                }
            }
            else
            {

                long cnt = x / (n - x);
                if (x % (n - x) == 0)
                {
                    return (n - x) * 3 * cnt;
                }
                else
                {
                    long nextX = x % (n - x);
                    return (n - x) * 3 * cnt + Length(n - x + nextX, nextX);
                }
            }
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