using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        double degs = (a[0] % 12) * 30 + a[1] * 0.5;
        double degl = a[1] * 6;
        double diff = Math.Abs(degl - degs);
        diff = Math.Min(360 - diff, diff);
        Console.WriteLine(diff);
    }
}