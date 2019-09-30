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
            int n, K;
            n = int.Parse(st[0]);
            K = int.Parse(st[1]);
            bool flaga, flagb;
            flaga = flagb = false;
            st = new string[n];
            for (j = 0; j < n; j++) st[j] = Console.ReadLine();
            int[,] memo = new int[n, n];
            for (j = 0; j < n; j++)
            {
                int now = 0;
                for (k = n - 1; k >= 0; k--)
                {
                    if (st[j][k] != '.')
                    {
                        if (st[j][k] == 'R') memo[j, n - 1 - now] = 1;
                        else memo[j, n - 1 - now] = 2;
                        now++;
                    }
                }
            }
            int[] vx = new int[8] { 1, 1, 1, 0, 0, -1, -1, -1 };
            int[] vy = new int[8] { -1, 0, 1, -1, 1, -1, 0, 1 };
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    for (l = 0; l < 8; l++)
                    {
                        int X = j - vx[l];
                        int Y = k - vy[l];
                        if (ok(n, X, Y)) continue;
                        X = j; Y = k;
                        int nowa = 0;
                        int nowb = 0;
                        while (ok(n, X, Y))
                        {
                            //Console.WriteLine(nowa + " " + nowb);
                            if (memo[X, Y] == 1)
                            {
                                nowb = 0; nowa++;
                                if (nowa >= K) flaga = true;
                            }
                            else if (memo[X, Y] == 2)
                            {
                                nowa = 0; nowb++;
                                if (nowb >= K) flagb = true;
                            }
                            else
                            {
                                nowa = nowb = 0;
                            }
                            X = X + vx[l];
                            Y = Y + vy[l];
                        }
                    }
                }
            }

            if (!flaga && !flagb) Console.WriteLine("Case #{0}: Neither", i + 1);
            else if (flaga && flagb) Console.WriteLine("Case #{0}: Both", i + 1);
            else if (flaga && !flagb) Console.WriteLine("Case #{0}: Red", i + 1);
            else if (!flaga && flagb) Console.WriteLine("Case #{0}: Blue", i + 1);

        }
        return 0;
    }

    bool ok(int n, int a, int b)
    {
        return a >= 0 && b >= 0 && a < n && b < n;
    }
}