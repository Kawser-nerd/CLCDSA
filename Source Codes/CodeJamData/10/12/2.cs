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
        int i, j, k, l, m;
        for (i = 0; i < Loop; i++)
        {
            string[] st = Console.ReadLine().Split(' ');
            int D, I, M, N;
            D = int.Parse(st[0]);
            I = int.Parse(st[1]);
            M = int.Parse(st[2]);
            N = int.Parse(st[3]);
            st = Console.ReadLine().Split(' ');
            int[] a = new int[st.Length];
            for (j = 0; j < N; j++)
            {
                a[j] = int.Parse(st[j]);
            }
            int len = a.Length;
            long[,] res = new long[len + 1, 256];
            for (l = 0; l < 256; l++) res[0, l] = 0;
            for (j = 1; j <= len; j++) for (l = 0; l < 256; l++) res[j, l] = long.MaxValue >> 1;
            for (j = 1; j <= len; j++)
            {
                for (l = 0; l < 256; l++)
                {
                    for (k = 0; k < j; k++)
                    {
                        for (m = 0; m < 256; m++)
                        {
                            long now = res[k, m] + (j - k - 1) * (long)D;
                            if (M != 0) now += Math.Max(0, (Math.Abs(l - m) - 1) / M) * I + Math.Abs(a[j - 1] - l);
                            else
                            {
                                if (l != m) now += long.MaxValue >> 2;
                                else now += Math.Abs(a[j - 1] - l);
                            }
                            
                            res[j, l] = Math.Min(res[j, l], now);
                        }
                    }
                }
            }
            long result = long.MaxValue >> 1;
            for (k = 1; k <= len; k++)
            {
                for (m = 0; m < 256; m++)
                {
                    long now = res[k, m] + (len - k) * (long)D;
                    result = Math.Min(result, now);
                }
            }
            Console.WriteLine("Case #{0}: {1}", i + 1, result);

        }
        return 0;
    }

    bool ok(int n, int a, int b)
    {
        return a >= 0 && b >= 0 && a < n && b < n;
    }
}