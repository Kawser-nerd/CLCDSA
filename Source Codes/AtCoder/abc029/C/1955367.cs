using System;

public class Hello
{
    public static void Main()
    {
        var a = new char[] { 'a', 'b', 'c' };
        var n = int.Parse(Console.ReadLine().Trim());
        getPW("", 0, n, a);
    }
    public static void getPW(string s, int i, int n, char[] a)
    {
        if (i == n) { Console.WriteLine(s); return; }
        foreach (var x in a)
            getPW(s + x, i + 1, n, a);
    }
}