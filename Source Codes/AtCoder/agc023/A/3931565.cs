using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _023_A
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
            var sums = new Dictionary<long, long>();
            sums.Add(0, 1);
            long sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += array[i];
                if (!sums.ContainsKey(sum))
                {
                    sums.Add(sum, 0);
                }
                sums[sum]++;
            }

            long res = 0;
            foreach(var key in sums.Keys)
            {
                //Console.WriteLine(key+" "+sums[key]);
                res += sums[key] * (sums[key] - 1) / 2;
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