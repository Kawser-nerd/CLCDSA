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
    static void Add(ref int a, int b) { if ((a += b) >= Mod) a -= Mod; }

    public void Solve()
    {
        int N = Reader.Int();
        int X = Reader.Int(), Y = Reader.Int(), Z = Reader.Int();
        int S = X + Y + Z;
        var badMask = new bool[1 << S];
        for (int mask = 0; mask < badMask.Length; mask++)
        {
            if ((mask >> Z - 1 & 1) == 0) continue;
            if ((mask >> Y + Z - 1 & 1) == 0) continue;
            if ((mask >> S - 1 & 1) == 1) badMask[mask] = true;
        }
        var dp = new int[1 << S];
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            var nextdp = new int[dp.Length];
            for (int mask = 0; mask < dp.Length; mask++)
                if (dp[mask] > 0)
                    for (int num = 1; num <= 10; num++)
                    {
                        int nextMask = (mask << num) + (1 << num - 1);
                        nextMask &= (1 << S) - 1;
                        if (!badMask[nextMask]) Add(ref nextdp[nextMask], dp[mask]);
                    }
            dp = nextdp;
        }
        long ans = 1;
        for (int i = 0; i < N; i++) ans = ans * 10 % Mod;
        for (int i = 0; i < dp.Length; i++) ans -= dp[i];
        ans = (ans % Mod + Mod) % Mod;

        Console.WriteLine(ans);
        Console.ReadLine();
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
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
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