using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var x = int.Parse(line[1]);
        Console.WriteLine(Math.Min(n - x, x - 1));
    }
}