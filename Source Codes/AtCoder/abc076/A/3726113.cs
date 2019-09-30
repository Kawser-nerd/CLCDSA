using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var r = int.Parse(Console.ReadLine());
        var g = int.Parse(Console.ReadLine());

        Console.WriteLine((2 * g) - r);
    }
}