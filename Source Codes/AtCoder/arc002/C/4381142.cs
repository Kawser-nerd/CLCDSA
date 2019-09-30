using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] s = Console.ReadLine().Select(x => x == 'A' ? 0 : x == 'B' ? 1 : x == 'X' ? 2 : 3).Concat(Enumerable.Repeat(-1, 2)).ToArray();
        int min = int.MaxValue;
        for (int i = 0; i < 256; i++)
        {
            int config1_1 = (i >> 6) & 3;
            int config1_2 = (i >> 4) & 3;
            int config2_1 = (i >> 2) & 3;
            int config2_2 = i & 3;
            int[] dp = Enumerable.Repeat(int.MaxValue / 2, n + 1).ToArray();
            dp[0] = 0;
            for (int j = 0; j < n - 1; j++)
            {
                dp[j + 1] = Min(dp[j + 1], dp[j] + 1);
                if ((s[j] == config1_1 && s[j + 1] == config1_2) || (s[j] == config2_1 && s[j + 1] == config2_2)) dp[j + 2] = Min(dp[j + 2], dp[j] + 1);
            }
            min = Min(min, Min(dp[n], dp[n - 1] + 1));
        }
        Console.WriteLine(min);
    }
}