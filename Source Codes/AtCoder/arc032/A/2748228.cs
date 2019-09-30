using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        Console.WriteLine(n == 2 ? "WANWAN" : "BOWWOW");
    }
}