using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input1 = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var input2 = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

        var value = 0;

        value += input1[0] * input2[0];
        value += input1[1] * input2[1];
        if (input2.Sum() >= input1[3])
        {
            value -= input1[2] * input2.Sum();
        }

        Console.WriteLine(value);
    }
}