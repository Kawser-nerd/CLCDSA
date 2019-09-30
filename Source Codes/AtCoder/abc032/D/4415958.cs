using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;


class P
{
    static void Main()
    {
        var nw = Console.ReadLine().Split().Select(int.Parse).ToList();
        var vws = Enumerable.Repeat(0, nw[0]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToList()).ToList();
        Solve1(nw, vws);
        Console.WriteLine(vws.Min(x => x[0]) <= 1000 ? Solve2(nw, vws) : vws.Min(x => x[1]) <= 1000 ? Solve3(nw, vws) : Solve1(nw, vws));
    }

    static long Solve1(List<int> nw, List<List<int>> vws)
    {
        //????????????????
        Dictionary<long, long> firstHalf = new Dictionary<long, long>();
        int firstHalfCount = nw[0] / 2;
        for (int i = 0; i < (1 << firstHalfCount); i++)
        {
            long weight = 0;
            long value = 0;
            for (int j = 0; j < firstHalfCount; j++)
            {
                if (((i >> j) & 1) == 1)
                {
                    value += vws[j][0];
                    weight += vws[j][1];
                }
            }
            if (!firstHalf.ContainsKey(weight)) firstHalf.Add(weight, 0);
            firstHalf[weight] = Max(firstHalf[weight], value);
        }

        Dictionary<long, long> secondHalf = new Dictionary<long, long>();
        int secondHalfCount = nw[0] - nw[0] / 2;
        for (int i = 0; i < (1 << (secondHalfCount)); i++)
        {
            long weight = 0;
            long value = 0;
            for (int j = 0; j < secondHalfCount; j++)
            {
                if (((i >> j) & 1) == 1)
                {
                    value += vws[firstHalfCount + j][0];
                    weight += vws[firstHalfCount + j][1];
                }
            }
            if (!secondHalf.ContainsKey(weight)) secondHalf.Add(weight, 0);
            secondHalf[weight] = Max(secondHalf[weight], value);
        }

        //???????
        var fArray = firstHalf.OrderBy(x => x.Key).ToArray();
        var sArray = secondHalf.OrderBy(x => x.Key).ToList();
        int fptr = 0;
        int sptr;
        long fmax = 0;
        long max = 0;

        for (sptr = sArray.FindLastIndex(x => x.Key <= nw[1]); sptr >= 0; sptr--)
        {
            while (fptr < fArray.Length && fArray[fptr].Key + sArray[sptr].Key <= nw[1])
            {
                fmax = Max(fmax, fArray[fptr].Value);
                fptr++;
            }
            max = Max(max, fmax + sArray[sptr].Value);
        }
        return max;
    }

    static long Solve2(List<int> nw, List<List<int>> vws)
    {
        //????????????????
        long[] valueDP = Enumerable.Repeat(long.MaxValue / 2, 200001).ToArray();
        valueDP[0] = 0;
        foreach (var item in vws)
        {
            long[] nextDP = valueDP.ToArray();
            for (int i = 0; i < valueDP.Length; i++)
            {
                if (i + item[0] < valueDP.Length) nextDP[i + item[0]] = Min(nextDP[i + item[0]], valueDP[i] + item[1]);
            }
            valueDP = nextDP;
        }
        long res = valueDP.Select((x, y) => new Tuple<long, int>(x, y)).Where(x => x.Item1 <= nw[1]).Max(x => x.Item2);
        return res;
    }

    static long Solve3(List<int> nw, List<List<int>> vws)
    {
        //????????????????
        long[] weightDP = Enumerable.Repeat(long.MinValue / 2, 200001).ToArray();
        weightDP[0] = 0;
        foreach (var item in vws)
        {
            long[] nextDP = weightDP.ToArray();
            for (int i = 0; i < weightDP.Length; i++)
            {
                if (i + item[1] < weightDP.Length) nextDP[i + item[1]] = Max(nextDP[i + item[1]], weightDP[i] + item[0]);
            }
            weightDP = nextDP;
        }
        long res = weightDP.Where((_, index) => index <= nw[1]).Max();
        return res;
    }
}