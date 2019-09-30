using System;
using System.Linq;

namespace arc060_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int i = 0; i < x[0]; i++) a[i] -= x[1];
            long[,] dp = new long[x[0],10000]; dp[0,5000]++; dp[0,5000 + a[0]]++;
            for (int i = 1; i < x[0]; i++)
            {
                for (int j = 0; j < 10000; j++)
                {
                    dp[i,j] += dp[i - 1,j];
                    int n = j - a[i];
                    if (10000 > n && n >= 0) dp[i,j] += dp[i - 1,n];
                }
            }
            Console.WriteLine(dp[x[0] - 1,5000] - 1);
        }
    }
}