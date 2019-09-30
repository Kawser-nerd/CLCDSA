using System.Linq;
using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        var p = new List<string>();
        var a = new char[] { 'a', 'b', 'c' };
        var n = int.Parse(Console.ReadLine().Trim());
        foreach (var x in a)
            getPW( x.ToString(), n, p, a);
        foreach (var y in p.OrderBy(x => x))
            Console.WriteLine(y);
    }
    public static void getPW(string s, int n, List<string> p , char[] a)
    {
        if (s.Length == n) { p.Add(s);  return; }
        foreach (var x in a)
            getPW(s + x, n, p, a);
    }
}