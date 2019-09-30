using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var w = s.ToCharArray();
        Array.Reverse(w);
        var rs = new string(w);
        Console.WriteLine(s == rs ? "YES":"NO");
    }
}