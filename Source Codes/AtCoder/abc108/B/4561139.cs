using System;

class Program
{
    static void Main(string[] args)
    {
        var xy = Console.ReadLine().Split(' ');
        var x1 = int.Parse(xy[0]);
        var y1 = int.Parse(xy[1]);
        var x2 = int.Parse(xy[2]);
        var y2 = int.Parse(xy[3]);

        var x3 = x2 - (y2 - y1);
        var y3 = y2 + (x2 - x1);

        var x4 = x1 - (y2 - y1);
        var y4 = y1 + (x2 - x1);

        Console.WriteLine($"{x3} {y3} {x4} {y4}");
    }
}