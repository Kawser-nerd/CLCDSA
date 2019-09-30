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
    static readonly int MaxH = 2000;

    public void Solve()
    {
        int N = Reader.Int(), Q = Reader.Int();
        var C = Reader.IntTable(N);
        var qs = Reader.IntTable(Q);
        double[] Sfrom = new double[MaxH + 1];

        foreach (var c in C)
        {
            int sy = c[0];
            double R = c[1], H = c[2];
            for (int i = 0; i < H; i++)
            {
                double r1 = R * (H - i) / H;
                double r2 = R * (H - i - 1) / H;
                double v = (r1 * r1 + r1 * r2 + r2 * r2) * Math.PI / 3;
                Sfrom[sy + i] += v;
            }
        }
        for (int i = Sfrom.Length - 2; i >= 0; i--)
            Sfrom[i] += Sfrom[i + 1];
        var ans = new double[Q];
        for (int i = 0; i < Q; i++)
            ans[i] = Sfrom[qs[i][0]] - Sfrom[qs[i][1]];

        Console.WriteLine(string.Join("\n", ans));
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