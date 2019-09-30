using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        int h = int.Parse(inputs[0]);
        int w = int.Parse(inputs[1]);
        int k = int.Parse(inputs[2]) - 1;
        int[] pattern = new int[w - 1];
        int maxPattern = 0;
        foreach(int i in Enumerable.Range(0, (int)Math.Pow(2, w - 1)))
        {
            if(w > 1 && Enumerable.Range(0, w - 1)
                .Any(x => (((i >> x) & (i >> (x + 1))) & 1) == 1))
                continue;
            //Console.WriteLine(Convert.ToString(i, 2).PadLeft(w));
            foreach(int j in Enumerable.Range(0, w - 1))
            {
                if(((i >> j) & 1) == 1)
                pattern[j]++;
            }
            maxPattern++;
        }
        //Console.WriteLine(string.Join(",", pattern));
        //Console.WriteLine(maxPattern);
        
        long[][] dp = Enumerable.Range(0, h + 1).Select(x => new long[w]).ToArray();
        dp[0][0] = 1;
        foreach(int y in Enumerable.Range(0, h))
            foreach(int x in Enumerable.Range(0, w))
            {
                if(dp[y][x] >= 1000000007)
                    dp[y][x] %= 1000000007;
                int p = maxPattern;
                if(x != 0)
                {
                    p -= pattern[x - 1];
                    dp[y + 1][x - 1] += dp[y][x] * pattern[x - 1];
                }
                if(x != w - 1)
                {
                    p -= pattern[x];
                    dp[y + 1][x + 1] += dp[y][x] * pattern[x];    
                }
                dp[y + 1][x] += dp[y][x] * p;
                    
            }
        Console.WriteLine(dp[h][k] % 1000000007);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}