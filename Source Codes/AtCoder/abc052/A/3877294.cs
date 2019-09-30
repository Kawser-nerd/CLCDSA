using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        Console.WriteLine(Math.Max(input[0] * input[1], input[2] * input[3]));
    }
}