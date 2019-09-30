using System;
using System.Linq;
using System.Collections.Generic;
class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());

        var val = n * 800;
        val += -(200 * (n / 15));
        Console.WriteLine(val);
    }
}