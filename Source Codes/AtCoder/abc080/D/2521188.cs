using System.Collections.Generic;
using System.Linq;
using System;

public class Ba
{
    public int s { get; set; }
    public int t { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<int, List<Ba>>();
        var tmax = 0;
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var C = int.Parse(line[1]);
        for (int i = 0; i < C; i++) d[i] = new List<Ba>();
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var s = int.Parse(line[0]);
            var t = int.Parse(line[1]);
            tmax = Math.Max(tmax, t);
            var c = int.Parse(line[2]) - 1;
            d[c].Add(new Ba { s = s, t = t });
        }
        var bas = setData(d, n, C);
        Console.WriteLine(getAns(bas, tmax));
    }
    public static int getAns(List<Ba> bas, int tmax)
    {
        var a = new int[tmax + 2];
        for (int i = 0; i < bas.Count(); i++)
        {
            a[bas[i].s]++;
            a[bas[i].t ]--;
        }
        var ret = a[0]; var rw = a[0];
        for (int i = 1; i < a.Length; i++)
        {
            rw = a[i] + rw;
            ret = Math.Max(ret, rw);
        }
        return ret;
    }
    public static List<Ba> setData(Dictionary<int, List<Ba>> d, int n, int C)
    {
        var ret = new List<Ba>();
        for (int i = 0; i < C; i++)
        {
            if (d[i].Count() >= 2)
            {
                var sortd = d[i].OrderBy(x => x.s).ToArray();
                var ns = sortd[0].s; var nt = sortd[0].t;
                var wns = false;
                for (int j = 1; j < sortd.Length; j++)
                {
                    if (sortd[j].s == nt) { nt = sortd[j].t; wns = true; }
                    else { ret.Add(new Ba { s = ns - 1, t = nt }); ns = sortd[j].s; nt = sortd[j].t; }
                    if (j == sortd.Length - 1 && wns) ret.Add(new Ba { s = ns - 1, t = nt });
                    else if (j == sortd.Length - 1 && !wns)  ret.Add(new Ba { s = sortd[j].s -1 , t = sortd[j].t });
                }
            }
            else if (d[i].Count() == 1) ret.Add(new Ba { s = d[i][0].s -1, t = d[i][0].t });
        }
        return ret;
    }
}