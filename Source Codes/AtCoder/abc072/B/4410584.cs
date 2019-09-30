using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        var s2 = s.Where((x, index) => index % 2 == 0 ).ToArray();
        Console.WriteLine(s2);
    }
}