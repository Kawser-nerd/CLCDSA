using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static long CalcEnergy(int order, long distance)
    {
        int coef = 5;
        if (order > 0)
        {
            coef = 2 * order + 3;
        }

        return coef * distance;
    }

    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var N = vals[0];
        var X = vals[1];
        var xs = Console.ReadLine().Split(' ').Select(long.Parse).OrderByDescending(t => t).ToArray();

        var maxK = (int)Math.Ceiling(N / 2.0);
        var accum = new long[N + 1];
        long acc = 0;
        for (int i = 0; i < N; i++)
        {
            acc += xs[i];
            accum[i + 1] = acc;
        }

        decimal min = decimal.MaxValue;
        for (int k = 1; k <= maxK; k++)
        {
            decimal energy = (k + N) * X;
            for (int i = 0; i < N; i += k)
            {
                var j = Math.Min(N, i + k);
                var order = i / k;
                energy += CalcEnergy(order, accum[j] - accum[i]);
            }

            min = Math.Min(energy, min);
        }

        Console.WriteLine(min);
    }
}