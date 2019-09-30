using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        Console.WriteLine(s[s.Length - 1] == 'T' ? "YES" : "NO");
    }
}