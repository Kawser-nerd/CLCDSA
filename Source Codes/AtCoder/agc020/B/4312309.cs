using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _020_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int k = ReadInt();
            long[] array = ReadLongs();
            Array.Reverse(array);
            if (array[0] != 2)
            {
                Console.WriteLine(-1);
                return;
            }
            long min = 2;
            long max = 3;
            for (int i = 1; i < k; i++)
            {
                if (min % array[i] != 0)
                {
                    min = (min / array[i] + 1) * array[i];
                }
                if (min > max)
                {
                    Console.WriteLine(-1);
                    return;
                }
                max = (max / array[i]) * array[i] + array[i] - 1;
                //Console.WriteLine(min + " " + max);
            }
            Console.WriteLine(min + " " + max);
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