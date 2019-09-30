using System;
using static System.Console;
using static System.Math;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        int W = int.Parse(ReadLine());
        var input = ReadLine().Split();
        int N = int.Parse(input[0]);
        int K = int.Parse(input[1]);
        int[] A = new int[N];
        int[] B = new int[N];
        for (int i = 0; i < N; i++)
        {
            var input0 = ReadLine().Split();
            A[i] = int.Parse(input0[0]);
            B[i] = int.Parse(input0[1]);
        }

        int[][][] dp = new int[N+1][][];
        for(int i = 0; i < N+1; i++)
        {
            dp[i] = new int[W+1][];
            for(int j = 0; j < W+1; j++)
            {
                dp[i][j] = new int[K+1];
            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int w = 0; w <= W; w++)
            {
                for(int k=0;k<K;k++)
                {
                    if (w >= A[i])
                    {
                        dp[i + 1][w][k+1] = Max(dp[i][w][k+1],dp[i][w - A[i]][k] + B[i]);
                    }
                    else
                    {
                        dp[i + 1][w][k+1] =dp[i][w][k+1];
                    }
                }
            }
        }

        WriteLine(dp[N][W][K]);
}
}