using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var a0 = int.Parse(Console.ReadLine().Trim());
        if (a0 != 0) { Console.WriteLine(-1); goto end; }
        var p = 0; var ret = 0L; var pre = 0;
        for (int i = 1; i < n; i++)
        {
            var aw = int.Parse(Console.ReadLine().Trim());
            var w = aw - pre;
            if (w >= 2) { Console.WriteLine(-1); goto end; }
            if (w <= 0) {  ret += i - 1 - p; p = i - aw;  }
            pre = aw;
        }
        ret += n - 1 - p;
        Console.WriteLine(ret);
    end:;
    }
}