using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = double.Parse(line[0]);
        var m = double.Parse(line[1]);
        if (n > 13) n -= 12;
        var tn = 30 * n + m / 2;
        var tm = 6 * m;
        var res = Math.Abs(tn - tm);
        if (res > 180) res = 360 - res;
        Console.WriteLine(res);
    }
}