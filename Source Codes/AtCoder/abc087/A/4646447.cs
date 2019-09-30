using System;

class Program
{
    static void Main(string[] args)
    {
        var x = int.Parse(Console.ReadLine());
        var a = int.Parse(Console.ReadLine());
        var b = int.Parse(Console.ReadLine());

        Console.WriteLine((x - a) % b);
    }
}