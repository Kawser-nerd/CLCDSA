using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var map = new char[n, n];
        var map2 = new char[m, m];
        for (int i = 0; i < n; i++)
        {
            var s = Console.ReadLine().Trim();
            for (int j = 0; j < n; j++) map[i, j] = s[j];
        }
        for (int i = 0; i < m; i++)
        {
            var s = Console.ReadLine().Trim();
            for (int j = 0; j < m; j++) map2[i, j] = s[j];
        }
        Console.WriteLine(checkMap(map, map2) ? "Yes" : "No");
    }
    public static bool checkMap(char[,] map, char[,] map2)
    {
        var n = map.GetLength(0); var m = map2.GetLength(0);
        for (int i = 0; i <= n - m; i++)
            for (int j = 0; j <= n - m; j++)
                if (checkMap2(map, map2, i, j)) return true;
        return false;
    }
    public static bool checkMap2(char[,] map, char[,] map2, int x, int y)
    {
        var m = map2.GetLength(0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
            {
                var nx = x + i;
                var ny = y + j;
                if (map[nx, ny] != map2[i, j]) return false;
            }
        return true;
    }
}