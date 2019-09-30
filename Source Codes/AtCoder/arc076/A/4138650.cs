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
        long[] nm = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long n = nm[0];
        long m = nm[1];
        long ans = 1;

        if(Math.Abs(n - m) > 1)
        {
            Console.WriteLine(0);
            return;
        }

        if (Math.Abs(n - m) == 0)
        {
            ans *= 2;
        }

        for (long i = n; i >= 1; i--)
        {
            ans *= i;
            ans %= 1000000007;
        }
        for (long i = m; i >= 1; i--)
        {
            ans *= i;
            ans %= 1000000007;
        }
        
        Console.WriteLine(ans);
    }
}