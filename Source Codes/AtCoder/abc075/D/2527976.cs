using System.Collections.Generic;
using System.Linq;
using System;

public class P
{
    public int x { get; set; }
    public int y { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var ps = new List<P>();
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var ax = new int[n];
        var ay = new int[n];
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var x = int.Parse(line[0]);
            var y = int.Parse(line[1]);
            ax[i] = x;
            ay[i] = y;
            ps.Add(new P { x = x, y = y });
        }
        Console.WriteLine(getAns(ax, ay, ps, n, k));
    }
    public static long getAns(int[] ax, int[] ay, List<P> ps, int n, int kk)
    {
        int p1; int p2; int p3; int p4;
        var retlist = new List<long>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    for (int L = 0; L < n; L++)
                    {
                        p1 = ax[i]; p2 = ax[j]; p3 = ay[k]; p4 = ay[L];
                        if ((p1 > p2) && (p3 > p4) && check(p1, p2, p3, p4, kk, ps))
                            retlist.Add((long)(p1 - p2) * (long)(p3 - p4));
                    }
        return retlist.Min();
    }
    public static bool check(int p1, int p2, int p3, int p4, int kk, List<P> ps)
    {
        var count = 0;
        foreach (var x in ps)
            if (x.x <= p1 && x.x >= p2 && x.y <= p3 && x.y >= p4) count++;
        return count >= kk;
    }
}