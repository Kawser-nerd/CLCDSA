using System;

class Program
{
    static void Main(string[] args)
    {
        var xy = Console.ReadLine().Split(' ');
        var ans = Math.Max(0, int.Parse(xy[0]) - int.Parse(xy[1]));
        Console.WriteLine(ans);
    }
}