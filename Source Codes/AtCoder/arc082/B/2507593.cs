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
        int[] p = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToArray();
        bool isLastSame = false;
        int same = 0;
        int samePair = 0;
        for (int i = 0; i < p.Length; i++)
        {
            if (isLastSame)
            {
                if (i == p[i])
                {
                    same--;
                    samePair++;
                }
                isLastSame = false;
            }
            else
            {
                if (i == p[i])
                {
                    same++;
                    isLastSame = true;
                }
            }
        }
        Console.WriteLine(same + samePair);
    }
}