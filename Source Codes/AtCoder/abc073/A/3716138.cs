using System;
using System.Linq;

class Program
{
    static void Main()
    {
        var n = Console.ReadLine();
        Console.WriteLine(n.Contains('9') ? "Yes" : "No");
    }
}