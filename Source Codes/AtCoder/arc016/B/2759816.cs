using System;

public class Hello
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine().Trim());
        var map = new int[9,n];
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine().Trim();
            for (int j = 0; j < 9; j++)
                if (s[j] == 'x') map[j,i] = 1;
                else if (s[j] == 'o') map[j,i] = 2;
        }
        var ret = getAns(map);
        Console.WriteLine(ret);
    }
    public static int  getAns (int[,] map)
    {
        var n = map.GetLength(1);
        var count = 0;
        for (int i = 0; i < 9; i++)
        {
            var pre = map[i, 0];
            if (pre >= 1) count++;
            for (int j = 1; j < n; j++)
            {
                if (map[i, j] == 1) count++;
                else if (map[i, j] == 2 && pre != 2) count++;
                pre = map[i, j];
            }
        }
        return count;
    }
}