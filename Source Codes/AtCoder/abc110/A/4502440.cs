using System;

class Program
{
    static void Main(string[] args)
    {
        var abc = Console.ReadLine().Split(' ');
        var a = int.Parse(abc[0]);
        var b = int.Parse(abc[1]);
        var c = int.Parse(abc[2]);

        var n = Math.Max(Math.Max(a, b), c);
        Console.WriteLine(a + b + c - n + n * 10);
    }
}