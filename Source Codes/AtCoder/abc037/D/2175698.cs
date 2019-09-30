using System;

public class Hello
{
    public const long MOD = 1000000007;
    public static void Main()
    {
        var dx = new int[] { 0, 1, 0, -1 };
        var dy = new int[] { 1, 0, -1, 0 };
        string[] line = Console.ReadLine().Trim().Split(' ');
        var h = int.Parse(line[0]);
        var w = int.Parse(line[1]);
        var map = new int[h, w];
        for (int i = 0; i < h; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < w; j++) map[i, j] = int.Parse(line[j]);
        }
        var dp = new long[h, w];
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) dp[i, j] = -1;
        var ret = 0L;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                var ww = goDP(map, dp, i, j, dx, dy);
                ww %= MOD;
                ret += ww;
                ret %= MOD;
            }
        Console.WriteLine(ret);
    }
    public static long goDP(int[,] map, long[,] dp, int x, int y, int[] dx, int[] dy)
    {
        if (dp[x, y] != -1) return dp[x, y];
        var h = map.GetLength(0);
        var w = map.GetLength(1);
        var ret = 0L;
        var find = false;
        for (int i = 0; i < 4; i++)
        {
            var nx = x + dx[i];
            var ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[x, y] < map[nx, ny]) { ret += goDP(map, dp, nx, ny, dx, dy) % MOD ; find = true; }
        }
        if (find) return dp[x, y] = ret + 1;
        else return dp[x, y] = 1;


    }
}