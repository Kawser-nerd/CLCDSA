using System.Collections.Generic;
using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<char, long>();
        var s = Console.ReadLine().Trim();
        var sL =(long) s.Length;
        for (int i = 0; i < sL; i++)
            if (d.ContainsKey(s[i])) d[s[i]]++;
            else d[s[i]] = 1;
        var count = 0L;
        foreach (var x in d.Where(y => y.Value >= 2))
            count += x.Value* (x.Value - 1) / 2;
        var res = sL * (sL - 1) / 2 - count + 1;
        Console.WriteLine(res);
    }
}