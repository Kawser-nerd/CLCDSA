using System.Collections.Generic;
using System;

public class P
{
    public int x { get; set; }
    public int y { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var ps = new List<P>();
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var k = int.Parse(line[2]);
        var hh = new int[h];
        var ww = new int[w];
        var n = int.Parse(Console.ReadLine().Trim());
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var r = int.Parse(line[0]) - 1;
            var c = int.Parse(line[1]) - 1;
            hh[r]++;
            ww[c]++;
            ps.Add(new P { x = r, y = c });
        }
        var hhh = new long[h + 1];
        var www = new long[w + 1];
        for (int i = 0; i < w; i++) hhh[ww[i]]++;
        for (int i = 0; i < h; i++) www[hh[i]]++;
        var ak = 0L;
        for (int i = 0; i < h+1; i++)
            if (k-i >=0 && k-i < w+1) ak += hhh[i] * www[k-i];
        foreach (var x in ps)
            if (hh[x.x] + ww[x.y] == k) ak--;
            else if (hh[x.x] + ww[x.y] == k + 1) ak++;
        Console.WriteLine(ak);
    }
}