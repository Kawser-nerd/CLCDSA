using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_029
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int digit = 1;
            int cnt = 0;
            for (; digit <= 9; digit++)
            {
                int div = (int)Math.Pow(10, digit);
                int val = n / div;
                cnt += val * div / 10;
                int margin = n % div;
                if (margin >= div / 5)
                {
                    cnt += div / 10;
                }
                else if (margin >= div / 10)
                {
                    cnt += margin % (div / 10) + 1;
                }
                //Console.WriteLine(val * div / 10);
            }

            Console.WriteLine(cnt);
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