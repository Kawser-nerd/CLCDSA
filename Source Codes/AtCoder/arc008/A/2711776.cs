using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var c1 = 100 * ((n + 9) / 10);
        var c2 = 100 * (n / 10) + 15 * (n % 10);
        Console.WriteLine(Math.Min(c1, c2));
    }
}