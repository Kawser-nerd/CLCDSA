using System;

public class Hello
{
    public static void Main()
    {
        var x = int.Parse(Console.ReadLine().Trim());
        var z = (int)Math.Pow(x, 0.25);
        Console.WriteLine(z);
    }
}