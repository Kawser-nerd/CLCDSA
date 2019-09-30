using System;

public class Hello
{
    public static void Main()
    {
        var y = int.Parse(Console.ReadLine().Trim());
        var m = int.Parse(Console.ReadLine().Trim());
        var d = int.Parse(Console.ReadLine().Trim());
        var d1 = getDays(2014, 5, 17);
        var d2 = getDays(y, m, d);
        Console.WriteLine(Math.Abs(d1 - d2));
    }
    public static int getDays(int y, int m, int d)
    {
        if (m == 1 | m == 2) return getDays(y - 1, m + 12, d);
        var res = 365 * y + y / 4 - y / 100 + y / 400 + (306 * (m + 1)) / 10 + d - 429;
        return res;
    }
}