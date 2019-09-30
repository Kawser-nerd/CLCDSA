using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var val = 0;
        val += input[0] * input[1] * 2;
        val += input[1] * input[2] * 2;
        val += input[2] * input[0] * 2;
        Console.WriteLine(val);
    }
}