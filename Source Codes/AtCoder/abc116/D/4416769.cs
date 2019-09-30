using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var nk = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var n = nk[0];
        var k = nk[1];
        var ts = new int[n];
        var ds = new long[n];
        for (int i = 0; i < ts.Length; i++)
        {
            var td = Console.ReadLine().Split().ToArray();
            ts[i] = int.Parse(td[0]);
            ds[i] = long.Parse(td[1]);
        }

        Array.Sort(ds, ts);
        Array.Reverse(ts);
        Array.Reverse(ds);

        var maximum = Solve(n, k, ts, ds);
        Console.WriteLine(maximum);
    }

    static long Solve(int n, int k, int[] ts, long[] ds)
    {
        var neta = 0L;
        var positiveBase = 0L;
        var nonpositiveBase = 0L;
        var nonpositive = new Stack<int>();
        var existingByNeta = new bool[n + 1];
        int i = 0;
        for (; i < k; i++)
        {
            if (existingByNeta[ts[i]])
            {
                nonpositiveBase += ds[i];
                nonpositive.Push(i);
            }
            else
            {
                positiveBase += ds[i];
                neta++;
                existingByNeta[ts[i]] = true;
            }
        }
        var point = positiveBase + nonpositiveBase + neta * neta;
        for (; i < n; i++)
        {
            if (!nonpositive.Any())
            {
                break;
            }

            if (existingByNeta[ts[i]])
            {
                continue;
            }

            positiveBase += ds[i];
            neta++;
            existingByNeta[ts[i]] = true;;
            nonpositiveBase -= ds[nonpositive.Pop()];
            point = Math.Max(point, positiveBase + nonpositiveBase + neta * neta);
        }
        return point;
    }
}