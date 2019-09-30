using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _008_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];
            long[] array = ReadLongs();
            long sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (array[i] > 0) sum += array[i];
            }
            long plus = 0;
            long minus = 0;
            long delta = 0;
            for(int i = 0; i < k; i++)
            {
                if (array[i] > 0) plus += array[i];
                else minus += array[i];
                delta = Math.Max(-plus, minus);
            }
            for (int i = 1; i <= n - k; i++)
            {
                if (array[i - 1] > 0) plus -= array[i - 1];
                else minus -= array[i - 1];
                if (array[i + k - 1] > 0) plus += array[i + k - 1];
                else minus += array[i + k - 1];
                long next = Math.Max(-plus, minus);
                delta = Math.Max(delta, next);
            }
            Console.WriteLine(sum + delta);
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