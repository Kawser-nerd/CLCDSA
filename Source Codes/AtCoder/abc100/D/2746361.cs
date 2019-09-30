using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        long[][] xyzs = Enumerable.Repeat(0, nm[0]).Select(_ => Console.ReadLine().Split().Select(long.Parse).ToArray()).ToArray();
        long max = 0;
        foreach (int x in new[] { -1, 1 })
        {
            foreach (int y in new[] { -1, 1 })
            {
                foreach (int z in new[] { -1, 1 })
                {
                    var values = Enumerable.Range(0, nm[0]).Select(p => xyzs[p][0] * x + xyzs[p][1] * y + xyzs[p][2] * z).OrderByDescending(value => value).Take(nm[1]).Sum();
                    max = Math.Max(values, max);
                }
            }
        }
        Console.WriteLine(max);
    }

}