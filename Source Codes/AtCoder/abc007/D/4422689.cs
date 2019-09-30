using System;

class Program
{
    static string A;
    static string B;

    static void Main()
    {
        string[] input = Console.ReadLine().Split();
        A = input[0];
        B = input[1];
        long b1 = long.Parse(B) - DP(B);
        long a = long.Parse(A) - 1;
        long a1 = a - DP(a.ToString());
        Console.WriteLine(b1 - a1);
    }

    /* 1??k???OK??????? */
    static long DP(string k)
    {
        int n;
        long[,] dp = new long[k.Length, 2];
        dp[0, 0] = ((n = (int)Char.GetNumericValue(k[0])) >= 9 ? 8 : (n > 4) ? n - 1 : n);
        dp[0, 1] = (n == 4 || n == 9) ? 0 : 1;
        for (int i = 1; i < k.Length; i++)
        {
            dp[i, 0] = dp[i - 1, 0] * 8;
            dp[i, 0] += dp[i - 1, 1] *
                ((n = (int)Char.GetNumericValue(k[i])) >= 9 ? 8 : (n > 4) ? n - 1 : n);
            dp[i, 1] = dp[i - 1, 1] * ((n == 4 || n == 9) ? 0 : 1);
        }
        return dp[k.Length - 1, 0] + dp[k.Length - 1, 1] - 1;
    }
}