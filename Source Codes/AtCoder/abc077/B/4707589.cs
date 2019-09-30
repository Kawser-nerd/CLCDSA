using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var x = (int)Math.Sqrt(n);
        Console.WriteLine(x * x);
    }
}