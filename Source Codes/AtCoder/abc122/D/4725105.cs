using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    const int Mod = (int)1e9 + 7;
    const int A = 0;
    const int C = 1;
    const int G = 2;
    const int T = 3;
    
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());

        var dp = new long[2][];
        dp[0] = E.Repeat(1L, 1 << 6).ToArray();
        dp[1] = new long[dp[0].Length];
        dp[0][A << 4 | G << 2 | C] = 0;
        dp[0][A << 4 | C << 2 | G] = 0;
        dp[0][G << 4 | A << 2 | C] = 0;
        for (int i = 3; i < n; i++)
        {
            for (int s = 0; s < dp[(i + 1) % 2].Length; s++)
            {
                int c3 = s >> 4 & 3;
                int c2 = s >> 2 & 3;
                int c1 = s >> 0 & 3;
                var skipC = c2 == A && c1 == G || c2 == G && c1 == A || c3 == A && (c2 == G || c1 == G);
                var skipG = c2 == A && c1 == C;
                var k = dp[(i + 1) % 2][s];
                dp[(i + 1) % 2][s] = 0;
                for (int c0 = A; c0 < 4; c0++)
                {
                    if (c0 == C && skipC || c0 == G && skipG)
                    {
                        continue;
                    }

                    dp[i % 2][c2 << 4 | c1 << 2 | c0] += k;
                    dp[i % 2][c2 << 4 | c1 << 2 | c0] %= Mod;
                }
            }
        }

        var sum = dp[(n + 1) % 2].Aggregate((x, y) => (x + y) % Mod);
        Console.WriteLine(sum);
    }
}