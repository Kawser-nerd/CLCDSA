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
        int[] ar = inputarray();
        int c = ar[0];
        int d = ar[1];
        int[] pos = new int[c];
        int[] num = new int[c];
        double min = 0;
        double max = 1e15;
        int i, j, k;
        for (i = 0; i < c; i++)
        {
            ar = inputarray();
            pos[i] = ar[0];
            num[i] = ar[1];
        }
        for (k = 0; k < 200; k++)
        {
            double mid = (min + max) / 2;
            double minpos = -1e14;
            for (i = 0; i < c; i++)
            {
                double canleft = pos[i] - mid;
                minpos = Math.Max(canleft, minpos);
                if (Math.Abs(minpos - pos[i]) > mid + 1e-8) break;
                minpos += d * (double)(num[i] - 1);
                if (Math.Abs(minpos - pos[i]) > mid + 1e-8) break;
                minpos += d;
            }
            if (i != c) min = mid;
            else max = mid;
        }
        Console.WriteLine(min);
    }
}