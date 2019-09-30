using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var hs = new HashSet<string>();
        var n = int.Parse(Console.ReadLine().Trim());
        var pre = Console.ReadLine().Trim();
        hs.Add(pre);
        for (int i = 1; i < n; i++)
        {
            var w = Console.ReadLine().Trim();
            if (!hs.Add(w) | pre[pre.Length - 1] != w[0]) { Console.WriteLine(i % 2 == 1 ? "WIN" : "LOSE"); goto end; }
            pre = w;
        }
        Console.WriteLine("DRAW");
        end:;
    }
}