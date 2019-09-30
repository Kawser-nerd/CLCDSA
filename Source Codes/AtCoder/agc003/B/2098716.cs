using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var tsum = 0L;
        var count = 0L;
        for (int i = 0; i < n; i++)
        {
            var w = long.Parse(Console.ReadLine().Trim());
            if (w == 0) { count += tsum / 2; tsum = 0; }
            else tsum += w;
        }
        count += tsum / 2;
        Console.WriteLine(count);
    }
}