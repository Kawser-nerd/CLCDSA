using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_038
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] array = ReadInts();

            long l = 0, r = 0;
            long allPat = 0;
            for (; r < n - 1; r++)
            {
                if (array[r] < array[r + 1])
                {
                    continue;
                }
                else
                {

                    allPat += (r - l + 1) * (r - l + 2) / 2;
                    l = r + 1;
                }
            }
            allPat += (r - l + 1) * (r - l + 2) / 2;

            Console.WriteLine(allPat);
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