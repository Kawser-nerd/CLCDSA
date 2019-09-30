using System.Linq;
using System.Collections.Generic;
using System;

public class P
{
    public int[] a { get; set; }
}

public class Hello
{
    public static void Main()
    {
        var ps = new List<P>();
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var map = new int[h, w];
        for (int i = 0; i < h; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < w; j++) map[i, j] = int.Parse(line[j]);
        }
        print1(map, h, w, ps);
        print2(map, h, w, ps);
        var pc = ps.Count();
        Console.WriteLine(pc);
        if (pc > 0)
            foreach (var x in ps)
                Console.WriteLine(string.Join(" ", x.a));
    }
    public static void print2(int[,] map, int h, int w, List<P> ps)
    {
        for (int i = 0; i < w - 1; i++)
            if (map[h - 1, i] % 2 == 1)
            {
                var pp = new P();
                pp.a = new int[] { h, i + 1, h, i + 2 };
                ps.Add(pp);
                map[h - 1, i + 1]++;
            }
    }
    public static void print1(int[,] map, int h, int w, List<P> ps)
    {
        for (int i = 0; i < h - 1; i++)
            for (int j = 0; j < w; j++)
                if (map[i, j] % 2 == 1)
                {
                    var pp = new P();
                    pp.a = new int[] { i + 1, j + 1, i + 2, j + 1 };
                    ps.Add(pp);
                    map[i + 1, j]++;
                }
    }
}