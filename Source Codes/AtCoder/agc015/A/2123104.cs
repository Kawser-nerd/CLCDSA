using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = long.Parse(line[0]);
        var a = long.Parse(line[1]);
        var b = long.Parse(line[2]);
        if (a > b) { Console.WriteLine(0); goto end; }
        if (a != b && n == 1) { Console.WriteLine(0); goto end; }
        else if (a == b && n == 1) { Console.WriteLine(1); goto end; }
        var ret = (n - 2) * (b - a) + 1;
        Console.WriteLine(ret);
        end:;
    }
}