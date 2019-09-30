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

        int[][][] dp = new int[60][][];
        for(int i = 0; i < 60; i++)
        {
            dp[i] = new int[10010][];
            for(int j = 0; j < 10010; j++)
            {
                dp[i][j] = new int[60];
            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int w = 0; w <= W; w++)
            {
                for(int k=1;k<=K;k++)
                {
                    if (w >= A[i])
                    {
                        dp[i + 1][w][k] = Max(dp[i][w][k], dp[i][w][k - 1]);
                        dp[i + 1][w][k] = Max(dp[i + 1][w][k], dp[i][w - A[i]][k - 1] + B[i]);
                    }
                    else
                    {
                        dp[i + 1][w][k] = Max(dp[i][w][k], dp[i][w][k - 1]);
                    }
                }
            }
        }

        WriteLine(dp[N][W][K]);
}
}