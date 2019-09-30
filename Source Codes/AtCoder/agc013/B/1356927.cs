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
        int N = Reader.Int(), M = Reader.Int();
        var E = EdgeRead(N, M);
        var seen = new bool[N];

        Func<int, List<int>> Gen = (start) =>
        {
            var res = new List<int>();
            for (int a = start; a != -1 && !seen[a]; )
            {
                seen[a] = true;
                res.Add(a + 1);
                a = Array.Find(E[a], i => !seen[i]);
            }
            return res;
        };
        seen[0] = true;
        var R = Gen(E[0][0]);
        seen[0] = false;
        var L = Gen(0);
        var ans = L.Reverse<int>().Concat(R);

        Console.WriteLine(ans.Count() + "\n" + string.Join(" ", ans));
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