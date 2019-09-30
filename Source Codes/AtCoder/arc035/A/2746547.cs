using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var sL = s.Length;
        for (int i = 0; i < sL / 2; i++)
            if (s[i] == s[sL - 1 - i] | s[i] == '*' | s[sL - 1 - i] == '*') continue;
            else { Console.WriteLine("NO"); goto end; }
        Console.WriteLine("YES");
        end:;
    }
}