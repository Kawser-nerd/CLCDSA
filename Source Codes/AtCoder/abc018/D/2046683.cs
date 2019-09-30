using System.Collections.Generic;
using System.Linq;
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
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var p = int.Parse(line[2]);
        var q = int.Parse(line[3]);
        var r = int.Parse(line[4]);
        var hp = new int[n, m];
        for (int i = 0; i < r; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var x = int.Parse(line[0]) - 1;
            var y = int.Parse(line[1]) - 1;
            var z = int.Parse(line[2]);
            hp[x, y] = z;
        }
        var a = Enumerable.Range(0, n).Comb(p);
        var maxret = 0;
        foreach (var x in a)
        {
            var w = x.ToArray();
            var alist = new List<int>();
            for (int i = 0; i < m; i++)
            {
                var subt = 0;
                foreach (var y in w)
                    subt += hp[y, i];
                alist.Add(subt);
            }
            var ret = alist.OrderByDescending(g => g).Take(q).Sum();
            maxret = Math.Max(maxret, ret);
        }
        Console.WriteLine(maxret);
    }
}