using System;

public class Hello
{
    public static void Main()
    {
        var t = "ict";
        var s = Console.ReadLine().Trim();
        s = s.ToLower();
        var sL = s.Length;
        var p = 0;
        var mes = "YES";
        for (int i = 0; i < 3; i++)
        {
            if (p == sL) { mes = "NO"; break; }
            var w = s.IndexOf(t[i], p);
            if (w == -1) { mes = "NO"; break; }
            else p = w + 1;
        }
        Console.WriteLine(mes);
    }
}