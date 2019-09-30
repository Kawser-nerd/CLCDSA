using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.IO;
using System.Text;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        long n = long.Parse(Console.ReadLine());
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long[] da = new long[n];

        long ans = 9223372036854775800;
            
        da[0] = a[0];
        for(long i = 1; i < n; i++)
        {
            da[i] = a[i] + da[i - 1];
        }

        for (long i = 0; i < n - 1; i++)
        {
            long x = da[i];
            long y = da[n - 1] - da[i];
            ans = Math.Min(ans, Math.Abs(x - y));
        }

        Console.WriteLine(ans);
    }
}