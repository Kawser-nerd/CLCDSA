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
    public void Solve()
    {
        int N = Reader.Int(), M = Reader.Int(), S = Reader.Int() - 1;
        var E = Enu.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < M; i++)
        {
            int a = Reader.Int() - 1, b = Reader.Int() - 1;
            E[a].Add(b);
            E[b].Add(a);
        }
        var maxMinV = Enu.Repeat(-1, N).ToArray();
        maxMinV[S] = S;
        var que = new Queue<int>();
        var inQue = new bool[N];
        que.Enqueue(S);

        while (que.Count > 0)
        {
            int at = que.Dequeue();
            inQue[at] = false;
            foreach (int next in E[at])
            {
                int nextVal = Math.Min(next, maxMinV[at]);
                if (nextVal > maxMinV[next])
                {
                    maxMinV[next] = nextVal;
                    if (!inQue[next]) { inQue[next] = true; que.Enqueue(next); }
                }
            }
        }

        Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        for (int i = 0; i < N; i++)
            if (maxMinV[i] >= i)
                Console.WriteLine(i + 1);
        Console.Out.Flush();
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