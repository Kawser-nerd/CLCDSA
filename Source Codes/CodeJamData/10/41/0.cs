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
            int len = N * 2 - 1;
            int[,] ar = new int[len, len];
            int i, j, k;
            for (i = 0; i < len; i++) for (j = 0; j < len; j++) ar[i, j] = -1;
            for (i = 0; i < len; i++)
            {
                st = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                for (j = 0; j < st.Length; j++)
                {
                    ar[i, j * 2 + Math.Abs(i - (N - 1))] = int.Parse(st[j]);
                }
            }
            int minx = 1000;
            /*
            for (i = 0; i < len; i++)
            {
                for (j = 0; j < len; j++)
                {
                    if (ar[i, j] == -1) Console.Write(' ');
                    else Console.Write(ar[i, j]);
                }
                Console.WriteLine();
            }
            */
            for (k = 0; k < len; k++)
            {
                for (i = 0; i < len; i++)
                {
                    for (j = 0; j < len; j++)
                    {
                        if (ar[i, j] == -1) continue;
                        int next = 2 * k - j;
                        if (next < 0 || next >= len) continue;
                        if (ar[i, next] == -1) continue;
                        if (ar[i, j] != ar[i, next])
                        {
                            break;

                        }
                    }
                    if (j != len) break;
                }
                if (i ==len)
                {
                    //Console.Write(k);
                    minx = Math.Min(minx, Math.Abs(k - (N - 1)));
                }
            }
            int miny = 1000;
            for (k = 0; k < len; k++)
            {
                for (i = 0; i < len; i++)
                {
                    for (j = 0; j < len; j++)
                    {
                        if (ar[i, j] == -1) continue;
                        int next = 2 * k - i;
                        if (next < 0 || next >= len) continue;
                        if (ar[next, j] == -1) continue;
                        if (ar[i, j] != ar[next, j])
                        {
                            break;

                        }
                    }
                    if (j != len) break;
                }
                if (i == len)
                {
                    //Console.Write(k);
                    miny = Math.Min(miny, Math.Abs(k - (N - 1)));
                }
            }
            //Console.WriteLine(minx + " " + miny);
            int res = (N + minx + miny) * (N + minx + miny) - N * N;
            Console.WriteLine("Case #{0}: {1}", ll + 1, res);
        }
        return 0;
    }

}