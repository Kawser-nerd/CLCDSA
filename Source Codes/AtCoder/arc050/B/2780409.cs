using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var r = long.Parse(line[0]);
        var b = long.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var x = long.Parse(line[0]);
        var y = long.Parse(line[1]);
        var mmax = (r + b) / Math.Min(x, y);
        var ret = getAns(r, b, x, y, mmax);
        Console.WriteLine(ret);
    }
    public static long getAns(long r, long b, long x, long y, long mmax)
    {
        var right = mmax;
        var left = 0L;
        while (right - left > 1)
        {
            var mid = left + (right - left) / 2;
            if (!check(r, b, x, y, mid)) right = mid;
            else left = mid;
        }
        return left;
    }
    public static bool check(long r, long b, long x, long y, long k)
    {
        var a1 = r - k;
        var a2 = b - k;
        if (a1 < 0 | a2 < 0) return false;
        return a1 / (x - 1) + a2 / (y - 1) >= k;
    }
}