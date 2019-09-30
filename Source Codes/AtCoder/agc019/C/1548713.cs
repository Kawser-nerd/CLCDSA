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
        int X1 = Reader.Int(), Y1 = Reader.Int(), X2 = Reader.Int(), Y2 = Reader.Int();
        int N = Reader.Int();
        int[] X = new int[N], Y = new int[N];
        int num = 0;

        for (int i = 0; i < N; i++)
        {
            int x = Reader.Int(), y = Reader.Int();
            if (x < Math.Min(X1, X2) || x > Math.Max(X1, X2)) continue;
            if (y < Math.Min(Y1, Y2) || y > Math.Max(Y1, Y2)) continue;
            X[num] = X1 <= X2 ? x : -x;
            Y[num] = Y1 <= Y2 ? y : -y;
            num++;
        }
        Array.Resize(ref X, num); Array.Resize(ref Y, num);
        Array.Sort(X, Y);
        var DP = Enu.Repeat(int.MaxValue, num + 1).ToArray();
        foreach (int y in Y) DP[LowerBound(DP, y)] = y;
        int circles = LowerBound(DP, int.MaxValue);
        double ans = (Math.Abs(X1 - X2) + Math.Abs(Y1 - Y2)) * 100L - circles * (20 - 5 * Math.PI);
        if (circles == Math.Min(Math.Abs(X1 - X2), Math.Abs(Y1 - Y2)) + 1)
            ans += 5 * Math.PI;

        Console.WriteLine(ans);
    }

    static int LowerBound(int[] A, int val, int L = 0, int R = -1)
    {
        if (R == -1) R = A.Length;
        while (R - L >= 1)
        {
            int mid = (L + R) / 2;
            if (A[mid] >= val) R = mid;
            else L = mid + 1;
        }
        return R;
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
    static void Init() { Dispose(); A = new string[0]; }
    public static void Set(TextReader r) { Init(); reader = r; }
    public static void Set(string file) { Init(); reader = new StreamReader(file); }
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
    public static void Dispose() { reader.Dispose(); }
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