using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int count = a[0];
        int k = a[1];
        int last = 0;
        int p = 0;
        int res = 0;
        for (int i = 0; i < count; i++)
        {
            int n = int.Parse(Console.ReadLine());
            if (last >= n) p = k;
            last = n;
            p--;
            if (i >= k - 1 && p <= 0) res++;
        }
        Console.WriteLine(res);
    }
}