using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] s = Enumerable.Repeat(0, nab[0]).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        double ave = s.Average();
        double diff = s.Max() - s.Min();
        double p;
        if (diff == 0)
        {
            if (nab[2] == 0)
            {
                p = 0;
            }
            else
            {
                Console.WriteLine(-1);
                return;
            }
        }
        else
        {
            p = nab[2] / diff;
        }
        double q = nab[1] - ave * p;
        Console.WriteLine($"{p} {q}");
    }
}