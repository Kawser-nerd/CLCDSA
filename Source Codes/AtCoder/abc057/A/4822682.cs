using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split();
        Console.WriteLine((int.Parse(ab[0]) + int.Parse(ab[1])) % 24);
    }
}