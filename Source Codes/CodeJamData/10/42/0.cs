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
            string[] st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int N = int.Parse(st[0]);
            int i, j,k;
            int len = 1<<N;
            int[] num = new int[len];
            st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (i = 0; i < (1<<N); i++)
            {
                num[i] = int.Parse(st[i]);
            }
            long[,] dp = new long[len, N + 1];
            long longm = long.MaxValue >> 3;

            for (i = 0; i < len; i++)
            {
                for (j = 0; j <= N; j++)
                {
                    dp[i, j] = longm;
                }
            }
            for (i = 0; i < len; i++)
            {
                int needs = Math.Max(0, N - num[i]);
                dp[i, needs] = 0;
            }

            while (len != 1)
            {
                st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int nextlen = len / 2;
                long[,] nextdp = new long[nextlen, N + 1];
                long[] price = new long[nextlen];
                for (i = 0; i < nextlen; i++) price[i] = long.Parse(st[i]);
                for (i = 0; i < nextlen; i++)
                {
                    for (j = 0; j <= N; j++)
                    {
                        nextdp[i, j] = longm;
                    }
                }
                for (i = 0; i < nextlen; i++)
                {
                    for (j = 0; j <= N; j++)
                    {
                        for (k = 0; k <= N; k++)
                        {
                            int needs = Math.Max(j, k);
                            nextdp[i, needs] = Math.Min(nextdp[i, needs], dp[i * 2, j] + dp[i * 2 + 1, k]);
                            if (needs != 0)
                            {
                                nextdp[i, needs - 1] = Math.Min(nextdp[i, needs - 1], dp[i * 2, j] + dp[i * 2 + 1, k] + price[i]);
                            }
                        }
                    }
                }


                dp = (long[,])nextdp.Clone();
                len /= 2;
            }
            long res = dp[0, 0];
            Console.WriteLine("Case #{0}: {1}", ll + 1, res);
        }
        return 0;
    }

}