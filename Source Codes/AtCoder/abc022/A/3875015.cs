using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var weight = int.Parse(Console.ReadLine());
        var count = 0;

        if (weight >= input[1] && weight <= input[2])
        {
            count++;
        }

        for (int i = 1; i < input[0]; i++)
        {
            weight += int.Parse(Console.ReadLine());

            if (weight >= input[1] && weight <= input[2])
            {
                count++;
            }
        }

        Console.WriteLine(count);
    }
}