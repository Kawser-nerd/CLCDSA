using System;

public class Hello
{
    public static void Main()
    {
        var s = 2025 -   int.Parse(Console.ReadLine().Trim());
        for (int i = 1; i <= 9; i++)
            for (int j = 1; j <= 9; j++)
                if (i * j == s) Console.WriteLine("{0} x {1}", i, j);
    }
}