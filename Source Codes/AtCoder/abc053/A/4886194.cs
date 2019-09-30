using System;

class Program
{
    static void Main(string[] args)
    {
        var x = int.Parse(Console.ReadLine());
        Console.WriteLine(x < 1200 ? "ABC" : "ARC");
    }
}