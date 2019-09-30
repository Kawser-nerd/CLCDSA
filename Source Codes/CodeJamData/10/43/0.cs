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

    int[] union;

    public int calc()
    {
        int Loop = int.Parse(Console.ReadLine());
        for (int ll = 0; ll < Loop; ll++)
        {
            string[] st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int N = int.Parse(st[0]);
            int[] maxx = new int[N];
            int[] minx = new int[N];
            int[] maxy = new int[N];
            int[] miny = new int[N];
            int i, j, k;
            union = new int[N];
            for (i = 0; i < N; i++)
            {
                st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                minx[i] = int.Parse(st[0]);
                miny[i] = int.Parse(st[1]);
                maxx[i] = int.Parse(st[2]) + 1;
                maxy[i] = int.Parse(st[3]) + 1;
                union[i] = -1;
            }
            for (i = 0; i < N; i++)
            {
                for (j = i + 1; j < N; j++)
                {
                    if (((long)maxx[i] - minx[j]) * ((long)maxx[j] - minx[i]) < 0) continue;
                    if (((long)maxy[i] - miny[j]) * ((long)maxy[j] - miny[i]) < 0) continue;
                    if (maxx[i] == minx[j] && maxy[i] == miny[j]) continue;
                    if (maxx[j] == minx[i] && maxy[j] == miny[i]) continue;
                    connect(i, j);
                }
            }
            long res = 0;
            for (i = 0; i < N; i++)
            {
                if (union[i] != -1) continue;
                long largex = 0;
                long largey = 0;
                long minsum = int.MaxValue;
                for (j = 0; j < N; j++)
                {
                    if (getnum(j) == i)
                    {
                        largex = Math.Max(largex, maxx[j] - 1);
                        largey = Math.Max(largey, maxy[j] - 1);
                        minsum = Math.Min(minx[j] + miny[j], minsum);
                    }
                }
                res = Math.Max(res, largex + largey - minsum + 1);
            }

            Console.WriteLine("Case #{0}: {1}", ll + 1, res);
        }
        return 0;
    }

    int getnum(int a)
    {
        if (union[a] == -1) return a;
        else return (union[a] = getnum(union[a]));
    }

    void connect(int a, int b)
    {
        if (getnum(a) == getnum(b)) return;
        //Console.WriteLine("connect " + a + " " + b);
        //Console.WriteLine(getnum(a) + " " + getnum(b));
        union[getnum(b)] = getnum(a);
    }

}