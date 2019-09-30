using System;

public class Hello
{
    public static void Main()
    {
        var a = new char[] { 'a', 'b', 'c' };
        var n = int.Parse(Console.ReadLine().Trim());
        getPW("", n, a);
    }
    public static void getPW(string s, int n, char[] a)
    {
        if (s.Length == n) { Console.WriteLine(s); return; }
        foreach (var x in a)
            getPW(s + x, n, a);
    }
}