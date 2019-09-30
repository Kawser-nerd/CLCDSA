using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, long.Parse);
        var b05 = Math.Min(a[0] * 2, a[1]);
        var b10 = Math.Min(b05 * 2, a[2]);
        var b20 = Math.Min(b10 * 2, a[3]);
        var n = int.Parse(Console.ReadLine().Trim());
        long res;
        if (n % 2 == 0) res = b20 * n / 2;
        else res = b20 * (n - 1) / 2 + b10;
        Console.WriteLine(res);
    }
}