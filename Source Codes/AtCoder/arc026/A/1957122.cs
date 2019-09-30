using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        Console.WriteLine(a[2] * Math.Min(a[0], 5) + a[1] * Math.Max(a[0] - 5, 0));
    }
}