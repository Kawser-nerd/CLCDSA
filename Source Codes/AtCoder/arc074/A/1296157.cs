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
        int H = Reader.Int(), W = Reader.Int();
        var ans = Math.Min(Calc(H, W), Calc(W, H));
        Console.WriteLine(ans);
    }

    private long Calc(long H, long W)
    {
        long res = long.MaxValue;
        for (int aw = 1; aw <= W / 2; aw++)
        {
            long bw = W - aw;
            long areaA = aw * H, areaB = bw * H;
            CheckMin(ref res, Calc2(areaA, bw, H));
            CheckMin(ref res, Calc2(areaA, H, bw));
            CheckMin(ref res, Calc2(areaB, aw, H));
            CheckMin(ref res, Calc2(areaB, H, aw));
        }
        return res;
    }

    private long Calc2(long areaA, long W, long H)
    {
        if (W < 2) return long.MaxValue;
        long areaB = W / 2 * H;
        long areaC = (W - W / 2) * H;
        var area = new[] { areaA, areaB, areaC };
        Array.Sort(area);
        return area[2] - area[0];
    }

    bool CheckMin(ref long a, long b) { if (b < a) { a = b; return true; } return false; }
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