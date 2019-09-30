using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

    public class Program
    {
        public static void Main()
        {


            var fsline = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            int W = fsline[0];
            var sdline = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int N = sdline[0];
            int K = sdline[1];

            int[] a = new int[N];
            int[] b = new int[N];

            for (int i = 0; i < N; i++)
            {
                var tmpline = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
                a[i] = tmpline[0];
                b[i] = tmpline[1];
            }

            int[,,] dp = new int[N+1, W+1,K+1];
            int outmax = 0;
            dp[0, 0, 0] = 0;
           
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j <= W; j++)
                {
                    for (int r = 0; r < K; r++)
                    {
                        if (j - a[i] < 0)
                        {
                            dp[i + 1, j, r + 1] = dp[i, j, r + 1];
                        }
                        else
                        {
                            dp[i + 1, j, r + 1] = Math.Max(dp[i, j, r + 1], dp[i, j - a[i], r] + b[i]);

                        }
                    }

                }
            }


            for (int i = 0; i <= K; i++)
            {
                outmax = Math.Max(outmax, dp[N, W, i]);
            }
            Console.WriteLine(outmax);
        }
	}