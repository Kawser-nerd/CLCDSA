using System;
using System.Collections.Generic;
using System.IO;

public class Myon
{
    Myon() { }
    public static int Main()
    {
        return new Myon().calc();
    }

    public int calc()
    {
        int Loop = int.Parse(Console.ReadLine());
        for (int ll = 0; ll < Loop; ll++)
        {
            long len = 100000;
            long[] dp = new long[len];
            string[] st = Console.ReadLine().Split(' ');
            long L = long.Parse(st[0]);
            int N = int.Parse(st[1]);
            long[] ar = new long[N];
            int i,j;
            st = Console.ReadLine().Split(' ');
            for (i = 0; i < N; i++) ar[i] = long.Parse(st[i]);
            for (i = 0; i < len; i++) dp[i] = long.MaxValue >> 1;
            Array.Sort(ar);
            dp[0] = 0;
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < len - ar[i]; j++)
                {
                    dp[j + ar[i]] = Math.Min(dp[j + ar[i]], dp[j] + 1);
                }
            }
            long maxvalue = ar[N - 1];
            long res = 0;
            if (L > len)
            {
                res += L / maxvalue - len / maxvalue + 2;
                L -= res * maxvalue;
            }
            if (dp[L] == (long.MaxValue >> 1))
            {
                Console.WriteLine("Case #{0}: IMPOSSIBLE", ll + 1);
            }
            else
            {
                res += dp[L];
                Console.WriteLine("Case #{0}: {1}", ll + 1, res);
            }
        }
        return 0;
    }

}