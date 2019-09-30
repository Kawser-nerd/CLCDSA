using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;

            int power = 6;
            while (power <= i)
            {
                dp[i] = Math.Min(dp[i], dp[i - power] + 1);
                power *= 6;
            }

            power = 9;
            while (power <= i)
            {
                dp[i] = Math.Min(dp[i], dp[i - power] + 1);
                power *= 9;
            }
        }

        Console.WriteLine(dp[n]);
    }
}