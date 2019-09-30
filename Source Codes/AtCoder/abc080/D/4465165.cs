using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using System.Runtime.CompilerServices;

class P
{
    static void Main()
    {
        var nc = Console.ReadLine().Split().Select(int.Parse).ToList();
        int[] imos = new int[100001];

        var g = Enumerable.Repeat(0, nc[0]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToList()).GroupBy(x => x[2]).Select(x => x.OrderBy(y => y[0]).ToArray()).ToList();
        foreach (var sts in g)
        {
            Dictionary<int, int> endTimes = new Dictionary<int, int>();
            foreach (var st in sts)
            {
                if (endTimes.ContainsKey(st[0]))
                {
                    imos[st[0]]++;
                    endTimes[st[0]]--;
                    if (endTimes[st[0]] == 0) endTimes.Remove(st[0]);
                }
                else imos[st[0] - 1]++;
                imos[st[1]]--;
                if (!endTimes.ContainsKey(st[1])) endTimes.Add(st[1], 0);
                endTimes[st[1]]++;
            }
        }
        int current = 0;
        int res = 0;
        foreach (var item in imos)
        {
            current += item;
            res = Max(res, current);
        }
        Console.WriteLine(res);
    }
}