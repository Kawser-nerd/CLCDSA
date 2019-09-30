using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var ab = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var a = ab[0];
        var b = ab[1];

        Console.WriteLine((a & b & 1) == 1 ? "Yes" : "No");
    }
}