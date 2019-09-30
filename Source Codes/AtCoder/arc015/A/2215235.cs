using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var res = 9 * n / 5d + 32;
        Console.WriteLine(res);
    }
}