using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var nx = Console.ReadLine().Split(' ').Select(value => Int64.Parse(value)).ToArray();
        var N = nx[0];
        var x=Console.ReadLine().Split(' ').Select(value => Int64.Parse(value)).ToList();
        x.Add(nx[1]);
        x=x.OrderByDescending(value => value).ToList();
        var list = new List<long>();
        for(int i = 0; i < N; ++i) list.Add(x[i] - x[i + 1]);
        var ans = list[0];
        for (int i = 1; i < list.Count(); ++i)
        {
            var a = ans < list[i] ? list[i] : ans;
            var b = a == ans ? list[i] : ans;
            ans = GetGcd(a, b);
        }
        Console.WriteLine(ans);
    }
    static long GetGcd(long a, long b)
    {
        while (b != 0)
        {
            var r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}