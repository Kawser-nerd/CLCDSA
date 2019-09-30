using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class AtCoder
{
    const int MOD = 1000000007;
    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        var stones =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine())
            .Select(int.Parse)
            .Select(x => x - 1)
            .ToList();
        foreach(int i in Enumerable.Range(0, n).Skip(1).Reverse())
        {
            if(stones[i] == stones[i - 1])
                stones.RemoveAt(i);
        }
        var bef = 
            Enumerable.Range(0, stones.Max() + 1)
            .Select(x => -1).ToArray();
        n = stones.Count;
        int[] dp = new int[stones.Count];
        foreach(int i in Enumerable.Range(0, n).Skip(0))
        {
            if(i != 0)
                dp[i] = dp[i - 1];
            if(bef[stones[i]] != -1)
            {
                dp[i] += dp[bef[stones[i]]] + 1;
            }
            bef[stones[i]] = i;
            if(dp[i] >= MOD)
                dp[i] %= MOD;
        }
        System.Console.WriteLine((dp[n - 1] + 1) % MOD);
    }
    static void Main()
    {
        var ac = new AtCoder();
        ac.Slove();
    }
}