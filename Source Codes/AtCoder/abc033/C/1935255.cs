using System;

public class Hello
{
    public static void Main()
    {
        string[] s = Console.ReadLine().Trim().Split('+');
        var count = 0;
        for (int i = 0; i < s.Length; i++)
            if (!s[i].Contains("0")) count++;
        Console.WriteLine(count);
    }
}