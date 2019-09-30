using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        Console.WriteLine(s.LastIndexOf('Z') - s.IndexOf('A') + 1);
    }
}