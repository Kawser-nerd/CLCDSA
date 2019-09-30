using System;
using System.Collections.Generic;

class Myon
{
    int input()
    {
        return int.Parse(Console.ReadLine());
    }

    int[] inputarray()
    {
        string[] s = Console.ReadLine().Split(' ');
        int[] ret = new int[s.Length];
        for (int i = 0; i < s.Length; i++) ret[i] = int.Parse(s[i]);
        return ret;
    }

    Myon() { }
    public static void Main()
    {
        new Myon().malti();
    }

    void malti()
    {
        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            Console.Write("Case #{0}: ", lll);
            calc();
        }
    }

    void calc()
    {
        int i, j;
        int X, S, R, t, N;
        int[] ar = inputarray();
        X = ar[0]; S = ar[1]; R = ar[2]; t = ar[3]; N = ar[4];

        int[] d = new int[N + 1];
        int[] v = new int[N + 1];
        for (i = 0; i < N; i++)
        {
            ar = inputarray();
            d[i] = ar[1] - ar[0];
            v[i] = ar[2];
            X -= d[i];
        }
        d[N] = X;
        v[N] = 0;
        for (i = 0; i <= N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (v[j] > v[j + 1])
                {
                    int temp;
                    temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                    temp = d[j];
                    d[j] = d[j + 1];
                    d[j + 1] = temp;
                }
            }
        }
        double nokori = t;
        double res = 0;
        for (i = 0; i <= N; i++)
        {
            double rv = R + v[i];
            double sv = S + v[i];
            double sp = d[i] / rv;
            if (nokori > sp)
            {
                res += sp;
                nokori -= sp;
            }
            else
            {
                double dd = d[i] - nokori * rv;
                res += nokori;
                nokori = 0;
                res += dd / sv;
            }
        }
        Console.WriteLine(res);
    }
}