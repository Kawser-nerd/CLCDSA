using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = int.Parse(line[0]);
        var b = int.Parse(line[1]);
        Console.WriteLine(((a > 0 && b > 0) | (a < 0 && b < 0)) ? b - a : b - a - 1);

    }
}