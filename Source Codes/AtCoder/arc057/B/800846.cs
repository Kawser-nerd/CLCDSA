using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] nk = Console.ReadLine().Split(' ');
            int n = int.Parse(nk[0]);
            int k = int.Parse(nk[1]);
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }
            long[,] dp = new long[n, n + 1];
            long[] asum = new long[n];
            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    asum[i] += a[j];
                }
            }
            if (asum[n - 1] == k)
            {
                Console.WriteLine(1);
                return;
            }
            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < n + 1; j++)
                {
                    if (i + 1 < j)
                    {
                        dp[i, j] = long.MaxValue;
                        continue;
                    }
                    if (j == 0)
                    {
                        dp[i, j] = 0;
                        continue;
                    }
                    if (i == 0)
                    {
                        dp[i, j] = 1;
                        continue;
                    }

                    long zerosho, kataseru;
                    zerosho = dp[i - 1, j];
                    if (dp[i - 1, j - 1] == long.MaxValue)
                    {
                        kataseru = long.MaxValue;
                    }
                    else
                    {
                        long dummy;
                        kataseru = Math.DivRem((dp[i - 1, j - 1] * asum[i]), asum[i - 1], out dummy) + 1;
                    }
                    dp[i, j] = Math.Min(zerosho, kataseru);
                }
            }
            for(int j = n; j >= 0; j--)
            {
                if (dp[n - 1, j] <= k)
                {
                    Console.WriteLine(j);
                    return;
                }
            }
            Console.WriteLine(0);
        }

    }
}