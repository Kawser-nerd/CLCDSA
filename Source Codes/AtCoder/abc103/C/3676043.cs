using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split().Select(ai => int.Parse(ai));

        var sum = 0;
        foreach (var ai in a)
        {
            sum += ai;
        }

        Console.WriteLine(sum - n);
    }
}