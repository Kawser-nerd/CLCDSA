using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var w1 = "ODIZSB";
        var w2 = "001258";
        var d = new Dictionary<char, char>();
        for (int i = 0; i < 6; i++) d[w1[i]] = w2[i];
        var s = Console.ReadLine().Trim();
        for (int i = 0; i < s.Length; i++)
            Console.Write(d.ContainsKey(s[i]) ? d[s[i]] : s[i]);
        Console.WriteLine();
    }
}