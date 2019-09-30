using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ')[1];
        Console.WriteLine($"A{input.Substring(0, 1)}C");
        
    }
}