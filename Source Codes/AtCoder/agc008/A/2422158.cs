using System.Linq;
using System;

public class Hello
{
    public const long INF = 99999999999;
    public static void Main()
    {
        var ret = new long[4];
        string[] line = Console.ReadLine().Trim().Split(' ');
        var x = long.Parse(line[0]);
        var y = long.Parse(line[1]);
        ret[0] = getAns(x, y);
        ret[1] = getAns(x, -y) + 1;
        ret[2] = getAns(-x, y) + 1;
        ret[3] = getAns(-x, -y) + 2;
        Console.WriteLine(ret.Min());
    }
    public static long getAns(long a, long b)
    {
        return a <= b ? b - a : INF;
    }
}