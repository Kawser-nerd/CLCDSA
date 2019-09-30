using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        var nk = Console.ReadLine().Split().Select(int.Parse).ToList();
        var a = Console.ReadLine().Split().Select(long.Parse).ToList();
        long currentCost = a.Take(nk[1]).Where(x => x < 0).Sum();
        long costMax = currentCost;

        long currentDump = a.Take(nk[1]).Where(x => x > 0).Sum();
        long dumpMin = currentDump;
        for (int i = nk[1]; i < nk[0]; i++)
        {
            if (a[i - nk[1]] < 0) currentCost -= a[i - nk[1]];
            else currentDump -= a[i - nk[1]];

            if (a[i] < 0) currentCost += a[i];
            else currentDump += a[i];

            costMax = Max(costMax, currentCost);
            dumpMin = Min(dumpMin, currentDump);
        }
        long greedyScore = a.Where(x => x >= 0).Sum();
        Console.WriteLine(Max(greedyScore + costMax, greedyScore - dumpMin));
    }
}