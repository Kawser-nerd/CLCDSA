using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        var n = input[0];
        var k = input[1];
        var trees = new int[n];
        for (int i = 0; i < n; i++)
        {
            trees[i] = int.Parse(Console.ReadLine());
        }

        Array.Sort(trees);

        var min = int.MaxValue;
        for (int i = 0; i < n - k + 1; i++)
        {
            var val = trees[i + k - 1] - trees[i];
            min = Math.Min(min, val);
        }

        Console.WriteLine(min);
    }
}