using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var a = Console.ReadLine();
        var i = int.Parse(Console.ReadLine());

        Console.WriteLine(a.Substring(i - 1, 1));
    }
}