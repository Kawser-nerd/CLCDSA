using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _011_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            long[] array = ReadLongs();
            Array.Sort(array);
            long[] sums = new long[n];
            sums[0] = array[0];
            for(int i =1; i < n; i++)
            {
                sums[i] = sums[i - 1] + array[i];
            }
            int cnt = 1;
            for(int i = n - 2; i >= 0; i--)
            {
                if (sums[i]*2 < array[i + 1])
                {
                    Console.WriteLine(cnt);
                    return;
                }
                cnt++;
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