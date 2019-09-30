using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        Array.Sort(a);
        Array.Reverse(a);
        var ret = 0L;
        for (int i = 0; i < n; i++)
            ret += a[2 * i + 1];
        Console.WriteLine(ret);
    }
}