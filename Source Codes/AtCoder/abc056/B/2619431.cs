using System;

class Program
{
    static void Main()
    {
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        Console.WriteLine(Math.Max(0, Math.Max(a[1], a[2]) - (Math.Min(a[1], a[2]) + a[0])));
    }
}