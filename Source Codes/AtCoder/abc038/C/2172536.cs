using System.Collections.Generic;
using System;

public class P
{
    public long L { get; set; }
    public long r { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var ps = new List<P>();
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var pre = a[0]; var L = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= pre && i - 1 > L) { ps.Add(new P { L = L, r = i - 1 }); pre = a[i]; L = i; }
            else if (a[i] <= pre && i - 1 >= L) { pre = a[i]; L = i; }
            else if (a[i] > pre && i == n - 1) ps.Add(new P { L = L, r = n - 1 });
            else pre = a[i];
        }
        Console.WriteLine(getAns(ps) + n);
    }
    public static long getAns (List<P> ps)
    {
        var ret = 0L;
        foreach (var x in ps)
        {
            var w = x.r - x.L;
            ret += w * (w + 1) / 2;
        }
        return ret;
    }
}