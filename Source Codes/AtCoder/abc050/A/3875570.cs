using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').ToList();
        if (input[1] == "+")
        {
            Console.WriteLine(int.Parse(input[0]) + int.Parse(input[2]));
        }
        else
        {
            Console.WriteLine(int.Parse(input[0]) - int.Parse(input[2]));
        }
    }
}