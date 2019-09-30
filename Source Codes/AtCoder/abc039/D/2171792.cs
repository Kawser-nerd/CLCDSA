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
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var map = new char[h, w];
        var ps = new List<P>();
        for (int i = 0; i < h; i++)
        {
            var s = Console.ReadLine().Trim();
            for (int j = 0; j < w; j++)
            {
                map[i, j] = s[j];
                if (s[j] == '.') ps.Add(new P { x = i, y = j });
            }
        }
        var map2 = map.Clone() as char[,];
        BtoW(map2, ps);
        var map3 = map2.Clone() as char[,];
        WtoB(map2);
        if (compareA(map, map2)) { Console.WriteLine("possible");  displayMap(map3); }
        else Console.WriteLine("impossible");
    }
    public static void displayMap (char[,] a)
    {
        var h = a.GetLength(0);
        var w = a.GetLength(1);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (j == w - 1) Console.WriteLine(a[i, j]);
                else Console.Write(a[i, j]);
    }
    public static bool compareA ( char[,] a , char[,] b)
    {
        var h = a.GetLength(0);
        var w = a.GetLength(1);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (a[i, j] != b[i, j]) return false;
        return true;
    }
    public static void BtoW(char[,] map, List<P> ps)
    {
        var h = map.GetLength(0);
        var w = map.GetLength(1);
        var dx = new int[] { 0, 1, 1, 1, 0, -1, -1, -1 };
        var dy = new int[] { 1, 1, 0, -1, -1, -1, 0, 1 };
        foreach (var x in ps)
        {
            for (int i = 0; i < 8; i++)
            {
                var nx = x.x + dx[i];
                var ny = x.y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) map[nx, ny] = '.';
            }
        }
    }
    public static void WtoB(char[,] map)
    {
        var h = map.GetLength(0);
        var w = map.GetLength(1);
        var dx = new int[] { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
        var dy = new int[] { 0, 1, 1, 0, -1, -1, -1, 0, 1 };
        var ps = new List<P>();
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                for (int k = 0; k < 9; k++)
                {
                    var nx = i + dx[k];
                    var ny = j + dy[k];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx, ny] == '#')
                    { ps.Add(new P { x = i, y = j }); break; }
                }
            }
        foreach (var x in ps) map[x.x, x.y] = '#';
    }
}