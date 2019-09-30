using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h1 = int.Parse(line[0]);
        var w1 = int.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var h2 = int.Parse(line[0]);
        var w2 = int.Parse(line[1]);
        Console.WriteLine((h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2) ? "YES" : "NO");
    }
}