using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;

class P
{
    static void Main()
    {
        long n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(long.Parse).ToList();
        var sum = a.Sum();
        var incr = n * (n + 1) / 2;
        if (sum % incr != 0) goto invalid;
        var operationCount = sum / incr;
        var diffs = a.Zip(a.Skip(1), (x, y) => y - x).Concat(Enumerable.Repeat(a.First() - a.Last(), 1)).ToList();
        long totalOperate = 0;
        foreach (var diff in diffs)
        {
            if ((operationCount - diff) < 0 || (operationCount - diff) % n != 0) goto invalid;
            totalOperate += (operationCount - diff) / n;
        }
        if (totalOperate != operationCount) goto invalid;

        Console.WriteLine("YES");
        return;
        invalid:;
        Console.WriteLine("NO");
    }
}