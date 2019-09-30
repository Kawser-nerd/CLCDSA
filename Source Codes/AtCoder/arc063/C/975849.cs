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
    int N, K;
    int[][] G;
    int[] Val, MinVal, MaxVal;

    public void Solve()
    {
        N = Reader.Int();
        G = EdgeRead(N);
        K = Reader.Int();
        Val = new int[N];
        MinVal = Enu.Repeat(-INF, N).ToArray();
        MaxVal = Enu.Repeat(INF, N).ToArray();
        for (int i = 0; i < K; i++)
        {
            int at = Reader.Int() - 1;
            Val[at] = MinVal[at] = MaxVal[at] = Reader.Int();
        }
        if (!DFS(0, -1) || !GenAnswer(0, -1)) { Console.WriteLine("No"); return; }
        Console.WriteLine("Yes\n" + string.Join("\n", Val));
    }

    bool DFS(int v, int prev)
    {
        foreach (int child in G[v])
            if (child != prev)
            {
                if (!DFS(child, v)) return false;
                MinVal[v] = Math.Max(MinVal[v], MinVal[child] - 1);
                MaxVal[v] = Math.Min(MaxVal[v], MaxVal[child] + 1);
            }
        return MinVal[v] <= MaxVal[v];
    }

    bool GenAnswer(int v, int prev)
    {
        if (prev == -1) Val[v] = MinVal[v];
        else if (Val[prev] - 1 >= MinVal[v]) Val[v] = Val[prev] - 1;
        else if (Val[prev] + 1 <= MaxVal[v]) Val[v] = Val[prev] + 1;
        else return false;
        foreach (int child in G[v])
            if (child != prev)
                if (!GenAnswer(child, v)) return false;
        return true;
    }

    int[][] EdgeRead(int V, int E = -1, int origin = 1)
    {
        if (E == -1) E = V - 1;
        var es = new List<int>[V];
        for (int i = 0; i < V; i++) es[i] = new List<int>();
        for (int i = 0; i < E; i++)
        {
            int a = Reader.Int() - origin, b = Reader.Int() - origin;
            es[a].Add(b);
            es[b].Add(a);
        }
        return es.Select(a => a.ToArray()).ToArray();
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