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
        string[] s = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
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
            Console.WriteLine("Case #{0}: ", lll);
            calc();
        }
    }

    double[] up, lp, dist, sum;

    void calc()
    {
        int i, j;
        int W, U, L, G;
        int[] ar = inputarray();
        W = ar[0]; U = ar[1]; L = ar[2]; G = ar[3];
        up = new double[W + 2];
        lp = new double[W + 2];
        dist = new double[W + 2];
        sum = new double[W + 2];
        ar = inputarray();
        int prex = ar[0];
        double prey = ar[1];
        for (i = 1; i < U; i++)
        {
            ar = inputarray();
            int x = ar[0];
            double y = ar[1];
            for (j = prex; j <= x; j++)
            {
                up[j] = prey + (y - prey) * (j - prex) / (x - prex);
            }
            prex = x;
            prey = y;
        }
        ar = inputarray();
        prex = ar[0];
        prey = ar[1];
        for (i = 1; i < L; i++)
        {
            ar = inputarray();
            int x = ar[0];
            double y = ar[1];
            for (j = prex; j <= x; j++)
            {
                lp[j] = prey + (y - prey) * (j - prex) / (x - prex);
            }
            prex = x;
            prey = y;
        }
        sum[0] = 0;
        for (i = 0; i <= W; i++)
        {
            dist[i] = lp[i] - up[i];
            if (i != 0) sum[i] = sum[i - 1] + (dist[i] + dist[i - 1]) / 2;
        }
        for (i = 1; i < G; i++)
        {
            double need = sum[W] / G * i;
            double low = 0;
            double hi = W;
            for (j = 0; j < 100; j++)
            {
                double mid = (low + hi) / 2;
                if (getsum(mid) < need)
                {
                    low = mid;
                }
                else
                {
                    hi = mid;
                }
            }
            Console.WriteLine(low);
            
        }
        return;
        
    }

    double getsum(double a)
    {
        int t = (int)a;
        double res = sum[t];
        double nextdist = dist[t] + (dist[t + 1] - dist[t]) * (a - t);
        double plus = (a - t) * (nextdist + dist[t]) / 2;
        return res + plus;
    }

}