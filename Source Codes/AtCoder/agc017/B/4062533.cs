using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _017_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nabcd = ReadInts();
            int n = nabcd[0];
            long a = nabcd[1];
            long b = nabcd[2];
            long c = nabcd[3];
            long d = nabcd[4];
            long delta = b - a;
            for(long m = 0; m < n; m++)
            {
                if(c*(n-1-m)-d*m<=delta
                    && delta <= -c * m + d * (n - 1 - m))
                {
                    Console.WriteLine("YES");
                    return;
                }
            }
            Console.WriteLine("NO");
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