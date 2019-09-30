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

public class P
{
    public int x { get; set; }
    public int y { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var ps = new P[n];
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            ps[i] = new P { x = int.Parse(line[0]), y = int.Parse(line[1]) };
        }
        var a = Enumerable.Range(0, n).Comb(3);
        var count = 0;
        foreach (var x in a)
        {
            var t = x.ToArray();
            if (checkT(ps, t)) count++;
        }
        Console.WriteLine(count);
    }
    public static bool checkT(P[] ps, int[] t)
    {
        var x1 = (long)(ps[t[1]].x - ps[t[0]].x);
        var y1 = (long)(ps[t[1]].y - ps[t[0]].y);
        var x2 = (long)(ps[t[2]].x - ps[t[0]].x);
        var y2 = (long)(ps[t[2]].y - ps[t[0]].y);
        var tr0 = Math.Abs(x1 * y2 - x2 * y1);
        return (tr0 != 0 && tr0 % 2 == 0);
    }
}