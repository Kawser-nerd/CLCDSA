using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var d = new Dictionary<int, int>();
        for (int i = 0; i < n; i++) d[int.Parse(Console.ReadLine().Trim())] = i;
        var ret = 1; var pre = d[1]; var te = 1;
        for (int i = 2; i <= n; i++)
        {
            if (d[i] > pre) { te++; ret = Math.Max(ret, te); }
            else te = 1;
            pre = d[i];
        }
        Console.WriteLine(n - ret);
    }
}