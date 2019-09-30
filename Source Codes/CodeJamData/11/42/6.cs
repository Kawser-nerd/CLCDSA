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

    static int MAX = 4000000;
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
                for (j = i + i; j < MAX; j += i)
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
        int i, j, k, l, m;
        int h, w;
        int[] ar = inputarray();
        h = ar[0]; w = ar[1];
        int min = Math.Min(h, w);
        int res = 0;
        int[,] num = new int[h, w];

        for (i = 0; i < h; i++)
        {
            string s = Console.ReadLine();
            for (j = 0; j < w; j++)
            {
                num[i, j] = s[j] - '0';
            }
        }

        for (k = 3; k <= min; k++)
        {
            for (i = 0; i < h - k + 1; i++)
            {
                for (j = 0; j < w - k + 1; j++)
                {
                    int centeri = 2 * i + k - 1;
                    int centerj = 2 * j + k - 1;
                    long sumi = 0;
                    long sumj = 0;
                    for (l = i; l < i + k; l++)
                    {
                        for (m = j; m < j + k; m++)
                        {
                            if ((l == i || l == i + k - 1) && (m == j || m == j + k - 1)) continue;
                            sumi += num[l, m] * (centeri - l * 2);
                            sumj += num[l, m] * (centerj - m * 2);
                        }
                    }
                    //Console.WriteLine(sumi + " " + sumj + " " + i + " " + j + " " + k);
                    if (sumi == 0 && sumj == 0) res = Math.Max(k, res);

                }
            }
        }
        if (res == 0) Console.WriteLine("IMPOSSIBLE");
        else Console.WriteLine(res);
    }
}