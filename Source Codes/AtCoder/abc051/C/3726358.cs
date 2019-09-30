using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var data = Console.ReadLine().Split();
        var sx = int.Parse(data[0]);
        var sy = int.Parse(data[1]);
        var tx = int.Parse(data[2]);
        var ty = int.Parse(data[3]);

        for (var y = sy; y < ty; y++)
        {
            Console.Write('U');
        }

        for (var x = sx; x < tx; x++)
        {
            Console.Write('R');
        }

        for (var y = ty; y > sy; y--)
        {
            Console.Write('D');
        }

        for (var x = tx; x > sx - 1; x--)
        {
            Console.Write('L');
        }

        for (var y = sy; y < ty + 1; y++)
        {
            Console.Write('U');
        }

        for (var x = sx - 1; x < tx; x++)
        {
            Console.Write('R');
        }

        Console.Write("DR");

        for (var y = ty; y > sy - 1; y--)
        {
            Console.Write('D');
        }

        for (var x = tx + 1; x > sx; x--)
        {
            Console.Write('L');
        }

        Console.WriteLine('U');
    }
}