using System.Collections.Generic;
using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<int, List<int>>();
        var n = int.Parse(Console.ReadLine().Trim());
        for (int i = 1; i <= n; i++) d[i] = new List<int>();
        for (int i = 2; i <= n; i++)
        {
            var w = int.Parse(Console.ReadLine().Trim());
            d[w].Add(i);
        }
        var ret = getSul(d, 1);
        Console.WriteLine(ret);

    }
    public static int getSul(Dictionary<int, List<int>> d, int id)
    {
        if (d[id].Count() == 0) return 1;
        var maxs = -1; var mins = 999999999;
        foreach (var x in d[id])
        {
            var w = getSul(d, x);
            if (w > maxs) maxs = w;
            if (w < mins) mins = w;
        }
        return maxs + mins + 1;
    }
}