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
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string[] st = Console.ReadLine().Split(' ');
            int R = int.Parse(st[0]);
            int K = int.Parse(st[1]);
            int n = int.Parse(st[2]);
            string[] st2 = Console.ReadLine().Split(' ');
            long[] memo = new long[n];
            long[] loop = new long[n];
            long[] loopcount = new long[n];
            long sum = 0;
            long res = 0;
            long j;
            for (j = 0; j < n; j++) sum += memo[j] = long.Parse(st2[j]);
            int k = 0;
            long nowcount = 0;
            int pre = 0;
            bool flag = true;
            for (j = 1; j <= R; j++)
            {
                long nowsum = K;
                for (; ; k++)
                {
                    if (k == n)
                    {
                        k = 0; nowcount += 1;
                    }
                    if (memo[k] <= nowsum && (k != pre || nowsum == K))
                    {
                        nowsum -= memo[k];
                    }
                    else
                    {
                        if (flag)
                        {
                            if (loop[k] != 0)
                            {
                                flag = false;
                                long plus = j - loop[k];
                                long plusloop = nowcount - loopcount[k];
                                long mul = (R - j) / plus;
                                nowcount += mul * plusloop;
                                j += plus * mul;
                                while (j > R)
                                {
                                    j -= plus;
                                    nowcount -= plusloop;
                                }
                            }
                            else
                            {
                                loop[k] = j;
                                loopcount[k] = nowcount;
                            }
                        }
                        pre = k;
                        break;
                    }
                }
            }
            res += nowcount * sum;
            for (k -= 1; k >= 0; k--)
            {
                res += memo[k];
            }
            Console.WriteLine("Case #" + (i + 1) + ": " + res);
        }
        return 0;
    }
}