using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    private static int[] dx = { 0, 1, 0, -1 };
    private static int[] dy = { 1, 0, -1, 0 };
    public static void Main()
    {
        int H = NextInt();
        int W = NextInt();
       // H = W = 50;
        char[,] map = new char[H, W];
        Node[,] node = new Node[H, W];
        int WhiteCount = 0;
        for (int i = 0; i < H; i++)
        {
            char[] line = NextString().ToCharArray();
            //line = Enumerable.Repeat('.',50).ToArray();
            for (int j = 0; j < W; j++)
            {
                if (line[j] == '.') WhiteCount++;
                map[i, j] = line[j];
                node[i, j] = new Node();
            }
        }
        Queue<int[]> pos = new Queue<int[]>();
        pos.Enqueue(new int[2] { 0, 0 });
        node[0, 0].count = 1;
        while (pos.Count() != 0)
        {
            var p = pos.Dequeue();
            if (node[p[0], p[1]].visit) continue;
            node[p[0], p[1]].visit = true;
            for (int i = 0; i < 4; i++)
            {
                int xx = p[1] + dx[i];
                int yy = p[0] + dy[i];
                if (yy < 0 || H <= yy || xx < 0 || W <= xx || node[yy, xx].visit || map[yy, xx] == '#') continue;
                node[yy, xx].count = node[p[0], p[1]].count + 1;
                pos.Enqueue(new int[2] { yy, xx });
            }
            if (p[0] == H - 1 && p[1] == W - 1) break;
        }
        if (node[H - 1, W - 1].visit) { Console.WriteLine(WhiteCount - node[H - 1, W - 1].count); }
        else Console.WriteLine(-1);
    }
}

public class Node
{
    public bool visit = false;
    public int count = 0;
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