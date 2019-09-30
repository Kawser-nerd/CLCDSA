using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

class AtCoder
{
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        long a = int.Parse(inputs[1]);
        long b = int.Parse(inputs[2]);
        var array = Console.ReadLine().Split().Select(int.Parse).ToArray();
        long[] dp = 
            Enumerable.Repeat((long)int.MaxValue, n + 1).ToArray();
        dp[0] = 0;
        foreach(int num in array)
        {
            dp[num] = dp.Take(num).Min();
            foreach(int i in Enumerable.Range(0, num))
            {
                dp[i] += a;
            }
            foreach(int i in Enumerable.Range(0, n + 1).Skip(num + 1))
            {
                dp[i] += b;
            }
            //System.Console.WriteLine(string.Join(" ", dp));
        }
        System.Console.WriteLine(dp.Min());
    }
    static void Main()
    {
        var ac = new AtCoder();
        ac.Slove();
    }
}