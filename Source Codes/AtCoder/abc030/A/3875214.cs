using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        var takahashi = input[1] / (double)input[0];
        var aoki = input[3] / (double)input[2];

        if (takahashi == aoki)
        {
            Console.WriteLine("DRAW");
        }
        else if (takahashi > aoki)
        {
            Console.WriteLine("TAKAHASHI");
        }
        else
        {
            Console.WriteLine("AOKI");
        }
    }
}