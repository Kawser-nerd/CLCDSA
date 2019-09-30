using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        long res = 0;
        List<long[]> abs = new List<long[]>();
        for (int i = 0; i < n; i++)
        {
            abs.Add(Console.ReadLine().Split().Select(long.Parse).ToArray());
        }
        abs.Reverse();
        foreach (var ab in abs)
        {
            long amari = (ab[0] + res) % ab[1];
            res += (ab[1] - amari) % ab[1];
        }
        Console.WriteLine(res);
    }
}