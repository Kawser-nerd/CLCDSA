using System.Linq;
using System.Collections.Generic;
using System;

public static class combi
{
    public static IEnumerable<IEnumerable<T>> Comb<T>(this IEnumerable<T> items, int r)
    {
        if (r == 0)
        {
            yield return Enumerable.Empty<T>();
        }
        else
        {
            var i = 1;
            foreach (var x in items)
            {
                var xs = items.Skip(i);
                foreach (var c in Comb(xs, r - 1))
                    yield return c.Before(x);
                i++;
            }
        }
    }
    public static IEnumerable<T> Before<T>(this IEnumerable<T> items, T first)
    {
        yield return first;
        foreach (var i in items)
            yield return i;
    }
}

public class Hello
{
    public const int INF = 999999999;
    public static void Main()
    {
        var d = new Dictionary<int, int>();
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var e = int.Parse(line[1]);
        var dp = new int[n, n];
        var start = new List<int>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) if (i != j) dp[i, j] = INF;
        for (int i = 0; i < e; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var u = int.Parse(line[0]) - 1;
            var v = int.Parse(line[1]) - 1;
            var L = int.Parse(line[2]);
            if (u == 0)
            {
                dp[u, v] = INF;
                dp[v, u] = INF;
                d[v] = L;
                start.Add(v);
            }
            else { dp[u, v] = L; dp[v, u] = L; }
        }
        if (start.Count() <= 1) { Console.WriteLine(-1); goto end; }
        goWarshall(dp);
        var a = start.Comb(2);
        var retlist = new List<int>();
        foreach (var w1 in a)
        {
            var w2 = w1.ToArray();
            var a1 = w2[0]; var a2 = w2[1];
            retlist.Add(d[a1] + d[a2] + dp[a1, a2]);
        }
        Console.WriteLine(retlist.Min() >= INF ? -1 : retlist.Min());
        end:;
    }
    public static void goWarshall(int[,] dp)
    {
        var n = dp.GetLength(0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dp[j, k] = Math.Min(dp[j, k], dp[j, i] + dp[i, k]);
    }
}