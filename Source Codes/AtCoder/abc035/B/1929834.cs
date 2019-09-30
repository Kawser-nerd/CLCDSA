using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var t = int.Parse(Console.ReadLine().Trim());
        var d = new Dictionary<char, int>();
        d['U'] = 0; d['D'] = 0; d['R'] = 0; d['L'] = 0; d['?'] = 0;
        for (int i = 0; i < s.Length; i++) d[s[i]]++;
        var x = Math.Abs(d['U'] - d['D']) + Math.Abs(d['R'] - d['L']);
        var q = d['?'];
        if (t == 1) Console.WriteLine(x + q);
        else if (q <= x) Console.WriteLine(x - q);
        else if ((q - x) % 2 == 0) Console.WriteLine(0);
        else Console.WriteLine(1);
    }
}