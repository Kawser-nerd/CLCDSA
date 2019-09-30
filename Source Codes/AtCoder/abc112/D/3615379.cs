using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;
using static System.Math;
using System.Numerics;

class Program
{
    static void Main(string[] args)
    {
        label:
        var sp = ReadLine().Split();
        int n = Parse(sp[0]);
        int m = Parse(sp[1]);
        int max = m / n;
        WriteLine(Yakusuu(m).Where(i => i <= max).Max());
        //goto label;
    }

    static List<int> Yakusuu(int num)
    {
        if (num == 1) return new List<int>() { 1 };
        int sq = (int)Ceiling(Sqrt(num));
        int sqsq = (int)Ceiling(Sqrt(sq));
        var gousei = new bool[sq + 1];
        for(int i = 2; i <= sqsq; ++i)
        {
            if (gousei[i]) continue;
            for(int j = i * 2; j < gousei.Length; j += i)
            {
                gousei[j] = true;
            }
        }
        var insuu = new List<List<int>>();
        for(int i = 2; i < gousei.Length; ++i)
        {
            if (!gousei[i])
            {
                if (num % i == 0)
                {
                    var list = new List<int>() { 1, i };
                    insuu.Add(list);
                    int j = i * i;
                    for(; num % j == 0; j *= i)
                    {
                        list.Add(j);
                    }
                    num /= (j / i);
                }
                if (num < i) break;
            }
        }
        if (1 < num)
        {
            insuu.Add(new List<int>() { 1, num });
        }
        var result = Get(insuu, 0).ToList();
        return result;
    }
    static IEnumerable<int> Get(List<List<int>> lislis, int i)
    {
        foreach (int n in lislis[i])
        {
            if (i == lislis.Count - 1)
            {
                yield return n;
            }
            else
            {
                foreach (var next in Get(lislis, i + 1))
                {
                    yield return n * next;
                }
            }
        }
    }
}