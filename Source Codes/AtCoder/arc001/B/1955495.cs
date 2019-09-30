using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        Console.ReadLine();
        string s = Console.ReadLine();
        int[] a = { s.Count(x => x == '1'), s.Count(x => x == '2'), s.Count(x => x == '3'), s.Count(x => x == '4') };
        Console.WriteLine($"{a.Max()} {a.Min()}");
    }
}