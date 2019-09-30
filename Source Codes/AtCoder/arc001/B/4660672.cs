using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    { 
        var s=Console.ReadLine().Split(' ');
        int D = Math.Abs(int.Parse(s[0])-int.Parse(s[1]));
        int[] dp = new int[D + 11];
        for (int i = 1; i < dp.Length; i++)
            dp[i] = 100;

        Func<int, int> f = x => ((0 <= x && x < dp.Length) ? dp[x] : 100);
        for (int i = 0; i < dp.Length; i += 10)
            dp[i] = Math.Min(dp[i], Math.Min(f(i - 10), f(i + 10)) + 1);
        for (int i = 0; i < dp.Length; i += 5)
            dp[i] = Math.Min(dp[i], Math.Min(f(i - 5), f(i + 5)) + 1);
        for (int i = 0; i < dp.Length; i += 1)
            dp[i] = Math.Min(dp[i], Math.Min(f(i - 1), f(i + 1)) + 1);
        for (int i = 0; i < dp.Length; i += 1)
            dp[i] = Math.Min(dp[i], Math.Min(f(i - 1), f(i + 1)) + 1);

        Console.WriteLine(dp[D]);
    }
}