using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = int.Parse(Console.ReadLine());
        var max = 0;
        for (int x = 0; x < input; x++)
        {
            var y = input - x;
            max = Math.Max(max, x * y);
        }

        Console.WriteLine(max);
    }
}