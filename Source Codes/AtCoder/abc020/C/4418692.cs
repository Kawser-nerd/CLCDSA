using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private static int[] dx = new int[4] { 0, -1, 0, 1 };
    private static int[] dy = new int[4] { -1, 0, 1, 0 };
    public static void Main()
    {
        int H = NextInt();
        int W = NextInt();
        int T = NextInt();
        int start = 0, goal = 0;
        List<char>[] map = new List<char>[H];
        for (int i = 0; i < H; i++)
        {
            string s = NextString();
            map[i] = new List<char>();
            for (int j = 0; j < W; j++)
            {
                map[i].Add(s[j]);
                if (s[j] == 'S') start = i * W + j;
                else if (s[j] == 'G') goal = i * W + j;
            }
        }

        long ng = 0, ok = 1000000000;
        while (ok - ng != 1)
        {
            long x = (ng + ok) / 2;
            long ans = 0;
            //????WF
            long[,] cost = new long[W * H, W * H];
            for (int i = 0; i < H * W; i++) for (int j = 0; j < H * W; j++) cost[i, j] = (i == j ? 0 : INF);

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        int yy = i + dy[d], xx = j + dx[d];
                        if (yy >= H || yy < 0 || xx >= W || xx < 0) continue;
                        else if (map[yy][xx] == '.') { cost[i * W + j, yy * W + xx] = 1; }
                        else if (map[yy][xx] == '#') { cost[i * W + j, yy * W + xx] = x; }
                        else if (map[yy][xx] == 'G') { cost[i * W + j, yy * W + xx] = 1; }
                        else if (map[yy][xx] == 'S') { cost[i * W + j, yy * W + xx] = 1; }
                    }
                }
            }

            for (int i = 0; i < H * W; i++)
                for (int j = 0; j < H * W; j++)
                    for (int k = 0; k < H * W; k++)
                        cost[j, k] = Math.Min(cost[j, k], cost[j, i] + cost[i, k]);

            ans = cost[start, goal];
            if (ans <= T) ng = x;
            else ok = x;
        }
        Console.WriteLine(ng);
    }
}

public class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}