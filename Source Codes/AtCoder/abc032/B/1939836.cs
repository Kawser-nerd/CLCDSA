using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var hs = new HashSet<string>();
        var s = Console.ReadLine().Trim();
        var k = int.Parse(Console.ReadLine().Trim());
        for (int i = 0; i <= s.Length - k; i++)
            hs.Add(s.Substring(i, k));
        Console.WriteLine(hs.Count());
    }
}