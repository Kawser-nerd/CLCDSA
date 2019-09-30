using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long res = Math.Min(a[0], a[1] / 2);
        a[1] -= res * 2;
        res += a[1] / 4;
        Console.WriteLine(res);
    }
}