using System;

class Program
{
    static void Main()
    {
        var nab = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        Console.WriteLine(Math.Max(0, (nab[2] - nab[1]) * (nab[0] - 2) + 1));
    }
}