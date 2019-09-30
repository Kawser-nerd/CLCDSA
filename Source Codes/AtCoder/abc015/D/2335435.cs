using System;
using System.Collections.Generic;
using System.Linq;

namespace app
{
    class Program
    {

        static void Main(string[] args)
        {
            string[] str;
            // int N = int.Parse(Console.ReadLine());
            // str = Console.ReadLine().Split(' ');
            // int N = int.Parse(str[0]), M = int.Parse(str[1]), D = int.Parse(str[2]);
            
            int W = int.Parse(Console.ReadLine());
            str = Console.ReadLine().Split(' ');
            int N = int.Parse(str[0]);
            int K = int.Parse(str[1]);
            int[] A = new int[N];
            int[] B = new int[N];
            for (int i = 0; i < N; i++) {
                str = Console.ReadLine().Split(' ');
                A[i] = int.Parse(str[0]);
                B[i] = int.Parse(str[1]);
            }

            int[,,] dp = new int[W+1, K+1, N+1];

            for (int i = 0; i <= W; i++) {
                for (int j = 0; j <= K; j++) {
                    for (int k = 0; k < N; k++) {
                        if (i-A[k] >= 0 && j > 0)
                            dp[i, j, k+1] = Math.Max(dp[i, j, k], dp[i-A[k], j-1, k] + B[k]);
                        else
                            dp[i, j, k+1] = dp[i, j, k];
                    }
                }
            }

            Console.WriteLine(dp[W, K, N]);

            // Console.WriteLine(0);
        }
    }
}