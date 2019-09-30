using System;
using System.Linq;
using System.Collections.Generic;

namespace AtCoderABC113
{
    class Program
    {
        static int mod = 1000000007;
        public static void Main(string[] args)
        {
            int H, W, K;
            string[] s = Console.ReadLine().Split(' ');
            H = int.Parse(s[0]);
            W = int.Parse(s[1]);
            K = int.Parse(s[2]);
            List<List<int>> dp = new List<List<int>>();
            for (int i = 0; i < H + 1; i++)
            {
                List<int> newlist = new List<int>();
                for (int j = 0; j < W; j++) newlist.Add(0);
                dp.Add(newlist);
            }
            dp[0][0] = 1;

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    for (int k = 0; k < (1 << (W - 1)); k++)
                    {
                        bool flag = true;
                        for (int l = 0; l < W - 2; l++)
                        {
                            if ((((k >> l) & 1) == 1) && (((k >> (l + 1)) & 1) == 1))
                            {
                                flag = false;
                            }
                        }
                        if (flag)
                        {
                            if (j >= 1 && ((k >> (j - 1)) & 1) == 1)
                            {
                                dp[i + 1][j - 1] += dp[i][j];
                                dp[i + 1][j - 1] %= mod;
                            }
                            else if (j <= W - 2&& ((k >> j) & 1) == 1)
                            {
                                dp[i + 1][j + 1] += dp[i][j];
                                dp[i + 1][j + 1] %= mod;
                            }
                            else
                            {
                                dp[i + 1][j] += dp[i][j];
                                dp[i + 1][j] %= mod;
                            }
                        }
                    }
                }
            }
            Console.WriteLine(dp[H][K - 1]);
        }
    }
}