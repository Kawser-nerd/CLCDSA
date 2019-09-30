using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        if (input[1] > input[0] / 2)
        {
            Console.WriteLine(input[0] - input[1]);
        }
        else
        {
            Console.WriteLine(input[1] - 1);
        }
    }
}