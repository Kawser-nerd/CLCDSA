using System;

public class P
{
    public int x { get; set; }
    public int y { get; set; }
}

public class Hello
{
    static int[] dx = new int[] { 0, 1, 0, -1 };
    static int[] dy = new int[] { 1, 0, -1, 0 };

    public static void Main()
    {
        var map = new int[10, 10];
        for (int i = 0; i < 10; i++)
        {
            var s = Console.ReadLine().Trim();
            for (int j = 0; j < 10; j++)
                if (s[j] == 'x') map[i, j] = -1;
        }
        var id = 1;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (map[i, j] == 0) putNum(map, new P { x = i, y = j }, id++);
        if (id >= 6) { Console.WriteLine("NO"); goto end; }
        if (id <= 2) { Console.WriteLine("YES"); goto end; }
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (map[i, j] == -1 && getAns(map, new P { x = i, y = j }, id - 1)) { Console.WriteLine("YES"); goto end; }
        Console.WriteLine("NO");
        end:;
    }
    public static bool getAns (int[,] map,P p , int id)
    {
        var chk = new bool[id];
        for (int i = 0; i < 4; i++)
        {
            var nx = p.x + dx[i];
            var ny = p.y + dy[i];
            if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && map[nx, ny] != -1)
                chk[map[nx, ny] - 1] = true;
        }
        for (int i = 0; i < chk.Length; i++)
            if (!chk[i]) return false;
        return true;
    }
    public static void putNum (int[,] map,  P p , int id )
    {
        map[p.x, p.y] = id;
        for (int i = 0; i < 4; i++)
        {
            var nx = p.x + dx[i];
            var ny = p.y + dy[i];
            if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && map[nx, ny] == 0)
                putNum(map, new P { x = nx, y = ny }, id);
        }
    }
}