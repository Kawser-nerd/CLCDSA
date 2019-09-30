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
        int w = int.Parse(Console.ReadLine());
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int k = int.Parse(inputs[1]);
        int[][] screenshot =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine()
                .Split().Select(int.Parse)
                .ToArray())
            .Where(x => x[0] <= w)
            .ToArray();
        int[][] dp = Enumerable.Range(0, k)
            .Select(x => new int[w + 1]
            )
            .ToArray();
        foreach(int[] ss in screenshot)
        {
            foreach(int i in Enumerable.Range(0, k).Reverse())
            {
                if(i == 0)
                    dp[i][ss[0]] = Math.Max(ss[1] , dp[i][ss[0]]);
                else
                    foreach(int j in dp[i - 1]
                        .Select((x, index) => index)
                        .Skip(ss[0])
                        .Where(x => dp[i - 1][x - ss[0]] != 0)
                        )
                    {
                        dp[i][j] = Math.Max(dp[i][j], dp[i - 1][j - ss[0]] + ss[1]);
                    }
            }
        }
        //Console.WriteLine(
        //    string.Join("\n", dp.Select(x =>
        //        string.Join(",", x.Where(y => y != int.MaxValue)))));
        int max = 
            dp.Select(x =>
                x.Max())
            .Max();
        Console.WriteLine(max);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}