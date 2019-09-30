using System;
using System.Collections.Generic;
using System.Linq;
using static Common;

public static class Common
{

    public static int BinSearchIndex(int v, int[] list)
    {
        v = v + 1;
        if (v > list.Last())
        {
            return list.Length;
        }
        int minRange = 0;
        int maxRange = list.Count() - 1;
        while (minRange != maxRange)
        {
            var center = (minRange + maxRange) / 2;
            if (list[center] < v)
            {
                minRange = center + 1;
            }
            else
            {
                maxRange = center;
            }
        }

        return minRange;
    }
}

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(i => i).ToArray();
        var b = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(i => i).ToArray();
        var c = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(i => i).ToArray();

        long count = 0;
        var bPattern = new long[b.Length + 1];
        bPattern[b.Length] = 0;
        for (int bi = 0; bi < b.Length; bi++)
        {
            var y = b[bi];
            var cIndex = BinSearchIndex(y, c);
            bPattern[bi] = c.Length - cIndex;
        }

        var bSum = new long[b.Length + 1];
        bSum[b.Length] = 0;
        long sum = 0;
        for (int bi = b.Length - 1; bi >= 0; bi--)
        {
            sum += bPattern[bi];
            bSum[bi] = sum;
        }
        foreach (var x in a)
        {
            var bIndex = BinSearchIndex(x, b);
            count += bSum[bIndex];
        }

        Console.WriteLine(count);
    }
}