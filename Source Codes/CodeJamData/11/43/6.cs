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

    static int MAX = 3000000;
    int count = 0;
    long[] prime = new long[MAX];
    bool[] p = new bool[MAX];

    void malti()
    {
        long i, j;
        for (i = 2; i < MAX; i++)
        {
            if (!p[i])
            {
                prime[count++] = i;
                for (j = i * i; j < MAX; j += i)
                {
                    p[j] = true;
                }
            }
        }

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
        long N = long.Parse(Console.ReadLine());
        long res = 0;
        if (N != 1) res += 1;
        for (i = 0; prime[i] * prime[i] <= N; i++)
        {
            long temp = prime[i];
            while (prime[i] * temp <= N)
            {
                temp *= prime[i];
                res++;
            }
        }
        Console.WriteLine(res);
    }
}