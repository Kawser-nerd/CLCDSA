using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _003_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = ReadInt();
            }
            long pair = 0;
            for (int i = 0; i < n; i++)
            {
                pair += array[i] / 2;
                array[i] = array[i] % 2;
                if (i < n - 1 &&
                    array[i] > 0 && array[i + 1] > 0)
                {
                    pair++;
                    array[i + 1]--;
                }
            }
            Console.WriteLine(pair);
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