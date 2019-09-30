using System;

class Program
{
    static void Main(string[] args)
    {
        var xy = Console.ReadLine().Split(' ');
        var x = int.Parse(xy[0]);
        var y = int.Parse(xy[1]);
        Console.WriteLine(x + y / 2);
    }
}