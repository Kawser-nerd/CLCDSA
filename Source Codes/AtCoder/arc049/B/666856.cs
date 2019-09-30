using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

class Program
{
    public void Solve()
    {
        int N = Reader.Int();
        var table = Reader.IntTable(N);
        double x = BinarySearch(table.Select(t => t[0]).ToArray(), table.Select(t => t[2]).ToArray());
        double y = BinarySearch(table.Select(t => t[1]).ToArray(), table.Select(t => t[2]).ToArray());
        Console.WriteLine(Math.Max(x, y));
    }

    private double BinarySearch(int[] X, int[] C)
    {
        int N = X.Length;
        Array.Sort(X, C);
        double L = X[0], R = X[N - 1];
        double ans = 0;

        for (int repeat = 0; repeat < 300; repeat++)
        {
            double mid1 = L + (R - L) / 3;
            double mid2 = L + (R - L) / 3 * 2;
            ans = Calc(mid1, X, C);
            if (ans < Calc(mid2, X, C)) R = mid2;
            else L = mid1;
        }

        return ans;
    }

    private double Calc(double target, int[] X, int[] C)
    {
        double max = 0;
        for (int i = 0; i < X.Length; i++)
            max = Math.Max(max, Math.Abs(X[i] - target) * C[i]);
        return max;
    }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    private static TextReader reader = Console.In;
    private static readonly char[] separator = { ' ' };
    private static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    private static string[] A = new string[0];
    private static int i;
    private static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Enu.Range(0, N).Select(i => Int()).ToArray(); }
    public static int[][] IntTable(int H) { return Enu.Range(0, H).Select(i => IntLine()).ToArray(); }
    public static string[] StringArray(int N) { return Enu.Range(0, N).Select(i => Next()).ToArray(); }
    public static string Line() { return reader.ReadLine().Trim(); }
    private static string[] Split(string s) { return s.Split(separator, op); }
    private static string Next() { CheckNext(); return A[i++]; }
    private static bool CheckNext()
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