using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var ans = n;

        for (var w = 1; ; w++)
        {
            var h = n / w;
            if (w > h)
                break;

            var diff = h - w;
            var spare = n - w * h;

            ans = Math.Min(ans, diff + spare);
        }
        WriteLine(ans);
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
            int next = Read();
            if (next < 0)
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }
}