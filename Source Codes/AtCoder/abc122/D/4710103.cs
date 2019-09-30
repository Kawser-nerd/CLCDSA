using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var N = int.Parse(ReadLine());
        var dp = new int[N + 1, 4, 4, 4];
        dp[0, 3, 3, 3] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        for (int f = 0; f < 4; f++)
                        {

                            if (k == 0 && l == 2 && f == 1
                                || k == 0 && l == 1 && f == 2
                                || k == 2 && l == 0 && f == 1
                                || j == 0 && l == 2 && f == 1
                                || j == 0 && k == 2 && f == 1)
                            {
                                continue;
                            }
                            dp[i + 1, k, l, f] = (dp[i + 1, k, l, f] + dp[i, j, k, l]) % 1000000007;
                        }
                    }
                }
            }

        }
        var ans = 0L;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    ans = (ans + dp[N, i, j, k]) % 1000000007;
                }
            }
        }
        WriteLine(ans);
    }
}