using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var x = int.Parse(Console.ReadLine());
        if (x < 1200)
        {
            Console.WriteLine("ABC");
        }
        else
        {
            Console.WriteLine("ARC");
        }
    }
}