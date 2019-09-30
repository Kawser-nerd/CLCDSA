using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        Console.WriteLine(n * 800 - n / 15 * 200);
    }
}