using System.Collections.Generic;
using System.Linq;
using System;

public class P
{
    public int L { get; set; }
    public int r { get; set; }
}

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var te = new List<P>();
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a = int.Parse(line[0]);
            var b = int.Parse(line[1]);
            te.Add(new P { L = a, r = b });
        }
        var ps = te.OrderBy(x => x.r).ToArray();
        var ans = new List<int>();
        ans.Add(ps[0].r - 1);
        for (int i = 1; i < m; i++)
            if (!check(ans, ps, i)) ans.Add(ps[i].r - 1);
        Console.WriteLine(ans.Count());
    }
    public static bool check(List<int> ans, P[] ps, int i)
    {
        foreach (var x in ans)
            if (x >= ps[i].L && x <= ps[i].r) return true;
        return false;
    }
}