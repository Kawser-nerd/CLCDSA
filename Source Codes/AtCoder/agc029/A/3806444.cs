using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var sL = s.Length;
        var wsum = 0L;
        for (int i = 0; i < sL; i++)
            if (s[i] == 'W') wsum += i;
        long w = sL - s.Replace("W", "").Length;
        var ans = wsum - w * (w - 1) / 2L;
        Console.WriteLine(ans);
    }
}