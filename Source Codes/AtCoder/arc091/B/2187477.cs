using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(Solve(nk));
        /*for (int i = 1; i < 100; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long res = Solve(new int[] { i, j });
                long res2 = Solve2(new int[] { i, j });
                if(res != res2)
                {
                    Console.WriteLine($"{i} {j} {res} {res2}");
                }
            }
        }*/
    }
    static long Solve2(int[] nk)
    {
        long res = 0;
        for (int i = 1; i <= nk[0]; i++)
        {
            for (int j = 1; j <= nk[0]; j++)
            {
                if ((i % j) >= nk[1])
                {
                    res++;
                    //Console.WriteLine($"{i}{j}");
                }
            }
        }
        return res;
    }
    static long Solve(int[] nk)
    {
        //b?k+1???
        //a?b*n+k??
        long res = 0;
        for (int b = nk[1] + 1; b <= nk[0]; b++)
        {
            int diff = b - nk[1];
            //????????
            int add = diff * (nk[0] / b);
            //????????
            if (nk[1] == 0)
            {
                add += Math.Max(0, (nk[0] % b - nk[1]));
            }
            else
            {
                add += Math.Max(0, (nk[0] % b - nk[1] + 1));
            }
            res += add;
        }
        return res;
    }
}