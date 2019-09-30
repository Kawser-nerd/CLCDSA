using System;
using System.Collections.Generic;
using System.Linq;
 
class Solution
{
    static void Main()
    {
        var n = 50;
        long k = long.Parse(Console.ReadLine());
        var plus = k / n;
        var rem = k % n;
        var a = Enumerable.Repeat(n - 1 + plus, n).ToArray();
        for (int t = 0; t < rem; t++)
        {
            var min = a.Min();
            var minIndex = Array.IndexOf(a, min);
            a[minIndex] += n;
            for (int i = 0; i < n; i++)
            {
                if (i != minIndex)
                {
                    a[i]--;
                }
            }
        }
        Console.WriteLine(n);
        Console.WriteLine(String.Join(" ", a));
    }
}