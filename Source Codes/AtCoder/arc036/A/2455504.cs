using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
class P
{
    static void Main()
    {
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] t = Enumerable.Repeat(0, nk[0]).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        for (int i = 2; i < t.Length; i++)
        {
            if(t[i - 2] + t[i - 1] + t[i] < nk[1])
            {
                Console.WriteLine(i + 1);
                return;
            }
        }
        Console.WriteLine(-1);
    }
}