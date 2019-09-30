using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        //A*(A-1)*…*(B+1) ??????
        Dictionary<int, int> factorCounts = new Dictionary<int, int>();
        var ab = Console.ReadLine().Split().Select(int.Parse).ToList();
        for (int i = ab[0]; i > ab[1]; i--)
        {
            foreach (var factor in Factors(i))
            {
                if (!factorCounts.ContainsKey(factor)) factorCounts.Add(factor, 0);
                factorCounts[factor]++;
            }
        }
        long res = 1;
        foreach (var kv in factorCounts)
        {
            res *= kv.Value + 1;
            res %= 1000000007;
        }
        Console.WriteLine(res);
    }

    static int[] Factors(int n)
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