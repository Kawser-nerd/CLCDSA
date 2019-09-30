using System;

public class Hello
{
    public static void Main()
    {
        var x = int.Parse(Console.ReadLine().Trim());
        for (int i = 1; i <= 200; i++)
            if (Math.Pow(i, 4) == x) { Console.WriteLine(i); break; }
    }
}