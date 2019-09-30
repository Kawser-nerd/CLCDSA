using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly double INF = 1e100;

    public void Solve()
    {
        int SX = Reader.Int(), SY = Reader.Int();
        int GX = Reader.Int(), GY = Reader.Int();
        int N = Reader.Int();
        var Circles = new int[N + 2][];
        Circles[0] = new[] { SX, SY, 0 };
        for (int i = 1; i <= N; i++) Circles[i] = Reader.IntLine();
        Circles[N + 1] = new[] { GX, GY, 0 };
        N = N + 2;
        var dp = new double[N];
        for (int i = 1; i < N; i++) dp[i] = INF;
        var que = new Queue<int>();
        que.Enqueue(0);
        var inQue = new bool[N];
        var len = new double[N,N];

        for (int a = 0; a < N; a++) 
            for (int b = 0; b < N; b++) 
                len[a,b] = Len(Circles[a][0],Circles[a][1], Circles[a][2],
                               Circles[b][0],Circles[b][1], Circles[b][2]);
        while (que.Count > 0)
        {
            int a = que.Dequeue();
            inQue[a] = false;
            for (int b = 0; b < N; b++)
            {
                double cost = dp[a] + len[a, b];
                if (CheckMin(ref dp[b], cost) && !inQue[b])
                {
                    inQue[b] = true;
                    que.Enqueue(b);
                }
            }
        }

        Console.WriteLine(dp[N - 1]);
    }

    bool CheckMin(ref double a, double b) { if (b < a) { a = b; return true; } return false; }
    double Len(long x1, long y1, long r1, long x2, long y2, long r2)
    {
        return Math.Max(0, Dist(x1, y1, x2, y2) - r1 - r2);
    }
    double Dist(long x1, long y1, long x2, long y2)
    {
        return Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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