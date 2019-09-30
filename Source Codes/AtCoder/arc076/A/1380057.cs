using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    const long Mod = (long)(1e9 + 7);
    
    public static void Main()
    {
        var nm = Console.ReadLine().Split()
            .Select(x => long.Parse(x))
            .OrderBy(x => x)
            .ToArray();

        var d = nm[1] - nm[0];
        if (d > 1)
        {
            Console.WriteLine(0);
            return;
        }

        var t = Frac(1, nm[0]);
        t *= t * Frac(nm[0] + 1, d) % Mod;
        t %= Mod;
        t *= 2 - d;
        t %= Mod;
        Console.WriteLine(t);
    }

    static long Frac(long x, long k)
        => k == 0
            ? 1
            : x * Frac(x + 1, k - 1) % Mod;
}