using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        int a;
        for (int i = 0; i < s.Length; i++)
            if (int.TryParse(s[i].ToString(), out a)) Console.Write(a);
        Console.WriteLine();
    }
}