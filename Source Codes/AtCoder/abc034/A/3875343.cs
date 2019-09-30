using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

        if (input[0] < input[1])
        {
            Console.WriteLine("Better");
        }
        else
        {
            Console.WriteLine("Worse");
        }
    }
}