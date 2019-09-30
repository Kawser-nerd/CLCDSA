using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        long n = long.Parse(Console.ReadLine());
        List<long> res = new List<long>();
        for (long i = Math.Max(0, n - 9 * 18); i < n; i++)
        {
            if (fx(i) + i == n) res.Add(i);
        }
        Console.WriteLine(res.Count);
        if(res.Count != 0) Console.WriteLine(string.Join("\n", res));
    }

    static long fx(long i) => i.ToString().Sum(x => x - '0');
}