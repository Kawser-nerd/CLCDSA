using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    const long mod = (long)1e9 + 7;

    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Trim();

        var ts = s.Select(x => (long)x - 'a').ToArray();
        var appearance = new long[26];
        for (int i = 0; i < ts.Length; i++)
        {
            appearance[ts[i]]++;
        }

        var dp = new long[appearance.Length];
        for (int i = 0; i < appearance.Length; i++)
        {
            for (int j = 0; j < dp.Length; j++)
            {
                if (i - j < 1)
                {
                    break;
                }

                dp[i - j] += dp[i - j - 1] * appearance[i] % mod;
                dp[i - j] %= mod;
            }
            dp[0] += appearance[i];
            dp[0] %= mod;
        }
        var k = dp.Aggregate((x, y) => (x + y) % mod);
        Console.WriteLine(k);
    }
}