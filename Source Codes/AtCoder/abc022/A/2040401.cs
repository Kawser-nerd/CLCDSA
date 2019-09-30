using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var s = int.Parse(line[1]);
        var t = int.Parse(line[2]);
        var wt = 0;
        var count = 0;
        for (int i = 0; i < n; i++)
        {
            wt += int.Parse(Console.ReadLine().Trim());
            if (wt >= s && wt <= t) count++;
        }
        Console.WriteLine(count);
    }
}