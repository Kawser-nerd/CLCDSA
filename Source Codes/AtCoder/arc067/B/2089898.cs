using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        long[] nab = Console.ReadLine().Split().Select(long.Parse).Distinct().ToArray();
        long[] a = Console.ReadLine().Split().Select(long.Parse).Distinct().ToArray();
        long res = 0;
        long pos = a[0];
        for (int i = 1; i < a.Length; i++)
        {
            res += Math.Min((a[i] - pos) * nab[1], nab[2]);
            pos = a[i];
        }
        Console.WriteLine(res);
    }
}