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
    List<int>[] E;

    public void Solve()
    {
        int N = Reader.Int(), K = Reader.Int();
        E = Enu.Range(0, N).Select(i => new List<int>()).ToArray();

        for (int i = 0; i < N - 1; i++)
        {
            int a = Reader.Int() - 1, b = Reader.Int() - 1;
            E[a].Add(b);
            E[b].Add(a);
        }
        int ans = N;
        for (int start = 0; start < N; start++)
        {
            int bad = 0, best = 0;
            foreach (int next in E[start])
            {
                var count = new int[N];
                DFS(next, start, 1, count);
                for (int c = K / 2 + 1; c < N; c++)
                    bad += count[c];
                if (K % 2 == 1) best = Math.Max(best, count[(K + 1) / 2]);
            }
            ans = Math.Min(ans, bad - best);
        }

        Console.WriteLine(ans);
    }

    void DFS(int at, int prev, int depth, int[] count)
    {
        count[depth]++;
        foreach (int next in E[at])
            if (next != prev)
                DFS(next, at, depth + 1, count);
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
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()); return r; }
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