using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);
        Console.WriteLine((a * b) % 2 == 1 ? "Yes" : "No");
    }
}