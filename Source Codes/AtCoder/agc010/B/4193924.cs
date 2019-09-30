using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _010_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long n = ReadInt();
            var array = ReadInts();
            long sum = 0;
            for (int i = 0; i < n; i++) sum += array[i];
            long div = n * (n + 1) / 2;
            if (sum % div > 0)
            {
                Console.WriteLine("NO");
                return;
            }
            long k = sum / div;
            long kk = k;
            for (int i = 0; i < n; i++)
            {
                long delta = array[(i + 1) % n] - array[i] - k;
                delta *= -1;
                long val = delta / n;
                if (delta < 0 || delta % n > 0 || val > kk)
                {
                    Console.WriteLine("NO");
                    return;
                }
                kk -= val;
            }
            Console.WriteLine("YES");
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