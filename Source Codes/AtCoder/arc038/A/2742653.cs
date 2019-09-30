using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, int.Parse);
        Array.Sort(a);  Array.Reverse(a);
        var res = 0;
        for (int i = 0; i < n; i += 2) res += a[i];
        Console.WriteLine(res);
    }
}