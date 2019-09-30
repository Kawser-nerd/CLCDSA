using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var xs = Enumerable.Range(0, n)
            .Select(_ => int.Parse(Console.ReadLine()))
            .ToArray();
        
        var complete = xs.Sum();
        var dp = new int[complete + 1];;
        for (int i = 0; i < n; ++i)
        {
            for (int j = complete; j > xs[i] - 1; --j)
            {
                dp[j] = Math.Max(dp[j], dp[j - xs[i]] + xs[i]);
            }
        }
        
        Console.WriteLine(dp.LastOrDefault(x => x % 10 != 0));
    }
}