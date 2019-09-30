using System;

class Program
{
    static void Main()
    {
        var data = Console.ReadLine().Split();
        var sx = int.Parse(data[0]);
        var sy = int.Parse(data[1]);
        var tx = int.Parse(data[2]);
        var ty = int.Parse(data[3]);

        for (var i = sy; i < ty; i++)
        {
            Console.Write('U');
        }

        for (var i = sx; i < tx; i++)
        {
            Console.Write('R');
        }

        for (var i = ty; i > sy; i--)
        {
            Console.Write('D');
        }

        for (var i = tx; i > sx - 1; i--)
        {
            Console.Write('L');
        }

        for (var i = sy; i < ty + 1; i++)
        {
            Console.Write('U');
        }

        for (var i = sx; i < tx + 1; i++)
        {
            Console.Write('R');
        }

        Console.Write("DR");

        for (var i = ty; i > sy - 1; i--)
        {
            Console.Write('D');
        }

        for (var i = tx; i > sx - 1; i--)
        {
            Console.Write('L');
        }

        Console.WriteLine('U');
    }
}