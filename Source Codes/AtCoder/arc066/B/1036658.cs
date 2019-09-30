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
    static readonly int Mod = (int)1e9 + 7;
    Dictionary<long, Dictionary<long, long>> dic;

    public void Solve()
    {
        long N = Reader.Long();
        dic = new Dictionary<long, Dictionary<long, long>>();
        Console.WriteLine(F(N, N));
    }

    private long F(long S, long X)
    {
        if (S == 0) return 1;
        if (dic.ContainsKey(S) && dic[S].ContainsKey(X)) return dic[S][X];
        long res = 0;
        res += F(S / 2, X / 2);
        res += F((S - 1) / 2, (X - 1) / 2);
        if (S >= 2) res += F((S - 2) / 2, X / 2);
        res %= Mod;
        Add(S, X, res);
        return res;
    }

    void Add(long S, long X, long val)
    {
        if (!dic.ContainsKey(S)) dic[S] = new Dictionary<long, long>();
        dic[S][X] = val;
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