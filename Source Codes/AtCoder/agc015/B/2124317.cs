using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var sL = s.Length;
        var count = (long)2 * (sL - 1);
        for (int i = 1; i < sL - 1; i++)
            if (s[i] == 'U') count += sL + i - 1;
            else count += 2 * sL - i - 2;
        Console.WriteLine(count);
    }
}