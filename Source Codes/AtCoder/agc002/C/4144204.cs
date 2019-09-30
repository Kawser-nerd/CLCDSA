using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _002_C
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nl = ReadInts();
            int n = nl[0];
            int l = nl[1];
            int[] array = ReadInts();
            int maxI = 0;
            for(int i = 0; i + 1 < n; i++)
            {
                if (array[maxI] + array[maxI + 1] < array[i] + array[i + 1])
                    maxI = i;
            }
            if (array[maxI] + array[maxI + 1] < l)
            {
                Console.WriteLine("Impossible");
                return;
            }
            Console.WriteLine("Possible");
            for(int i = 0; i < maxI; i++)
            {
                Console.WriteLine(i + 1);
            }
            for(int i = n-1; i-1 >maxI; i--)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine(maxI+1) ;
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