using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var n = Console.ReadLine().ToCharArray().ToList();
        if (n.Distinct().Count() != 1)
        {
            Console.WriteLine("DIFFERENT");
        }
        else
        {
            Console.WriteLine("SAME");
        }
    }
}