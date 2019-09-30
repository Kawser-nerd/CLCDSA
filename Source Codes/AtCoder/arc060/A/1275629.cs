using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

public class Magatro
{
    int N, A;
    int[] X;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        A = int.Parse(line[1]);
        X = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    public void Solve()
    {
        Scan();
        int sum = X.Sum();
        long[,,] dp = new long[100, 100, 3000];
        dp[0, 0, 0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k <= sum - X[i]; k++)
                {
                    dp[i + 1, j, k] += dp[i, j, k];
                    dp[i + 1, j + 1, k + X[i]] += dp[i, j, k];
                }
            }
        }
        long ans = 0;
        for (int i = 1; i <= N; i++)
        {
            ans += dp[N, i, i * A];
        }
        Console.WriteLine(ans);
    }
}