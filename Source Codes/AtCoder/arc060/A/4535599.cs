using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;


static class P
{
    static void Main()
    {
        long[,] dp = new long[51, 2501];
        var na = Console.ReadLine().Split().Select(int.Parse).ToList();
        var xs = Console.ReadLine().Split().Select(int.Parse).ToList();
        dp[0, 0] = 1;
        foreach (var x in xs)
        {
            long[,] newdp = new long[51, 2501];
            for (int i = 0; i <= 49; i++)
            {
                for (int j = 0; j <= 2450; j++)
                {
                    newdp[i, j] += dp[i, j];
                    newdp[i + 1, j + x] += dp[i, j];
                }
            }
            dp = newdp;
        }
        long res = 0;
        for (int i = 1; i <= 50; i++)
        {
            for (int j = 0; j <= 2500; j++)
            {
                if(j % i == 0 && j / i == na[1]) res += dp[i, j];
            }
        }
        Console.WriteLine(res);
    }
}