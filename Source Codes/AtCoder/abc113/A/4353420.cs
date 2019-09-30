using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        var x = input[0];
        var y = input[1];

        Console.WriteLine(x + y / 2);
    }
}