using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var map = new long[n, 3];
        for (int i = 0; i < n; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < 3; j++)
                map[i, j] = long.Parse(line[j]);
        }
        Console.WriteLine(getAns(map, m));
    }
    public static long getAns(long[,] map, int m)
    {
        var n = map.GetLength(0);
        var ret = Int64.MinValue;
        for (int i = 0; i < 8; i++)
        {
            var te = new long[n];
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                    if (((i >> k) & 1) == 1) te[j] += map[j, k];
                    else te[j] -= map[j, k];
            var te2 = te.OrderByDescending(x => x).Take(m).Sum();
            ret = Math.Max(ret, te2);
        }
        return ret;
    }
}