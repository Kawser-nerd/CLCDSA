using System;
using System.Collections.Generic;

public class CSharp
{
    public static void Main()
    {
        Kyopuro chokudai = new Kyopuro();
        chokudai.AtCoder();
    }
}

public class Kyopuro
{
    public void AtCoder()
    {
        int p = 1000000000 + 7;
        int n = int.Parse(Console.ReadLine());
        int[] c = new int[n+1];
        List<int>[] list = new List<int>[200010];
        for (int i = 0; i < 200010; i++) list[i] = new List<int>();
        for (int i = 1; i <= n; i++)
        {
            c[i] = int.Parse(Console.ReadLine());
            list[c[i]].Add(i);
        }
        long[] dp = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        long[] ac = new long[200010];
        ac[c[1]] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (c[i - 1] == c[i]) dp[i] = dp[i - 1];
            else
            {
                ac[c[i]] += dp[i - 1];
                ac[c[i]] %= p;
                dp[i] = ac[c[i]];
            }
        }

        Console.WriteLine(dp[n]);
    }
    public static void DebugWL(object x) { System.Diagnostics.Debug.WriteLine(x); }
}