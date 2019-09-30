using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        var p = 0;
        var ret = "";
        for (int i = 0; i < s.Length; i++)
        {
            if ( p < 4  &&   a[p] == i) { ret += "\""; p++; }
            ret += s[i];
        }
        if (p == 3) ret += "\"";
        Console.WriteLine(ret);
    }
}