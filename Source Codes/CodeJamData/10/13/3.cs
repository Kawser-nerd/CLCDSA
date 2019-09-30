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
        int i;
        for (i = 0; i < Loop; i++)
        {
            string[] st = Console.ReadLine().Split(' ');
            int a1, a2, b1, b2;
            a1 = int.Parse(st[0]);
            a2 = int.Parse(st[1]);
            b1 = int.Parse(st[2]);
            b2 = int.Parse(st[3]);
            Console.WriteLine("Case #{0}: {1}", i + 1, check(a1, a2, b1, b2));
        }
        return 0;
    }

    long check(int a1, int a2, int b1, int b2)
    {
        int i;
        long res = 0;
        for (i = a1; i <= a2; i++)
        {
            if (b1 <= i / 2)
            {
                res += Math.Min(i / 2, b2) - b1 + 1;

            }
            if (b2 >= i * 2)
            {
                res += b2 - Math.Max(i * 2, b1) + 1;
            }
            if (b1 < i)
            {
                int mi = Math.Max(i / 2 + 1, b1);
                int ma = Math.Min(i - 1, b2);
                if (ma >= mi) res += check(mi, ma, i, i);
            }
            if (b2 > i)
            {
                int mi = Math.Max(i + 1, b1);
                int ma = Math.Min(i * 2 - 1, b2);
                if (ma >= mi) res += ma - mi + 1 - check(i, i, mi - i, ma - i);
            }
        }
        return res;
    }
}