using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, W;
    private int[] v, w;
    private int vMax = -1, wMax = -1;
    const int Max = 200000;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        W = int.Parse(line[1]);
        v = new int[N];
        w = new int[N];
        for (int i = 0; i < N; i++)
        {
            line = Console.ReadLine().Split(' ');
            v[i] = int.Parse(line[0]);
            w[i] = int.Parse(line[1]);
            vMax = Math.Max(vMax, v[i]);
            wMax = Math.Max(wMax, w[i]);
        }
    }

    private long DFS(long vv, long ww, int i)
    {
        if (i == N)
        {
            return vv;
        }
        long result = DFS(vv, ww, i + 1);
        if (ww + w[i] <= W)
        {
            result = Math.Max(result, DFS(vv + v[i], ww + w[i], i + 1));
        }
        return result;
    }

    private void DatasetOne()
    {
        Console.WriteLine(DFS(0, 0, 0));
    }

    private void DatasetTwo()
    {
        var dp = new long[Max + 1];
        for (int i = 0; i <= Max; i++)
        {
            dp[i] = -1;
        }
        dp[0] = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = Max; j >= 0; j--)
            {
                if (dp[j] != -1)
                {
                    dp[j + w[i]] = Math.Max(dp[j + w[i]], dp[j] + v[i]);
                }
            }
        }
        long ans = -1;
        for (int i = 0; i <= Max; i++)
        {
            if (i > W)
            {
                break;
            }
            ans = Math.Max(ans, dp[i]);
        }
        Console.WriteLine(ans);
    }

    private void DatasetThree()
    {
        var dp = new long[Max + 1];
        for (int i = 0; i <= Max; i++)
        {
            dp[i] = long.MaxValue;
        }
        dp[0] = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = Max; j >= 0; j--)
            {
                if (dp[j] != long.MaxValue)
                {
                    dp[j + v[i]] = Math.Min(dp[j + v[i]], dp[j] + w[i]);
                }
            }
        }
        for (int i = Max; i >= 0; i--)
        {
            if (dp[i] <= W && dp[i] != long.MaxValue)
            {
                Console.WriteLine(i);
                return;
            }
        }
    }

    public void Solve()
    {
        Scan();
        if (wMax <= 1000)
        {
            DatasetTwo();
        }
        else if (vMax <= 1000)
        {
            DatasetThree();
        }
        else if (N <= 30)
        {
            DatasetOne();
        }
    }
}