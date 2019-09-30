using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace prog
{
    class Source
    {
        static void Main()
        {
            int N = int.Parse(Console.ReadLine());
            int[] dp = new int[100010];
            dp[0] = 0;
            int x = 1;
            for (int i = 1; i <= N; i++)
            {
                dp[i] = dp[i - 1] + 1;
                for (int j = 1; j < 10; j++)
                {
                    x = (int)Math.Pow(6, j);
                    if (x > i) break;
                    dp[i] = Math.Min(dp[i], dp[i - x] + 1);
                }
                for (int j = 1; j < 10; j++)
                {
                    x = (int)Math.Pow(9, j);
                    if (x > i) break;
                    dp[i] = Math.Min(dp[i], dp[i - x] + 1);
                }
            }
            Console.WriteLine(dp[N]);
        }
    }
}