using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var data = Console.ReadLine().Split();
        var a = data[0];
        var b = data[1];

        var i = int.Parse(data[0] + data[1]);
        var x = Math.Sqrt((double)i);
        Console.WriteLine(x == (int)x ? "Yes" : "No");
    }
}