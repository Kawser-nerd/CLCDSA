using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var d = Array.ConvertAll(line, int.Parse);
        line = Console.ReadLine().Trim().Split(' ');
        var j = Array.ConvertAll(line, int.Parse);
        var res = 0;
        for (int i = 0; i < 7; i++) res += Math.Max(d[i], j[i]);
        Console.WriteLine(res);
    }
}