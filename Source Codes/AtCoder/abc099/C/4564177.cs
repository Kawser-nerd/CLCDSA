using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var N = Int32.Parse(Console.ReadLine());
        var dp = new int[N + 1];
        dp[0] = 0;
        for (int i = 1; i <= N; ++i) dp[i] = 100000;
        for (int i=1;i<=N;i++)
        {
            for(int j = 1; j <= i; j *= 6)
            {
                dp[i] = Math.Min(dp[i],dp[i-j]+1);
            }
            for (int k = 1; k <= i; k *= 9)
            {
                dp[i] = Math.Min(dp[i], dp[i - k] + 1);
            }
        }
        Console.WriteLine(dp[N]);
    }
}