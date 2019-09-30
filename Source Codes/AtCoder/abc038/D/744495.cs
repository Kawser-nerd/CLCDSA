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
    static readonly int INF = (int)1e9;

    public void Solve()
    {
        int N = Reader.Int();
        var table = Reader.IntTable(N);
        var dic = new Dictionary<int, List<int>>();
        foreach (var t in table)
        {
            if (!dic.ContainsKey(t[0])) dic[t[0]] = new List<int>();
            dic[t[0]].Add(t[1]);
        }
        var Hs = dic.Keys.OrderBy(h => h);
        var dp = new int[N + 1];
        for (int i = 0; i < N + 1; i++)
            dp[i] = INF;
        foreach (var h in Hs)
        {
            dic[h].Sort();
            dic[h].Reverse();
            foreach (int w in dic[h])
                dp[LowerBound(dp, w)] = w;
        }

        Console.WriteLine(LowerBound(dp, INF));
    }

    // [L, R)
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
    static T[] Range<T>(int N, Func<T> f) { return Enu.Range(0, N).Select(i => f()).ToArray(); }
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