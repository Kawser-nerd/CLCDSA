using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] count = new int[n + 10];
        long res = 1;
        for (int i = 1; i <= n; i++)
        {
            var factor = factors(i);
            foreach (var item in factor)
            {
                count[item]++;
            }
        }
        foreach (var item in count)
        {
            res *= (item + 1);
            res %= 1000000007;
        }
        Console.WriteLine(res);
    }

    static int[] factors(int n)
    {
        int i = 2;
        List<int> res = new List<int>();
        while (i * i <= n)
        {
            if (n % i == 0)
            {
                res.Add(i);
                n /= i;
            }
            else
            {
                i++;
            }
        }
        if (n != 1) res.Add(n);
        return res.ToArray();
    }
}