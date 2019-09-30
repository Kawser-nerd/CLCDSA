using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace problem
{
    class Program
    {
        const int MOD = 1000000007;
        void slove()
        {
            var inputs = Console.ReadLine().Split();
            int height = int.Parse(inputs[0]);
            int width = int.Parse(inputs[1]);
            int[] field =
                Enumerable.Range(0, height)
                .SelectMany(x => Console.ReadLine().Split())
                .Select(int.Parse)
                .ToArray();
            var order =
                field.Select((x, i) => i)
                .OrderBy(i => field[i]);
            long[] dp = new long[field.Length];
            foreach(int i in order)
            {
                dp[i]++;
                //System.Console.WriteLine($"{i} {dp[i]}");
                if(dp[i] > MOD)
                    dp[i] %= MOD;
                if(i % width > 0 && field[i - 1] > field[i])
                    dp[i - 1] += dp[i];
                if(i % width < width - 1 && field[i + 1] > field[i])
                    dp[i + 1] += dp[i];
                if(i / width > 0 && field[i - width] > field[i])
                    dp[i - width] += dp[i];
                if(i / width < height - 1 && field[i + width] > field[i])
                    dp[i + width] += dp[i];
            }
            System.Console.WriteLine(dp.Sum() % MOD);
        }
        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader("input.txt"));
            new Program().slove();
        }
    }
}