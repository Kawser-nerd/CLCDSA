using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var nm = Console.ReadLine().Split()
            .Select(x => int.Parse(x))
            .ToArray();
        var n = nm[0];
        var m = nm[1];
        var adlQuery =
            from i in Enumerable.Range(1, m)
            let vu = Console.ReadLine().Split()
                .Select(x => int.Parse(x) - 1)
                .OrderBy(x => x)
                .ToArray()
            select vu into es
            from e in new[] { es, es.Reverse() }
            let v = e.First()
            let u = e.Last()
            orderby u ascending
            group u by v into g
            select g;
        var adl = Enumerable.Range(0, n)
            .GroupJoin(adlQuery, i => i, adj => adj.Key, (_, inner) => inner.SelectMany(adj => adj))
            .DefaultIfEmpty()
            .Select(x => x.ToArray())
            .ToArray();
        var q = int.Parse(Console.ReadLine());
        var queriesQuery =
            from i in Enumerable.Range(1, q)
            let x = Console.ReadLine().Split()
                .Select(x => int.Parse(x))
                .ToArray()
            select new { i, v = x[0] - 1, d = x[1], c = x[2] };
        var queries = queriesQuery.ToArray();

        var dp = Enumerable.Range(1, 3).Select(_ => new int[n]).ToArray();
        foreach (var query in queries.Reverse())
        {
            var vs = new[] { query.v };
            for (int d = query.d; d > -1; --d)
            {
                var bfs = new List<int[]>();
                foreach (var v in vs)
                {
                    if (dp[0][v] <= query.i)
                    {
                        dp[0][v] = query.i;
                        dp[2][v] = query.c;
                    }

                    if (dp[1][v] < d)
                    {
                        dp[1][v] = d;
                        bfs.Add(adl[v]);
                    }
                }
                vs = bfs.SelectMany(x => x).Distinct().ToArray();
            }
        }

        foreach (var v in dp[2])
        {
            Console.WriteLine(v);
        }
    }
}