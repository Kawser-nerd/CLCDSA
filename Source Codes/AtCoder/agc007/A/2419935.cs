using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var count = 0;
        for (int i = 0; i < h; i++)
            count += w - Console.ReadLine().Trim().Replace("#", "").Length;
        Console.WriteLine(count == h + w - 1 ? "Possible" : "Impossible");
    }
}