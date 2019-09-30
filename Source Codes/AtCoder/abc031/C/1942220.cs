using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        string[] line = Console.ReadLine().Trim().Split(' ');
        var w = Array.ConvertAll(line, int.Parse);
        var tmax = -999999999;
        for (int i = 0; i < n; i++)
        {
            var a = getAselect(w, i);
            tmax = Math.Max(tmax, a);
        }
        Console.WriteLine(tmax);
    }
    public static int getAselect(int[] w, int t)
    {
        var n = w.Length; var amax = -999999999;
        var tret = -1;
        for (int i = 0; i < t; i++)
        {
            var apoint = 0; var count = 0; var tpoint = 0;
            for (int j = i; j <= t; j++)
                if (count++ % 2 == 1) apoint += w[j];
                else tpoint += w[j];
            if (apoint > amax) { amax = apoint; tret = tpoint; }
        }
        for (int i = t + 1; i < n; i++)
        {
            var apoint = 0; var count = 0; var tpoint = 0;
            for (int j = t; j <= i; j++)
                if (count++ % 2 == 1) apoint += w[j];
                else tpoint += w[j];
            if (apoint > amax) { amax = apoint; tret = tpoint; }
        }
        return tret;
    }
}