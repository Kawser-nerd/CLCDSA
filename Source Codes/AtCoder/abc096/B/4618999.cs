using System;

class Program
{
    static void Main(string[] args)
    {
        var abc = Console.ReadLine().Split(' ');
        var a = int.Parse(abc[0]);
        var b = int.Parse(abc[1]);
        var c = int.Parse(abc[2]);

        var k = int.Parse(Console.ReadLine());

        var max = Math.Max(Math.Max(a, b), c);
        var sum = a + b + c - max + max * Math.Pow(2, k);
        Console.WriteLine(sum);
    }
}