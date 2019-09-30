using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var res = 0;
        foreach (var x in a) res += Math.Max(0, 80 - x);
        Console.WriteLine(res);
    }
}