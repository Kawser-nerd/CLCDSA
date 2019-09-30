using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        Console.WriteLine("{0}{1}{2}", s[0], s.Length - 2, s[s.Length - 1]);
    }
}