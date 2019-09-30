using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_B
{
    class _057
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
            int[] array = new int[n];
            for(int i = 0; i < n; i++)
            {
                array[i] = ReadInt();
            }
            long[,] dp = new long[n + 1, n + 1];
            //i?????j????????????????
            dp[1, 1] = 1;
            long all = array[0];
            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    long next = dp[i - 1, j - 1]
                        * (all + array[i - 1]) / all + 1;
                    dp[i, j] = next;
                    if (j <= i - 1)
                        dp[i, j] = Math.Min(dp[i, j], dp[i - 1, j]);
                }
                all += array[i - 1];
            }
            if (all == k)
            {
                Console.WriteLine(1);
                return;
            }
            /*
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    Console.Write(dp[i, j] + " ");
                }
                Console.WriteLine();
            }
            */
            for(int i = 0; i <= n; i++)
            {
                if (dp[n, i] > k)
                {
                    Console.WriteLine(i - 1);
                    return;
                }
            }
            Console.WriteLine(n);
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