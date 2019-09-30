using System;
using System.Linq;
using System.Collections.Generic;

using E = System.Linq.Enumerable;

public class Program
{
    public static void Main()
    {
        var ns = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var n = ns[0];
        var s = ns[1];
        var cs = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

        var ds = cs.Select(x => Math.Abs(s - x)).ToArray();
        for (int i = 1; i < ds.Length; i++)
        {
            while (ds[i] != 0)
            {
                if (ds[i - 1] > ds[i])
                {
                    ds[i] += ds[i - 1];
                    ds[i - 1] = ds[i] - ds[i - 1];
                    ds[i] -= ds[i - 1];
                }

                ds[i] %= ds[i - 1];
            }
            ds[i] = ds[i - 1];
        }
        Console.WriteLine(ds.Last());
    }
}