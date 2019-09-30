using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var d = new Dictionary<int, string> { { 0, "Do" }, { 10, "Re" }, { 8, "Mi" }, { 7, "Fa" }, { 5, "So" }, { 3, "La" }, { 1, "Si" } };
        var t = Console.ReadLine().Trim();
        var s = t.Substring(0, 12) + t.Substring(0, 12);
        var a = s.IndexOf("WBWBWWBWBWBW");
        Console.WriteLine(d[a]);
    }
}