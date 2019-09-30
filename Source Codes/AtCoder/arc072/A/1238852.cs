using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var xs = Console.ReadLine().Split()
            .Select(x => long.Parse(x))
            .ToArray();

        var adjust = new long[2];
        var sum = new long[2];
        var sign = new[] { Math.Sign(1), Math.Sign(-1) };
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                var t = sum[j] + xs[i];
                var k = t * sign[j];
                if (k >= 0)
                {
                    adjust[j] += k + 1;
                    sum[j] = -1 * sign[j];
                }
                else
                {
                    sum[j] = t;
                }
                sign[j] = Math.Sign(sum[j]);
            }
        }
        
        Console.WriteLine(adjust.Min());
    }
}