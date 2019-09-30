using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var pre = int.Parse(Console.ReadLine().Trim());
        var state = 'w';
        var ws = 0;
        var res = 0;
        for (int i = 1; i < n; i++)
        {
            var w = int.Parse(Console.ReadLine().Trim());
            if (w > pre && state == 'e')
            {
                var mnt = i - ws;
                res = Math.Max(res, mnt);
                ws = i - 1;
                state = 'w';
            }
            if (w < pre && state == 'w')
            {
                state = 'e';
            }
            pre = w;
        }
        res = Math.Max(res, n - ws);
        Console.WriteLine(res);
    }
}