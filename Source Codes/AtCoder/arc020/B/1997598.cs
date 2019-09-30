using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] p = Enumerable.Repeat(0, a[0]).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        int min = int.MaxValue;
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if (i != j)
                {
                    int diff = 0;
                    for (int k = 0; k < p.Length; k++)
                    {
                        if (p[k] != (k % 2 == 0 ? i : j)) diff++;
                    }
                    min = Math.Min(diff, min);
                }
            }
        }
        Console.WriteLine(min * a[1]);
    }
}