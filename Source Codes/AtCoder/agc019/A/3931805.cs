using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _019_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long[] qhsd = ReadLongs();
            long n = ReadLong();

            qhsd[1] = Math.Min(qhsd[0] * 2, qhsd[1]);
            qhsd[2] = Math.Min(qhsd[1] * 2, qhsd[2]);
            qhsd[3] = Math.Min(qhsd[2] * 2, qhsd[3]);
            long                res = (n / 2) * qhsd[3];
            if (n % 2 == 1)
            {
                res += qhsd[2];
            }
            Console.WriteLine(res);
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