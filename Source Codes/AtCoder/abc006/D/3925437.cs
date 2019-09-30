using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public Program()
    {
        int n = int.Parse(Console.ReadLine());
        int[] cards =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine())
            .Select(int.Parse)
            .ToArray();
        int[] dp = new int [n + 1].Select(x => int.MaxValue).ToArray();
        dp[0] = 0;
        dp[1] = cards[0];
        foreach(int i in Enumerable.Range(1, n - 1))
        {
            int k = 1;
            for(int start = 0, end = n, mid = n / 2; start <= end; mid = (start + end) / 2)
            {
                if(dp[mid] > cards[i])
                {
                    end = mid - 1;
                }
                else
                {
                    k = mid;
                    start = mid + 1;
                }                
            }
            dp[k + 1] = Math.Min(dp[k + 1], cards[i]);
        }
        Console.WriteLine(n - dp.Count(x => x != int.MaxValue) + 1);
        //Console.WriteLine(string.Join(",", dp));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}