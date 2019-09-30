using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] NST = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int w = int.Parse(Console.ReadLine());
        int res = 0;
        if (NST[1] <= w && w <= NST[2]) res++;
        for (int i = 1; i < NST[0]; i++)
        {
            w += int.Parse(Console.ReadLine());
            if (NST[1] <= w && w <= NST[2]) res++;
        }
        Console.WriteLine(res);
    }
}