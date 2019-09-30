using System;

class Program
{
    static void Main(string[] args)
    {
        var n = 0;
        foreach (var c in Console.ReadLine())
            n += c == '+' ? 1 : -1;
        Console.WriteLine(n);
    }
}