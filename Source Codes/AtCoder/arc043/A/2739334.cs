using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var a = int.Parse(line[1]);
        var b = int.Parse(line[2]);
        var pmax = long.MinValue;
        var pmin = long.MaxValue;
        var psum = 0L;
        for (int i = 0; i < n; i++)
        {
            var w = long.Parse(Console.ReadLine().Trim());
            pmax = Math.Max(pmax, w);
            pmin = Math.Min(pmin, w);
            psum += w;
        }
        if (pmax == pmin) { Console.WriteLine(-1); goto end; }
        var p = (double)b / (pmax - pmin);
        var q = a - p * (double)psum /n;
        Console.WriteLine("{0} {1}", p, q);
        end:;
    }
}