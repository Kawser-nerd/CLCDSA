//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var N = line1[0];
        var A = line1[1];
        var B = line1[2];

        var X = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();

        long sum = 0;

        for (int i = 0; i < N - 1; i++)
        {
            sum += Math.Min(B, A * (X[i + 1] - X[i]));
        }

        Console.WriteLine(sum);
    }
}