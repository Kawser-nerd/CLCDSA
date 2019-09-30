using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var n = int.Parse(Console.ReadLine().Trim());
        var a = new List<string>();
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                a.Add(s[i].ToString() + s[j]);
        a.Sort();
        Console.WriteLine(a[n - 1]);
    }
}