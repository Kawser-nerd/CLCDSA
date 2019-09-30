using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var nk = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();
        var n = nk[0];
        var k = nk[1];
        var ts = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();

        var f = 0L;
        for (int i = 39; i >= 0; i--)
        {
            var d = 1L << i;
            var one = ts.Sum(x => x >> i & 1);
            if (k >= d && one < n - one)
            {
                k -= d;
                f += (n - one) * d;
            }
            else
            {
                f += one * d;
            }
        }
        Console.WriteLine(f);
    }
}