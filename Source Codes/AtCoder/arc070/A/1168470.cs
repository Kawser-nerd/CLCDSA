using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var x = double.Parse(Console.ReadLine());

        var i = (int)Math.Ceiling((Math.Sqrt(8 * x + 1) - 1) / 2);
        Console.WriteLine(i);
    }
}