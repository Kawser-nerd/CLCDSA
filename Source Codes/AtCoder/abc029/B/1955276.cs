using System;

public class Hello
{
    public static void Main()
    {
        var count = 0;
        for (int i = 0; i < 12; i++)
            if (Console.ReadLine().Trim().Contains("r")) count++;
        Console.WriteLine(count);
    }
}