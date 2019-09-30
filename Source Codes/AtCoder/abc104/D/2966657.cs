using System;

public class Hello
{
    public static int MOD = 1000000007;
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var sL = s.Length;
        var dp = new long  [sL + 1, 4];
        dp[0, 0] = 1;
        for (int i = 0; i < sL; i++)
        {
            if (s[i] == 'A' | s[i] == '?')
            {
                for (int j = 0; j < 4; j++)
                {
                    dp[i + 1, j] += dp[i, j];
                    dp[i + 1, j] %= MOD;
                }
                dp[i + 1, 1] += dp[i, 0];
                dp[i + 1, 1] %= MOD;
            }
            if (s[i] == 'B' | s[i] == '?')
            {
                for (int j = 0; j < 4; j++)
                {
                    dp[i + 1, j] += dp[i, j];
                    dp[i + 1, j] %= MOD;
                }
                dp[i + 1, 2] += dp[i, 1];
                dp[i + 1, 2] %= MOD;
            }
            if (s[i] == 'C' | s[i] == '?')
            {
                for (int j = 0; j < 4; j++)
                {
                    dp[i + 1, j] += dp[i, j];
                    dp[i + 1, j] %= MOD;
                }
                dp[i + 1, 3] += dp[i, 2];
                dp[i + 1, 3] %= MOD;
            }
        }
        Console.WriteLine(dp[sL,3]);
    }
}