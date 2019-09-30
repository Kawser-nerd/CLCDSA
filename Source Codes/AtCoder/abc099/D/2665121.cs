using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var c = int.Parse(line[1]);
        var cmap = new int[c, c];
        for (int i = 0; i < c; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < c; j++)
                cmap[i, j] = int.Parse(line[j]);
        }
        var map = new int[3, c];
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < n; j++)
            {
                var w = int.Parse(line[j]) - 1;
                map[(i + j + 2) % 3, w]++;
            }
        }
        Console.WriteLine(getAns(cmap, map));
    }
    public static int getAns(int[,] cmap, int[,] map)
    {
        var c = cmap.GetLength(0);
        var ret = 999999999; int cost;
        for (int i = 0; i < c; i++)
            for (int j = 0; j < c; j++)
                for (int k = 0; k < c; k++)
                    if (i != j && j != k && k != i)
                    {
                        cost = 0;
                        for (int L = 0; L < c; L++)
                            cost += map[0, L] * cmap[L, i] + map[1, L] * cmap[L, j] + map[2, L] * cmap[L, k];
                        ret = Math.Min(ret, cost);
                    }
        return ret;
    }
}