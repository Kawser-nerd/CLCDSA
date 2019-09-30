using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;
 
class P
{
    static void Main()
    {
        var nx = Console.ReadLine().Split().Select(int.Parse).ToList();
        int n = nx[0];
        long x = nx[1];
        var a = Console.ReadLine().Split().Select(long.Parse).ToList();
        long[][] costMin = Enumerable.Repeat(0, n).Select(_ => new long[n]).ToArray();
        costMin[0] = a.ToArray();
        long min = a.Sum();
        for (int i = 1; i < n; i++)
        { 
            for (int j = 0; j < n; j++) costMin[i][(j + 1) % n] = Min(costMin[i - 1][(j + 1) % n], costMin[i - 1][j]);
            min = Min(min, costMin[i].Sum() + i * x);
        }
        Console.WriteLine(min);
    }
}