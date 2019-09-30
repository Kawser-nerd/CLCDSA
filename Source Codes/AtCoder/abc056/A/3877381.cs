using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var input = Console.ReadLine().Split(' ').ToList();
        if (input[0] == "H")
        {
            Console.WriteLine(input[1]);
        }
        else
        {
            if (input[1] == "H")
            {
                Console.WriteLine("D");
            }
            else
            {
                Console.WriteLine("H");
            }
        }
    }
}