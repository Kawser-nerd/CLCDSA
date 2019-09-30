using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int H = Reader.Int(), W = Reader.Int(), K = Reader.Int();
        var grid = Reader.StringArray(H);
        int S = Enu.Range(0, H * W).First(i => grid[i / W][i % W] == 'S');
        var dist = GridBFS(grid, S / W, S % W);
        int ans = INF;

        for (int r = 0; r < H; r++)
            for (int c = 0; c < W; c++)
                if (dist[r][c] < INF)
                {
                    int steps = Math.Max(1, (dist[r][c] + K - 1) / K);
                    int endDist = Math.Min(Math.Min(r, H - 1 - r), Math.Min(c, W - 1 - c));
                    steps += (endDist + K - 1) / K;
                    ans = Math.Min(ans, steps);
                }

        Console.WriteLine(ans);
    }

    static readonly int INF = (int)1e9;
    static readonly int[] DR = { 0, 1, 0, -1 };
    static readonly int[] DC = { 1, 0, -1, 0 };

    static int[][] GridBFS(string[] grid, int sr, int sc, char badCell = '#')
    {
        int H = grid.Length, W = grid[0].Length;
        var dist = new int[H][];
        for (int r = 0; r < H; r++) dist[r] = Enu.Repeat(INF, W).ToArray();
        dist[sr][sc] = 0;
        var que = new Queue<int>();
        que.Enqueue(sr); que.Enqueue(sc);
        Func<int, int, bool> IsInside = (r, c) => r >= 0 && r < H && c >= 0 && c < W;

        while (que.Count > 0)
        {
            int r = que.Dequeue(), c = que.Dequeue();
            for (int d = 0; d < DR.Length; d++)
            {
                int nr = r + DR[d], nc = c + DC[d];
                if (IsInside(nr, nc) && grid[nr][nc] != badCell && dist[nr][nc] == INF)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    que.Enqueue(nr); que.Enqueue(nc);
                }
            }
        }

        return dist;
    }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string[] Split(string s) { return s.Split(separator, op); }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}