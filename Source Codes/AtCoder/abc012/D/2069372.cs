using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var dp = new int[n, n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) if (i != j) dp[i, j] = 999999999;
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]) - 1;
            var b = int.Parse(line[1]) - 1;
            var t = int.Parse(line[2]);
            dp[a, b] = t;
            dp[b, a] = t;
        }
        goWarshall(dp);
        var ret = new int[n];
        for (int i = 0; i < n; i++)
        {
            var tmax = 0;
            for (int j = 0; j < n; j++)
                tmax = Math.Max(tmax, dp[i, j]);
            ret[i] = tmax;
        }
        Console.WriteLine(ret.Min());
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