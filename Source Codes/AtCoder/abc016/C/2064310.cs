using System;

public class Hello
{
    private const int INF = 999999999;
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var dp = new int[n, n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) if (i != j) dp[i, j] = INF;
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]) - 1;
            var b = int.Parse(line[1]) - 1;
            dp[a, b] = 1;
            dp[b, a] = 1;
        }
        goWarshall(dp);
        for (int i = 0; i < n; i++)
        {
            var count = 0;
            for (int j = 0; j < n; j++)
                if (dp[i, j] == 2) count++;
            Console.WriteLine(count);
        }
    }
    public static void goWarshall(int[,] dp)
    {
        var n = dp.GetLength(0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dp[j, k] = Math.Min(dp[j, k], dp[j, i] + dp[i, k]);
    }
}