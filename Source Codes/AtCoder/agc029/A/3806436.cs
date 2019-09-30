using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var wsum = 0L; var w = 0L;
        for (int i = 0; i < s.Length; i++)
            if (s[i] == 'W')
            {
                w++;
                wsum += i;
            }
        var ans = wsum - w * (w - 1) / 2;
        Console.WriteLine(ans);
    }
}