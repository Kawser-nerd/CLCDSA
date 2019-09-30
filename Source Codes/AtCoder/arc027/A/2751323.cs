using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var ans = (18 - h) * 60 - m;
        Console.WriteLine(ans);
    }
}