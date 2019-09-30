using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split();
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);

        if (a == 1) a += 13;
        if (b == 1) b += 13;

        if (a < b) Console.WriteLine("Bob");
        else if (b < a) Console.WriteLine("Alice");
        else Console.WriteLine("Draw");
    }
}