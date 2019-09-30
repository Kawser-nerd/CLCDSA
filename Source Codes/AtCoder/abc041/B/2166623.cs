using System;

public class Hello
{
    public const long P = 1000000007;
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = long.Parse(line[0]) % P;
        var b = long.Parse(line[1]) % P;
        var c = long.Parse(line[2]) % P;
        var ab = (a * b) % P;
        var abc = (ab * c) % P;
        Console.WriteLine(abc);
    }
}