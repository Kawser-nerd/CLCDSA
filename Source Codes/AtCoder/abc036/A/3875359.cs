using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var count = input[1] / input[0];
        if (input[1] % input[0] != 0)
        {
            count++;
        }

        Console.WriteLine(count);
    }
}