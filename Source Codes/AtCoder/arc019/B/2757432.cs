using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var w = check(s);
        var sL = s.Length;
        int res;
        if (w == 0) res = (sL / 2) * 2 * 25;
        else if (w == 1) res = sL * 25 - 2;
        else res = sL * 25;
        Console.WriteLine(res);
    }
    public static int check(string s)
    {
        var sL = s.Length;
        var count = 0;
        for (int i = 0; i < sL / 2; i++)
        {
            if (s[i] != s[sL - 1 - i]) count++;
            if (count >= 2) return 2;
        }
        return count;
    }
}