using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.AGC_Challenge
{
    class _004_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nx = ReadInts();
            int n = nx[0];
            long x = nx[1];
            int[] array = ReadInts();
            Array.Reverse(array);
            long resTime = long.MaxValue;
            var times = new long[n];
            for (int i = 0; i < n; i++)
            {
                long time = 0;
                for(int j = 0; j < n; j++)
                {
                    if (i == 0) times[j] = array[j];
                    else times[j] = Math.Min(times[j], array[(j + i) % n]);
                    time += times[j];
                }
                resTime = Math.Min(resTime, time + x * i);
            }
            Console.WriteLine(resTime);
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