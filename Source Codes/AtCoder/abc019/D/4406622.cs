using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;
using static System.Math;
using System.Collections;

class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int maxValue = 0;
        int maxInd = -1;
        for (int i = 2; i <= n; i++)
        {
            Console.WriteLine($"? 1 {i}");
            int value = int.Parse(Console.ReadLine());
            if (maxValue < value)
            {
                maxValue = value;
                maxInd = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (maxInd == i) continue;
            Console.WriteLine($"? {maxInd} {i}");
            int value = int.Parse(Console.ReadLine());
            maxValue = Max(maxValue, value);
        }
        Console.WriteLine($"! {maxValue}");
    }
}