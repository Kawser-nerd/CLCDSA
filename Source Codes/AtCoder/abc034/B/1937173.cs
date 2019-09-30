using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        Console.WriteLine(n % 2 == 0 ? n - 1 : n + 1);
    }
}