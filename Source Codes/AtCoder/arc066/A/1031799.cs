using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

internal class Program
{
    private static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var array = Console.ReadLine().Split(' ').Select(int.Parse).OrderBy(x => x).ToList();
        int k = N / 2;
        if (N % 2 == 1 && array[0] != 0)
            k = -1;
        for (int i = N % 2; i < N; i += 2)
            if (array[i] != i + 1 || array[i + 1] != i + 1)
                k = -1;
        var ret = k == -1 ? 0 : BigInteger.ModPow(2, k, 1000000007);
        Console.WriteLine(ret);
    }
}