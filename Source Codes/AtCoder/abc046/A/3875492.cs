using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        Console.WriteLine(input.Distinct().Count());
    }
}