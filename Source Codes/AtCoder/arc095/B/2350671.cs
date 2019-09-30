using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var max = a.Max();

        var best = a.Min();
        foreach (var x in a)
        {
            if(Math.Abs(max - x * 2) < Math.Abs(max - best * 2))
            {
                best = x;
            }
        }

        Console.WriteLine($"{max} {best}");
    }
}