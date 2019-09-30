using System;
using System.Linq;

public class Program
{
    private const char Up = 'U';
    private const char Right = 'R';
    private const char Down = 'D';
    private const char Left = 'L';

    public static void Main()
    {
        var data = Console.ReadLine().Split();
        var sx = int.Parse(data[0]);
        var sy = int.Parse(data[1]);
        var tx = int.Parse(data[2]);
        var ty = int.Parse(data[3]);

        var x = tx - sx;
        var y = ty - sy;

        var result = "";

        result += Generate(Up, y);
        result += Generate(Right, x);
        result += Generate(Down, y);

        x++;
        y++;

        result += Generate(Left, x);
        result += Generate(Up, y);
        result += Generate(Right, x);

        result += "DR";

        result += Generate(Down, y);
        result += Generate(Left, x);

        result += Up;

        Console.WriteLine(result);
    }

    private static string Generate(char c, int count) => new String(c, count);
}