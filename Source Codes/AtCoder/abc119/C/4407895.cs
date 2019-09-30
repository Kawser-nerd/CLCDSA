using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var nabc = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var n = nabc[0];
        var a = nabc[1];
        var b = nabc[2];
        var c = nabc[3];
        var ls = new int[n];
        for (int i = 0; i < ls.Length; i++)
        {
            ls[i] = int.Parse(Console.ReadLine());
        } 

        var abc = nabc.Skip(1).ToArray();
        var min = Dfs(ls, 0, abc, new int[abc.Length], abc.Sum());
        Console.WriteLine(min);
    }

    static int Dfs(int[] ls, int i, int[] bs, int[] ks, int mp)
    {
        if (i >= ls.Length)
        {
            return ks.Any(x => x == 0) ? int.MaxValue : mp;
        }

        var min = Dfs(ls, i + 1, bs, ks, mp);
        for (int j = 0; j < bs.Length; j++)
        {
            var d = 0 <= bs[j] && bs[j] < ls[i]
                ? bs[j] + bs[j] - ls[i]
                : ls[i] <= bs[j]
                ? ls[i]
                : -ls[i];
            if (ks[j] > 0)
            {
                mp += 10;
            }
            ks[j]++;
            mp -= d;
            bs[j] -= ls[i];
            min = Math.Min(min, Dfs(ls, i + 1, bs, ks, mp));
            bs[j] += ls[i];
            mp += d; 
            ks[j]--;
            if (ks[j] > 0)
            {
                mp -= 10;
            }
        }
        return min;
    }
}