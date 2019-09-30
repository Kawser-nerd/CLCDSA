using System.Linq;
using System;

public class SW
{
    public double w { get; set; }
    public double p { get; set; }
    public double salt { get; set; }
}

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var k = int.Parse(line[1]);
        var sws = new SW[n];
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var w = double.Parse(line[0]);
            var p = double.Parse(line[1]);
            sws[i] = new SW { w = w, p = p };
        }
        var ret = goBS(sws, k);
        Console.WriteLine(ret);
    }
    public static double goBS(SW[] sws, int k)
    {
        var ok = 0d;
        var ng = 100d;
        for (int i = 0; i < 100; i++)
        {
            var mid = (ok + ng) / 2d;
            if (canMake(sws, k, mid)) ok = mid;
            else ng = mid;
        }
        return ok;
    }
    public static bool canMake(SW[] sws, int k, double t)
    {
        var n = sws.Length;
        for (int i = 0; i < n; i++)
            sws[i].salt = (sws[i].p - t) * sws[i].w / 100d;
        var ret = sws.OrderByDescending(x => x.salt).Take(k).Sum(x => x.salt);
        return ret >= 0d;
    }
}