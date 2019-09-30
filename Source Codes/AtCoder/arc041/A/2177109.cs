using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int k = int.Parse(Console.ReadLine());
        Console.WriteLine(a.Sum() - Math.Abs(a[1] - k));
    }
}