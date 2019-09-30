using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] xy = Console.ReadLine().Split().Select(long.Parse).ToArray();
        Console.WriteLine(Math.Abs(xy[0] - xy[1]) > 1 ? "Alice" : "Brown");
    }
}