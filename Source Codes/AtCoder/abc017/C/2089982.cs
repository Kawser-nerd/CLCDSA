using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] imos = new int[nm[1] + 1];
        int sum = 0;
        for (int i = 0; i < nm[0]; i++)
        {
            int[] lrs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            imos[lrs[0] - 1] += lrs[2];
            imos[lrs[1]] -= lrs[2];

            sum += lrs[2];
        }

        int min = int.MaxValue;
        int nowSum = 0;
        for (int i = 0; i < imos.Length - 1; i++)
        {
            nowSum += imos[i];
            min = Math.Min(min, nowSum);
        }
        Console.WriteLine(sum - min);
    }
}