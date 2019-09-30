using System;
using System.Linq;

class Program
{
    static int W;
    static int N;
    static int K;
    static int[] A;
    static int[] B;

    static void Main()
    {
        /* ??????? */
        W = int.Parse(Console.ReadLine());
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = input[0];
        K = input[1];
        A = new int[N];
        B = new int[N];
        for (int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split().Select(int.Parse).ToArray();
            A[i] = input[0];
            B[i] = input[1];
        }

        /*
         * dp[i,j,k] : i????????j?k?????????
         */
        int[,,] dp = new int[N + 1, W + 1, K + 1];
        for (int i = 1; i <= N; i++)
        {
            int a = A[i - 1];
            int b = B[i - 1];
            for (int j = 0; j <= W; j++)
            {
                for (int k = 1; k <= K; k++)
                {
                    try
                    {
                        dp[i, j, k] = Math.Max(dp[i - 1, j - a, k - 1] + b, dp[i - 1, j, k]);
                    }
                    catch
                    {
                        dp[i, j, k] = dp[i - 1, j, k];
                    }
                }
            }
        }

        /* ?????? */
        int ans = 0;
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k <= K; k++)
            {
                ans = Math.Max(ans, dp[N, j, k]);
            }
        }
        Console.WriteLine(ans);
    }
}