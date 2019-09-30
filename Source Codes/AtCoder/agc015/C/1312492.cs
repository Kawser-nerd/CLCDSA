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
        int H = Reader.Int(), W = Reader.Int(), NQ = Reader.Int();
        var grid = Reader.StringArray(H);
        var Q = Reader.IntTable(NQ);
        var cell = new int[H + 1, W + 1];
        var up = new int[H + 1, W + 1];
        var left = new int[H + 1, W + 1];

        for (int r = 0; r < H; r++)
            for (int c = 0; c < W; c++)
                if (grid[r][c] == '1')
                {
                    cell[r, c] = 1;
                    if (r > 0 && grid[r - 1][c] == '1') up[r, c] = 1;
                    if (c > 0 && grid[r][c - 1] == '1') left[r, c] = 1;
                }
        var cellSum = new RectangleSum(cell);
        var upSum = new RectangleSum(up);
        var leftSum = new RectangleSum(left);
        var ans = new List<int>();
        foreach (var q in Q)
        {
            int r1 = q[0] - 1, c1 = q[1] - 1, r2 = q[2], c2 = q[3];
            int x = cellSum[r1, c1, r2, c2] - upSum[r1 + 1, c1, r2, c2] - leftSum[r1, c1 + 1, r2, c2];
            ans.Add(x);
        }

        Console.WriteLine(string.Join("\n", ans));
    }
}

class RectangleSum
{
    private readonly int[][] sum;
    public RectangleSum(int[,] grid)
    {
        int H = grid.GetLength(0), W = grid.GetLength(1);
        sum = new int[H + 1][];
        for (int r = 0; r < sum.Length; r++)
            sum[r] = new int[W + 1];
        for (int r = 0; r < H; r++)
            for (int c = 0; c < W; c++)
            {
                sum[r + 1][c + 1] = grid[r, c];
                sum[r + 1][c + 1] += sum[r][c + 1] + sum[r + 1][c] - sum[r][c];
            }
    }
    public int this[int r1, int c1, int r2, int c2]
    {
        get { return sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1]; }
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