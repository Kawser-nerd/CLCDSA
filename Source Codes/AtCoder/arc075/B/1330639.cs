using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var nab = Console.ReadLine().Split()
            .Select(x => long.Parse(x))
            .ToArray();
        var n = (int)nab[0];
        var a = nab[1];
        var b = nab[2];
        var hs = Enumerable.Range(0, n)
            .Select(_ => long.Parse(Console.ReadLine()))
            .ToArray();

        var c = a - b;
        Func<long, bool> pred = xx => hs
            .Select(x => x - b * xx)
            .Where(x => x > 0)
            .Sum(x => (x - 1) / c + 1)
            <= xx;

        var minBound = 1L;
        var maxBound = (long)Math.Ceiling((double)hs.Max() / b);
        while (minBound != maxBound)
        {
            var t = (maxBound - minBound) / 2 + minBound;
            if (pred(t))
            {
                maxBound = t;
            }
            else
            {
                minBound = t + 1;
            }
        }
        
        Console.WriteLine(minBound);
    }
}