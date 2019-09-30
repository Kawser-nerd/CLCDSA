using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        var input = int.Parse(Console.ReadLine());

        if (input <= 59)
        {
            Console.WriteLine("Bad");
        }
        else if (input <= 89)
        {
            Console.WriteLine("Good");
        }
        else if (input <= 99)
        {
            Console.WriteLine("Great");
        }
        else
        {
            Console.WriteLine("Perfect");
        }
    }
}