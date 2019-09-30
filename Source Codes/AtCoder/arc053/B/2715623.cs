using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<char, int>();
        var s = Console.ReadLine().Trim();
        for (int i = 0; i < s.Length; i++)
            if (d.ContainsKey(s[i])) d[s[i]]++;
            else d[s[i]] = 1;
        var c = 0; var ep = 0;
        foreach (var x in d)
            if (x.Value % 2 == 1)
            {
                c++;
                ep += (x.Value - 1) / 2;
            }
            else ep += x.Value / 2;
        Console.WriteLine(getAns(c,ep));
    }
    public static int getAns (int c , int ep)
    {
        if (c == 0) return 2 * ep;
        if (c == 1) return 2 * ep + 1;
        if (c > ep) return 1;
        else return (ep / c) * 2 + 1;
    }
}