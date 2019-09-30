using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var a = new string[] { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
        var b = new int[] { 0, 5, 4, 3, 2, 1, 0 };
        var d = new Dictionary<string, int>();
        var s = Console.ReadLine().Trim();
        var s2 = s.Substring(0, 2);
        for (int i = 0; i < 7; i++)
            if (s2 == a[i]) { Console.WriteLine(b[i]); break; }
    }
}