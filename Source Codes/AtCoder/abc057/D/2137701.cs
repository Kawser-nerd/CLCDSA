using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        long[] v = Console.ReadLine().Split().Select(long.Parse).OrderByDescending(x => x).ToArray();
        long[] take = v.Take(nab[1]).ToArray();
        Console.WriteLine(take.Average().ToString("G20"));
        long res = 0;
        long last = take.Last();
        if (take.Distinct().Count() != 1)
        {
            res = combination(v.Count(x => x == last), take.Count(x => x == last));
        }
        else
        {
            int lastcount = v.Count(x => x == last);
            for (int i = nab[1]; i <= Math.Min(lastcount, nab[2]); i++)
            {
                res += combination(lastcount, i);
            }
        }
        Console.WriteLine(res);
    }
    static long combination(int n, int r)
    {
        long res = 1;
        for (int i = 1; i <= r; i++)
        {
            res *= (n - i + 1);
            res /= i;
        }
        return res;
    }
}