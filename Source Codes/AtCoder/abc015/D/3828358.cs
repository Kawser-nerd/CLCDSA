using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_015
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int w = ReadInt();
            int[] nk = ReadInts();
            var abs = new int[nk[0]][];
            for (int i = 0; i < nk[0]; i++)
            {
                abs[i] = ReadInts();
            }
            var dp = new int[nk[1] + 1, w + 1];
            for (int j = 1; j <= nk[1]; j++)
            {
                for (int k = abs[0][0]; k <= w; k++)
                {
                    dp[j, k] = abs[0][1];
                }
            }
            for (int i = 1; i < nk[0]; i++)
            {
                var nextDp = new int[nk[1] + 1, w + 1];
                for (int j = 1; j <= nk[1]; j++)
                {
                    for (int k = 0; k <= w; k++)
                    {
                        if (k >= abs[i][0])
                        {
                            nextDp[j, k] = Math.Max(dp[j, k],
                                dp[j - 1, k - abs[i][0]] + abs[i][1]);
                        }
                        else
                        {
                            nextDp[j, k] = dp[j, k];
                        }
                    }
                }
                dp = nextDp;
            }
            /*
            for(int i = 0; i <= nk[1]; i++)
            {
                for(int j = 0; j <= w; j++)
                {
                    Console.Write(dp[i, j]+" ");
                }
                Console.WriteLine();
            }
            */
            Console.WriteLine(dp[nk[1], w]);
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