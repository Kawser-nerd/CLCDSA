using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int res = int.MinValue;
        for (int i = 0; i < a.Length; i++)
        {
            int aokimax = int.MinValue;
            int tkhsmax = int.MinValue;
            for (int j = 0; j < a.Length; j++)
            {
                if(i != j)
                {
                    var t = a.Where((_, x) => Math.Min(i, j) <= x && x <= Math.Max(i, j)).ToArray();
                    int aoki = t.Where((_, index) => index % 2 == 1).Sum();
                    if(aokimax < aoki)
                    {
                        aokimax = aoki;
                        tkhsmax = t.Sum() - aoki;
                    }
                }
            }
            res = Math.Max(res,tkhsmax);
        }
        Console.WriteLine(res);
    }
}