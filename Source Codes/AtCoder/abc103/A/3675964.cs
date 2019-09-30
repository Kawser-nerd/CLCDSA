using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var a = Console.ReadLine().Split().Select(ai => int.Parse(ai)).OrderBy(ai => ai).ToArray();
        var result = 0;

        result += a[1] - a[0];
        result += a[2] - a[1];

        Console.WriteLine(result);
    }
}