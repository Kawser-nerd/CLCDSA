using System;

public class Hello
{
    public static void Main()
    {
        var a = new string[] { "Left", "Right", "AtCoder" };
        var b = new string[] { "<", ">", "A" };
        var s = Console.ReadLine().Trim();
        for (int i = 0; i < 3; i++)
            s = s.Replace(a[i], b[i]);
        Console.WriteLine(s);
    }
}