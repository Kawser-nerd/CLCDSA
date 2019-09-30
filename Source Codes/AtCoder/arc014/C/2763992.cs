using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var s = Console.ReadLine().Trim();
        var c = new int[3];
        c[0] = n - s.Replace("R", "").Length;
        c[1] = n - s.Replace("G", "").Length;
        c[2] = n - c[0] - c[1];
        var ret = 0;
        foreach (var x in c)
            ret += x % 2;
        Console.WriteLine(ret);
    }
}