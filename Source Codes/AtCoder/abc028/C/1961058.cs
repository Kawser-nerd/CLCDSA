using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        Console.WriteLine(Math.Max(a[0] + a[3] + a[4], a[1] + a[2] + a[4]));
    }
}