using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        int[] dp = Enumerable.Range(0, n + 1).Select(x => int.MaxValue).ToArray();
        dp[n] = 0;
        foreach(int i in Enumerable.Range(0, 3)
            .Select(x => int.Parse(Console.ReadLine()))
            .Where(x => x >= 0 && x <= n))
            dp[i] = int.MinValue;
        foreach(int i in Enumerable.Range(1, n)
            .Where(x => dp[x] >= 0)
            .Reverse())
        {
            if(dp[i] != int.MaxValue)
                foreach(int j in Enumerable.Range(1, 3))
                {
                    if(i - j < 0)
                        break;
                    dp[i - j] = Math.Min(dp[i - j], dp[i] + 1);
                }
        }
        //Console.WriteLine(string.Join(",", dp));
        Console.WriteLine(dp[0] < 101 ? "YES" : "NO");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}