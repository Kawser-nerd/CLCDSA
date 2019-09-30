using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var abq = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var a = abq[0];
        var b = abq[1];
        var q = abq[2];
        var ss = new long[a + 2];
        ss[0] = long.MinValue / 4;
        ss[ss.Length - 1] = long.MaxValue / 4;
        for (int i = 0; i < ss.Length - 2; i++)
        {
            ss[i + 1] = long.Parse(Console.ReadLine());
        }
        var ts = new long[b + 2];
        ts[0] = long.MinValue / 4;
        ts[ts.Length - 1] = long.MaxValue / 4;
        for (int i = 0; i < ts.Length - 2; i++)
        {
            ts[i + 1] = long.Parse(Console.ReadLine());
        }
        var queries = new long[q];
        for (int i = 0; i < queries.Length; i++)
        {
            queries[i] = long.Parse(Console.ReadLine());
        }

        var sb = new System.Text.StringBuilder();
        foreach (var x in queries)
        {
            var s = Neighbors(x, ss);
            var t = Neighbors(x, ts);
            var d = new [] 
            { 
                x - Math.Min(s.Item1, t.Item1), 
                (x - s.Item1) * 2 + t.Item2 - x,
                (x - t.Item1) * 2 + s.Item2 - x,
                x - s.Item1 + (t.Item2 - x) * 2,
                x - t.Item1 + (s.Item2 - x) * 2,
                Math.Max(s.Item2, t.Item2) - x,
            };
            sb.AppendLine(d.Min().ToString());
        }
        Console.WriteLine(sb);
    }

    static Tuple<long, long> Neighbors(long p, long[] ps)
    {
        var ok = 0;
        var ng = ps.Length;
        while (Math.Abs(ok - ng) > 1)
        {
            var m = (ok + ng) / 2;
            if (p > ps[m])
            {
                ok = m;
            }
            else
            {
                ng = m;
            }
        }

        return Tuple.Create(ps[ok], ps[Math.Min(ok + 1, ps.Length - 1)]);
    }
}