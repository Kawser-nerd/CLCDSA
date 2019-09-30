using System;
using System.Collections.Generic;
using System.Linq;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        long k = 0;
        while(a.Any(v => v >= n))
        {
            for(int i = 0; i < n;i++ )
            {
                if (a[i] >= n)
                {
                    var t = a[i] / n;
                    a[i] %= n;
                    for (int j = 0; j < n; j++)
                    {
                        if (i != j)
                        {
                            a[j] += t;
                        }
                    }
                    k += t;
                }
            }
        }

        Console.WriteLine(k);
        return;
    }
}