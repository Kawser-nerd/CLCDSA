using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Enumerable.Repeat("", int.Parse(Console.ReadLine())).Select(_ => int.Parse(Console.ReadLine())).ToArray();
        int asum = a.Sum();
        Console.WriteLine(asum);
        Console.WriteLine(Math.Max(0, a.Max() * 2 - asum));
    }
}