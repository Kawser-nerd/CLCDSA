using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var xs = Console.ReadLine().Split()
            .Select(x => Int64.Parse(x))
            .OrderByDescending(x => x)
            .ToArray();
        
        var creature = xs.Skip(1).Sum();
        var numSurvivable = 1;
        for (int i = 1; i < n; ++i)
        {
            if (xs[i - 1] > 2 * creature)
                break;

            creature -= xs[i];
            ++numSurvivable;
        }
        
        Console.WriteLine(numSurvivable.ToString());
    }
}