using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var xy = Console.ReadLine().Split()
            .Select(x => long.Parse(x))
            .ToArray();

        Console.WriteLine(Math.Abs(xy[0] - xy[1]) > 1 ? "Alice" : "Brown");
    }
}