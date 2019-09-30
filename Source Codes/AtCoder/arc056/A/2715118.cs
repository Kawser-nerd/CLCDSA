using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = long.Parse(line[0]);
        var b = long.Parse(line[1]);
        var k = long.Parse(line[2]);
        var L = long.Parse(line[3]);
        var c1 = ((k + L - 1) / L) * b;
        var c2 = (k / L) * b + (k % L) * a;
        Console.WriteLine(Math.Min(c1, c2));
    }
}