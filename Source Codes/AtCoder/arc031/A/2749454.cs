using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        Console.WriteLine(check(s) ? "YES" : "NO");
    }
    public static bool check(string s)
    {
        var sL = s.Length;
        for (int i = 0; i < sL / 2; i++)
            if (s[i] != s[sL - 1 - i]) return false;
        return true;
    }
}