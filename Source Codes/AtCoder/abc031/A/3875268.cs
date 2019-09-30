using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var atk = (input[0] + 1) * input[1];
        var def = input[0] * (input[1] + 1);
        Console.WriteLine(Math.Max(atk, def));
    }
}