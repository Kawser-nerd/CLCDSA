using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var nm = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var n = nm[0];
        var m = nm[1];
        var lefts = new int[m];
        var rights = new int[m];
        for (int i = 0; i < m; i++)
        {
            var ab = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            lefts[i] = ab[0];
            rights[i] = ab[1];
        }
        
        n += 1;
        var mostNears = new int[n];
        for (int i = 0; i < m; i++)
        {
            mostNears[rights[i]] = Math.Max(mostNears[rights[i]], lefts[i]);
        }

        var count = 0;
        var unbridged = 1;
        for (int i = 1; i < n; i++)
        {
            if (mostNears[i] < unbridged)
            {
                continue;
            }

            count++;
            unbridged = i;
        }

        Console.WriteLine(count);
    }
}