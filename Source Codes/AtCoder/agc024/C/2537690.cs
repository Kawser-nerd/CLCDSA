using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Enumerable.Repeat(0, n).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        //???0
        //??????????

        //??????????Ni-1????????????

        //1 1???????????????????
        //a[i-1]+1==a[i]?????????+1
        
        //????????????
        //????????????????????-> ?? (13WA->13WA)
        //????????? ?????????????????????
        long res = 0;
        for (int i = a.Length - 1; i >= 1; i--)
        {
            if (a[i] - a[i - 1] > 1)
            {
                res = -1;
                goto end;
            }

            if (a[i - 1] + 1 == a[i]) res++;
            else res += a[i];
        }
        end:;
        if (a[0] != 0) res = -1;
        Console.WriteLine(res);
    }
}